//---------- Réalisation de la classe <Attribute> ------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Attribute::getUnit()
{
    return unit;
}

string Attribute::getDescription()
{
    return description;
}

void Attribute::addMeasurement(const Measurement& m)
{
    measurements.push_back(m);
}

list<Measurement>& Attribute::getMeasurements()
{
    return measurements;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute()
{
    #ifdef MAP
        std::cout << "Appel au constructeur par défaut de <Attribute>" << std::endl;
    #endif
}//----- Fin de Attribute

Attribute::Attribute(list<string> fields)
{
    unit = fields.front();
    fields.pop_front();
    description = fields.front();
    fields.pop_front();

    #ifdef MAP
		std::cout << "Appel au constructeur de <Attribute>" << std::endl;
	#endif
}//----- Fin du constructeur Attribute

Attribute::~Attribute ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Attribute>" << std::endl;
	#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
