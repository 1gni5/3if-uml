//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	long getLongitude();
	long getLatitude();

//-------------------------------------------- Constructeurs - destructeur
	Sensor();
    Sensor(std::list<string> fields);
    virtual ~Sensor();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	long latitude;
	long longitude;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // SENSOR_H
