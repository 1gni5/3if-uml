/*************************************************************************
                           Attribute  
                             -------------------
    début                : $02/05/2022$
    copyright            : (C) $2022$ par $CHAUDRON$
    e-mail               : $felicie.chaudron@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <attribute> (fichier TrajetSimple.h) ----------------
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
    Attribute (long attribute , string unit, string description);  
    
    virtual ~Attribute ( );

    string getUnit();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	long attributeID;
    string unit;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // ATTRIBUTE_H




