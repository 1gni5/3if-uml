//---------- Interface de la classe <cleaner> ----------------------------
#if !defined(SYSTEM_H)
#define SYSTEM_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>

#include "Measurement.h"
#include "Sensor.h"
#include "Attribute.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class System
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	pair<double, string> ComputeAirQuality(
			double latitude,
			double longitude,
			time_t timestamp);

	//-------------------------------------------- Constructeurs - destructeur
	System();
	virtual ~System();

	//------------------------------------------------------------------ PRIVE

private:
	//----------------------------------------------------- Méthodes protégées
	vector<pair<Sensor, double>> getNearestSensors(
			double latitude,
			double longitude,
			size_t number);
	inline double computeDistance(pair<double, double> A, pair<double, double> B)
	{
		return (sqrt(pow((B.first - A.first), 2) + pow((B.second - A.second), 2)));
	}

	//----------------------------------------------------- Attributs protégés
	map<string, Attribute> attributes;
	map<string, Sensor> sensors;
	multimap<string, Measurement> measurements;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // SYSTEM_H
