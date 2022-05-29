//---------- Interface de la classe <System> -----------------------------
#if ! defined ( SYSTEM_H )
#define SYSTEM_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>

using std::string;
using std::map;
using std::multimap;

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
};

//----------------------- Autres définitions dépendantes de <System> -----

#endif // SYSTEM_H