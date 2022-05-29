//---------- Réalisation de la classe <System> --------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::make_pair;

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Deserialize.h"
#include "Utilities.h"

//------------------------------------------------------------- Constantes
bool MyComparator(pair<Sensor, unsigned int> a, pair<Sensor, unsigned int> b) {
    if(a.second > b.second) {
        return true;
    } 
    return false;
}

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

std::list<Sensor> System::getNearestSensors(
    double latitude, 
    double longitude, 
    int nbSensors
){
    multimap<double, Sensor> nearestSensors;
    list<Sensor> results;

    for (auto& sensor : sensors)
    {
        nearestSensors.insert(
            make_pair(
                distance(
                    pair<double, double>(latitude, longitude),
                    pair<double, double>(sensor.second.getLatitude(), sensor.second.getLongitude())
                ),
                sensor.second
            )
        );
    }

    for (auto& sensor : nearestSensors)
    {
        results.push_back(sensor.second);
        if (results.size() >= nbSensors) { break; }
    }

    return results;
}

unordered_map<string, double> System::computeAirQuality(
    double latitude, 
    double longitude,
    time_t timestamp,
    unsigned int nbSensors
){
    unordered_map<string, double> results;
    list<Sensor> nearestSensors = getNearestSensors(latitude, longitude, nbSensors);

    // Calcul la somme des distance
    double sumDistance = 0;
    for (auto& sensor : nearestSensors)
    {
        sumDistance += distance(
            make_pair(latitude, longitude),
            make_pair(sensor.getLatitude(), sensor.getLongitude())
        );
    }
    
    // Calcul le poids des résultats de chaque capteurs
    list<pair<Sensor, double>> weightedSensors;
    for (auto& sensor : nearestSensors)
    {
        weightedSensors.push_back(
            make_pair(
                sensor,
                distance(
                    make_pair(latitude, longitude),
                    make_pair(sensor.getLatitude(), sensor.getLongitude())
                ) / sumDistance
            )
        );
    }

    // Initialise les résultats à 0
    for (auto& attribute : attributes)
    {
        results[attribute.first] = 0;
    }

    // Calcul le résultat final
    size_t noMeasurements = 0; 
    for (auto& sensor : weightedSensors)
    {
        for (auto& measurement : sensor.first.getMeasurements())
        {
            if (measurement.getTimestamp() == timestamp) 
            {
                noMeasurements++;
                results[measurement.getUnit()] += measurement.getValue() * sensor.second;
            }
        }
    }

    results.insert(
        make_pair("ATMO", computeATMOIndex(results))
    );
    return results;
}

unordered_map<string, double> System::computeAirQuality(
    Sensor sensor,
    time_t start,
    time_t end
){
    unordered_map<string, double> results;
    unordered_map<string, double> noMeasurements;

    // Initialise les résultats à 0
    for (auto& attribute : attributes)
    {
        results[attribute.first] = 0;
        noMeasurements[attribute.first] = 0;
    }

    for (auto& measurement : sensor.getMeasurements())
    {
        if (measurement.getTimestamp() >= start && measurement.getTimestamp() <= end)
        {
            results[measurement.getUnit()] += measurement.getValue();
            noMeasurements[measurement.getUnit()]++;
        }
    }

    // Divise par le nombre de mesures
    for (auto& attribute : attributes)
    {
        if (noMeasurements[attribute.first] != 0)
        {
            results[attribute.first] /= noMeasurements[attribute.first];
        }
    }

    // results.insert(
    //     make_pair("ATMO", computeATMOIndex(results))
    // );

    return results;
}

unsigned int System::computeATMOIndex(
    unordered_map<string, double> airQuality
){
    int indexMax = airQualityIndex[airQuality.begin()->first].size();
    int atmoMax = 0;
    for (auto& unit : airQuality)
    {
        int index = 0;
        int atmo = 1;

        while (index < indexMax && unit.second > airQualityIndex[unit.first][index])
        {
            index++;
            atmo++;
        }

        if (atmo > atmoMax) { atmoMax = atmo; }
    }
    
    return atmoMax;
}

std::list<Sensor> System::orderSensorsByATMO(
    Sensor referenceSensor,
    time_t start,
    time_t end
) {
    unsigned int referenceValue = computeATMOIndex(computeAirQuality(referenceSensor, start, end));

    multimap<unsigned int, Sensor> sortedSensors;
    for (auto& sensor : sensors)
    {
        if (sensor.first == referenceSensor.getId()) { continue; }
        // std::cout << "SENSOR " << sensor.second.getId() << " : " << computeATMOIndex(computeAirQuality(sensor.second, start, end)) << std::endl;

        int score = referenceValue - computeATMOIndex(computeAirQuality(sensor.second, start, end));
        score = abs(score);

        // std::cout << "SCORE : " << score << std::endl;

        sortedSensors.insert(make_pair(score, sensor.second));
    } 

    list<Sensor> results;
    for (auto& sensor : sortedSensors)
    {
        results.push_back(sensor.second);
    }

    return results;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
System::System()
{
    // Charge le fichier CSV en mémoire
    deserialize<Attribute>(
        "datasets/attributes.csv",
        attributes, 0, true
    );

    deserialize<Cleaner>(
        "datasets/cleaners.csv",
        cleaners, 0
    );

    deserialize<Measurement>(
        "datasets/measurements.csv",
        measurements, 0, true, false
    );

    deserialize<Provider>(
        "datasets/providers.csv",
        providers, 0
    );

    deserialize<Sensor>(
        "datasets/sensors.csv",
        sensors, 0
    );

    deserialize<User>(
        "datasets/users.csv",
        users, 0
    );
    
    // Création des relations entre les objets
    for (auto &measurement : measurements)
    {
        // Récupère le capteur et ajoute la mesure.
        string idSensor = measurement.second.getSensor();
        Sensor& sensor = sensors[idSensor];
        sensor.addMeasurement(measurement.second);

        // Récupère l'attribut et ajoute la mesure.
        string idAttribute = measurement.second.getUnit();
        Attribute& attribute = attributes[idAttribute];
        attribute.addMeasurement(measurement.second);
    }

    // Remplis le tableau d'index
    airQualityIndex.insert(pair<string, vector<int>>("PM10", {20, 40, 50, 100, 150}));
    airQualityIndex.insert(pair<string, vector<int>>("NO2", {40, 90, 120, 230, 340}));
    airQualityIndex.insert(pair<string, vector<int>>("O3", {50, 100, 130, 240, 380}));
    airQualityIndex.insert(pair<string, vector<int>>("SO2", {100, 200, 350, 500, 750}));

    #ifdef MAP
        std::cout << "Appel au constructeur par défaut de <System>" << std::endl;
    #endif
}//----- Fin de System

System::~System ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <System>" << std::endl;
	#endif
} //----- Fin de ~System


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
