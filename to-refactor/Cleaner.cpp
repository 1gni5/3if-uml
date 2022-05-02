//---------- Réalisation de la classe <cleaner> ------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <ctime>

using std::string;
using std::list;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"
#include "Coordinates.h"

//------------------------------------------------------------- Constantes

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

Cleaner::Cleaner (list<string> fields)
{
    location = Coordinates(fields.front());
    fields.pop_front();
    start = t_time(fields.front());
    fields.pop_front();
    stop = t_time(fields.front());
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


