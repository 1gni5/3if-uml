//---------- Réalisation de la classe <Sensor> --------------------------

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

string Sensor::getId(void)
{
    return id;
}

long Sensor::getLongitude()
{ 
    return longitude; 
}

long Sensor::getLatitude()
{ 
    return latitude; 
}

std::vector<size_t>& Sensor::getMeasurements(void)
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
    id = fields.front();
    fields.pop_front();

    // Extract latitude and longitude
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
void Sensor::updateBackRefs(void)
{
    // Aucune référence à mettre à jour
}

string Sensor::getUnique(void)
{ 
    return id; 
}