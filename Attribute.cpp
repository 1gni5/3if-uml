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

Attribute::Attribute (long attribute , string monUnit, string maDescription)
{
	this->attributeID = attribute;
    this->unit = monUnit;
    this->description = maDescription;
	
	#ifdef MAP
		cout << "Appel au constructeur de <Attribute>" << endl;
	#endif
} //----- Fin du constructeur Attribute

Attribute::Attribute (string attr , string myUnit, string myDescription)
{
	this->attributeID = atol(attr);
    this->unit = myUnit;
    this->description = myDescription;
	
	#ifdef MAP
		cout << "Appel au constructeur de <Attribute>" << endl;
	#endif
} //----- Fin du constructeur Attribute


Attribute::~Attribute ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Attribute>" << endl;
	#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


