//---------- Interface de la classe <sensor> -----------------------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
#include <vector>

using std::string;

#include "Model.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Sensor
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques

	string getId(void);
	long getLongitude(void);
	long getLatitude(void);

	std::vector<size_t>& getMeasurements(void);

//-------------------------------------------- Constructeurs - destructeur
	Sensor(void);
	Sensor(std::list<string> fields);
	virtual ~Sensor(void);

//------------------------------------------------------------------ PRIVE
	private:

//----------------------------------------------------- Méthodes protégées

		void updateBackRefs(void);
		string getUnique(void);
		
//----------------------------------------------------- Attributs protégés
		string id;
		long latitude;
		long longitude;

		// Only for Model use
		size_t _id;
		std::vector<size_t> measurements;
		
		friend class Model<Sensor>;
		friend class Measurement;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // SENSOR_H
