//---------- Réalisation de la classe <sensor> --------------------------

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
{ return longitude; }

long Sensor::getLatitude()
{ return latitude; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
{
	#ifdef MAP
		cout << "Appel au constructeur de <Sensor>" << endl;
	#endif
} //---- Fin du constructeur Sensor

Sensor::Sensor (list<string> fields)
{
    // Extract latitude and longitude
    latitude = atol(fields.front().c_str());
    fields.pop_front();

    longitude = atol(fields.front().c_str());
    fields.pop_front();

    #ifdef MAP
        cout << "Appel au constructeur de <Sensor>" << endl;
    #endif
} //----- Fin du constructeur Sensor

Sensor::~Sensor ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Sensor>" << endl;
	#endif
} //----- Fin de ~Sensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
