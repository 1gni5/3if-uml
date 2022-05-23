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
using std::tm;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

time_t Cleaner::getStart()
{ return start; }

time_t Cleaner::getStop()
{ return stop; }

long Cleaner::getLongitude()
{ return longitude; }

long Cleaner::getLatitude()
{ return latitude; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner ()
{
	#ifdef MAP
		cout << "Appel au constructeur de <Cleaner>" << endl;
	#endif
} //---- Fin du constructeur Cleaner

Cleaner::Cleaner (list<string> fields)
{
    // Extract latitude and longitude
    latitude = atol(fields.front().c_str());
    fields.pop_front();

    longitude = atol(fields.front().c_str());
    fields.pop_front();

    // Extract start and stop dates
    start = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

    stop = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

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
time_t parseDateTime(string fdate, string fmt)
{
    tm time;
//    strptime(fdate.c_str(), "%Y-%m-%d %H:%M:%S", &time);
    strptime(fdate.c_str(), fmt.c_str(), &time);
    return mktime(&time);
}
