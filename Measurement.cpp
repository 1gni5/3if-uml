/*************************************************************************
                           Measurement  
                             -------------------
    début                : $02/05/2022$
    copyright            : (C) $2022$ par $CHAUDRON$
    e-mail               : $felicie.chaudron@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Measurement> ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes
#define NMAP

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


DateTime Measurement::getTimeStamp()
{
    return timeStamp;
}

long Measurement::getValue()
{
    return value;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement (DateTime timeStamp, long Value)
{
	this->timeStamp = timeStamp;
    this->value = Value;
	
	#ifdef MAP
		cout << "Appel au constructeur de <Measurement>" << endl;
	#endif
} //----- Fin du constructeur Measurement

    

Measurement::~Measurement ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Measurement>" << endl;
	#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


