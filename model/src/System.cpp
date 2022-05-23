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
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

System::System()
{
    deserialize<Attribute>("datasets/attributes.csv", attributes, 0, true);
    deserialize<Sensor>("datasets/sensor.csv", sensors, 0);
    deserialize<Measurement>("datasets/measurements.csv", measurements, 1);
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
            make_pair(latitude, longitude));
        nearestSensors.push_back(make_pair(s.second, dist));
    }

    sort(nearestSensors.begin(), nearestSensors.end(), wayToSort);

    cout << "je suis ici !!! " << endl;
    for (auto &s : nearestSensors)
    {
        cout << s.second << endl;
    }
}