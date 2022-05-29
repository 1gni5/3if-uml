//---------- Interface de la classe <Sensor> -----------------------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>

using std::string;

#include "Measurement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	string getId();
	double getLongitude();
	double getLatitude();

	void addMeasurement(const Measurement& m);
	std::list<Measurement>& getMeasurements();

//-------------------------------------------- Constructeurs - destructeur
	Sensor();
    Sensor(std::list<string> fields);
    virtual ~Sensor();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string id;
	double latitude;
	double longitude;

	std::list<Measurement> measurements;
};

//----------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H
