//---------- Réalisation de la classe <user> --------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string User::getSensor()
{ return sensor; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

User::User ()
{
	#ifdef MAP
		cout << "Appel au constructeur de <User>" << endl;
	#endif
} //---- Fin du constructeur User

User::User (list<string> fields)
{
	// Extract Sensor
    sensor = fields.front();

    #ifdef MAP
        cout << "Appel au constructeur de <User>" << endl;
    #endif
} //----- Fin du constructeur User

User::~User ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <User>" << endl;
	#endif
} //----- Fin de ~User

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
