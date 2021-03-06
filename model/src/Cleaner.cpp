//---------- Réalisation de la classe <Cleaner> --------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>

using std::string;
using std::list;
using std::tm;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"
#include "Utilities.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

time_t Cleaner::getStart()
{ 
    return start; 
}

time_t Cleaner::getStop()
{ 
    return stop; 
}

long Cleaner::getLongitude()
{ 
    return longitude; 
}

long Cleaner::getLatitude()
{ 
    return latitude; 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Cleaner>" << std::endl;
	#endif
} //---- Fin du constructeur Cleaner

Cleaner::Cleaner (list<string> fields)
{
    // Extract latitude and longitude
    latitude = atol(fields.front().c_str());
    fields.pop_front();

    longitude = atol(fields.front().c_str());
    fields.pop_front();

    // Extract start and stop dates
    start = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

    stop = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

    #ifdef MAP
        std::cout << "Appel au constructeur de <Cleaner>" << std::endl;
    #endif
} //----- Fin du constructeur Cleaner

Cleaner::~Cleaner ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Cleaner>" << std::endl;
	#endif
} //----- Fin de ~Cleaner

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
