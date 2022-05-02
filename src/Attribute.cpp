//---------- Réalisation de la classe <Attribute> ------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::endl;

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

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Attribute::Attribute(list<string> fields)
{
    unit = fields.front();
    fields.pop_front();
    description = fields.front();
    fields.pop_front();

    #ifdef MAP
		cout << "Appel au constructeur de <Attribute>" << endl;
	#endif
}//----- Fin du constructeur Attribute

Attribute::~Attribute ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Attribute>" << endl;
	#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

std::ostream& operator<<(std::ostream& os, const Attribute& attribute)
{
    os << "{ " << attribute.unit << ", " << attribute.description << " }";
    return os;
}


