//---------- Interface de la classe <Measurement> ----------------------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	time_t getTimestamp();
	string getSensor();
	string getUnit();
	double getValue();

//-------------------------------------------- Constructeurs - destructeur
	Measurement();
    Measurement(std::list<string> fields);
    virtual ~Measurement();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	time_t timestamp;
	string sensor;
	string unit;
	double value;
};

//------------------------ Autres définitions dépendantes de <Measurement>

#endif // MEASUREMENT_H
