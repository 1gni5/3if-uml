//---------- Interface de la classe <measurement> ------------------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

using std::string;

#include "Attribute.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	time_t getTimestamp();
	double getValue();
	Attribute* getAttribute();
	Sensor* getSensor();

//-------------------------------------------- Constructeurs - destructeur
	Measurement();
    Measurement(std::list<string> fields);
    virtual ~Measurement();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

	void updateBackRefs(void);
	string getUnique(void);

//----------------------------------------------------- Attributs protégés

	time_t timestamp;
	double value;
	string idUnit;
	string idSensor;

	// Fonctionnement interne de Model<>
	size_t _id;
	Attribute *unit;
	Sensor *sensor;

	friend class Model<Measurement>;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // MEASUREMENT_H
