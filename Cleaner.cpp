/*************************************************************************
                           Cleaner  
                             -------------------
    début                : $02/05/2022$
    copyright            : (C) $2022$ par $CHAUDRON$
    e-mail               : $felicie.chaudron@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include "Coordinates.h"
#include <ctime>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes
#define NMAP

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


t_time Cleaner::getStart()
{
    return start;
}

t_time Cleaner::getStop()
{
    return stop;
}

coord_t Cleaner::getCoordinates()
{
    return location;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner (long cleanerID, coord_t location, t_time start, t_time stop)
{
	this->cleanerID = cleanerID;
    this->location = location;
    this->start = start;
    this->stop = stop;
	
	#ifdef MAP
		cout << "Appel au constructeur de <Cleaner>" << endl;
	#endif
} //----- Fin du constructeur Cleaner

    

Cleaner::~Cleaner ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Cleaner>" << endl;
	#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


