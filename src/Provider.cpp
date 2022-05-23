//---------- Réalisation de la classe <cleaner> --------------------------

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
{ return cleaner; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider ()
{
	#ifdef MAP
		cout << "Appel au constructeur de <Provider>" << endl;
	#endif
} //---- Fin du constructeur Provider

Provider::Provider (list<string> fields)
{
    // Extract latitude and longitude
    cleaner = fields.front();

    #ifdef MAP
        cout << "Appel au constructeur de <Provider>" << endl;
    #endif
} //----- Fin du constructeur Provider

Provider::~Provider ( )
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Provider>" << endl;
	#endif
} //----- Fin de ~Provider

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
