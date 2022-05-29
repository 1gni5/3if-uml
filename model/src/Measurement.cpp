//---------- Réalisation de la classe <measurement> ----------------------

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
#include "Measurement.h"
#include "Utilities.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

time_t Measurement::getTimestamp()
{ 
    return timestamp; 
}

string Measurement::getSensor()
{ 
    return sensor; 
}

string Measurement::getUnit()
{ 
    return unit; 
}

double Measurement::getValue()
{ 
    return value; 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Measurement>" << std::endl;
	#endif
} //---- Fin du constructeur Measurement

Measurement::Measurement (list<string> fields)
{
    
    timestamp = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

    sensor = fields.front();
    fields.pop_front();

    unit = fields.front();
    fields.pop_front();

    value = atol(fields.front().c_str());
    fields.pop_front();

    #ifdef MAP
        std::cout << "Appel au constructeur de <Measurement>" << std::endl;
    #endif
} //----- Fin du constructeur Measurement

Measurement::~Measurement ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Measurement>" << std::endl;
	#endif
} //----- Fin de ~Measurement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
