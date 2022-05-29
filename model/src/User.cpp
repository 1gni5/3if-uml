//---------- Réalisation de la classe <User> -----------------------------

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

string User::getId()
{
	return id;
}

string User::getSensor()
{ 
	return sensor; 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

User::User ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <User>" << std::endl;
	#endif
} //---- Fin du constructeur User

User::User (list<string> fields)
{
	id = fields.front();
	fields.pop_front();

    sensor = fields.front();
	fields.pop_front();

    #ifdef MAP
        std::cout << "Appel au constructeur de <User>" << std::endl;
    #endif
} //----- Fin du constructeur User

User::~User ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <User>" << std::endl;
	#endif
} //----- Fin de ~User

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
