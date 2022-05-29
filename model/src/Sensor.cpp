//---------- Réalisation de la classe <Sensor> ---------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>

using std::string;
using std::list;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

long Sensor::getLongitude()
{ 
    return longitude; 
}

long Sensor::getLatitude()
{ 
    return latitude; 
}

void Sensor::addMeasurement(const Measurement& m)
{
    measurements.push_back(m);
}

std::list<Measurement>& Sensor::getMeasurements()
{
    return measurements;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Sensor>" << std::endl;
	#endif
} //---- Fin du constructeur Sensor

Sensor::Sensor (list<string> fields)
{
    latitude = atol(fields.front().c_str());
    fields.pop_front();

    longitude = atol(fields.front().c_str());
    fields.pop_front();

    #ifdef MAP
        std::cout << "Appel au constructeur de <Sensor>" << std::endl;
    #endif
} //----- Fin du constructeur Sensor

Sensor::~Sensor ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Sensor>" << std::endl;
	#endif
} //----- Fin de ~Sensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
