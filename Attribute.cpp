/*************************************************************************
                           Attribute  
                             -------------------
    début                : $02/05/2022$
    copyright            : (C) $2022$ par $CHAUDRON$
    e-mail               : $felicie.chaudron@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Attribute> ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <list>

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes
#define NMAP

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string Attribute::getUnit()
{
        return unit;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Attribute::Attribute (string monUnit, string maDescription)
{
    this->unit = monUnit;
    this->description = maDescription;
	
	#ifdef MAP
		cout << "Appel au constructeur de <Attribute>" << endl;
	#endif
} //----- Fin du constructeur Attribute

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

std::ostream& operator<<(std::ostream& out, const Attribute& attribute)
{
    out << "{ " << attribute.unit << ", " << attribute.description << " }";
    return out;
}


