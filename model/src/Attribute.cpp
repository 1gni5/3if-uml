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

string Attribute::getId(void)
{
    return id;
}

string Attribute::getUnit(void)
{
    return unit;
}

string Attribute::getDescription(void)
{
    return description;
}

string Attribute::getUnique(void)
{
    return id;
}

std::vector<size_t>& Attribute::getMeasurements(void)
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
    id = fields.front();
    fields.pop_front();

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
void Attribute::updateBackRefs(void)
{
    // Aucune référence à mettre à jour
}