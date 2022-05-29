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

string Cleaner::getId()
{
    return id;
}

time_t Cleaner::getStart()
{ 
    return start; 
}

time_t Cleaner::getStop()
{ 
    return stop; 
}

double Cleaner::getLongitude()
{ 
    return longitude; 
}

double Cleaner::getLatitude()
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
    id = fields.front();
    fields.pop_front();
    
    // Extract latitude and longitude
    latitude = atof(fields.front().c_str());
    fields.pop_front();

    longitude = atof(fields.front().c_str());
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
