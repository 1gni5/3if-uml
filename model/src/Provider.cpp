//---------- Réalisation de la classe <Provider> -------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>

using std::string;
using std::list;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string Provider::getCleaner()
{ 
	return cleaner; 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Provider>" << std::endl;
	#endif
} //---- Fin du constructeur Provider

Provider::Provider (list<string> fields)
{
    cleaner = fields.front();

    #ifdef MAP
        std::cout << "Appel au constructeur de <Provider>" << std::endl;
    #endif
} //----- Fin du constructeur Provider

Provider::~Provider ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Provider>" << std::endl;
	#endif
} //----- Fin de ~Provider

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
