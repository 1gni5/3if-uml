//---------- Réalisation de la classe <provider> -------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::string;
using std::list;
using std::vector;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Provider::getUnique(void)
{ return id; }

Cleaner Provider::getCleaner(void)
{ return *cleaner; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider (void)
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Provider>" << std::endl;
	#endif
} //---- Fin du constructeur Provider

Provider::Provider (list<string> fields)
{
    // Extract latitude and longitude
    id = fields.front();

	string unique = fields.front();
	cleaner = &Model<Cleaner>::get(unique);

    #ifdef MAP
        std::cout << "Appel au constructeur de <Provider>" << std::endl;
    #endif
} //----- Fin du constructeur Provider

Provider::~Provider (void)
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Provider>" << std::endl;
	#endif
} //----- Fin de ~Provider

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Provider::updateBackRefs(void)
{
	// Nothing to do here
}