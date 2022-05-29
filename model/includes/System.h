//---------- Interface de la classe <System> -----------------------------
#if ! defined ( SYSTEM_H )
#define SYSTEM_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>

using std::string;
using std::map;
using std::multimap;
using std::unordered_map;
using std::array;
using std::vector;

#include "Attribute.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "Provider.h"
#include "Sensor.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class System 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    std::list<Sensor> getNearestSensors(
        double latitude, 
        double longitude, 
        int nbSensors
    );

    unordered_map<string, double> computeAirQuality(
        double latitude, 
        double longitude,
        time_t timestamp,
        unsigned int nbSensors
    );

    unordered_map<string, double> computeAirQuality(
        Sensor sensor,
        time_t start,
        time_t end
    );

    std::list<Sensor> orderSensorsByATMO(
        Sensor referenceSensor,
        time_t start,
        time_t end
    );

    unsigned int computeATMOIndex(
        unordered_map<string, double> airQuality
    );

//-------------------------------------------- Constructeurs - destructeur
    System ();
    virtual ~System ();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string, Attribute> attributes;
    map<string, Cleaner> cleaners;
    multimap<string, Measurement> measurements;
    map<string, Provider> providers;
    map<string, Sensor> sensors;
    map<string, User> users;
    unordered_map<string, vector<int>> airQualityIndex;
};

//----------------------- Autres définitions dépendantes de <System> -----

#endif // SYSTEM_H