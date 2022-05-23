//---------- Réalisation de la classe <System> --------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Deserialize.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
bool wayToSort(pair<Sensor, double> sensorA, pair<Sensor, double> sensorB)
{
    return (sensorA.second < sensorB.second);
}
//----------------------------------------------------- Méthodes publiques
pair<double, string> System::ComputeAirQuality(
    double latitude,
    double longitude,
    time_t timestamp)
{
    cout << " MDR RRRR !ù!" << endl;
    getNearestSensors(latitude, longitude, 5);

    return make_pair(0, "ok");
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

System::System()
{
    cout << "Building Attributes" << endl;
    deserialize<Attribute>("datasets/attributes.csv", attributes, 0, true);
    cout << "Building Sensors" << endl;
    deserialize<Sensor>("datasets/sensors.csv", sensors, 0);
    cout << "Building Measurements" << endl;
    deserialize<Measurement>("datasets/measurements.csv", measurements, 1);
    //cout << "Building Cleaners" << endl;  
    //deserialize<Cleaner>("datasets/cleaners.csv", cleaners, 0);
    //cout << "Building Providers" << endl; 
    //deserialize<Provider>("datasets/providers.csv", providers, 0);
    //cout << "Building Users" << endl;  
    //deserialize<User>("datasets/users.csv", users, 0);
#ifdef MAP
    cout << "Appel au constructeur de <System>" << endl;
#endif
} //---- Fin du constructeur System

System::~System()
{
#ifdef MAP
    cout << "Appel au destructeur de <System>" << endl;
#endif
} //----- Fin de ~System

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
vector<pair<Sensor, double>> System::getNearestSensors(
    double latitude,
    double longitude,
    size_t number)
{
    vector<pair<Sensor, double>> nearestSensors;

    for (auto &s : sensors)
    {
        double dist = computeDistance(
            make_pair(s.second.getLatitude(), s.second.getLongitude()),
            make_pair(latitude, longitude)
        );

        nearestSensors.push_back(make_pair(s.second, dist));
    }

    sort(nearestSensors.begin(), nearestSensors.end(), wayToSort);

    vector<pair<Sensor, double>> result(nearestSensors.begin(), nearestSensors.begin() + number);
    return result;
}