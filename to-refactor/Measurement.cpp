//---------- Réalisation de la classe <Measurement> ----------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

using std::string;

//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


t_time Measurement::getTimeStamp()
{
    return timeStamp;
}

long Measurement::getValue()
{
    return value;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement (list<string> fields)
{
    timeStamp = t_time(fields.front());
    fields.pop_front();
    value = atol(fields.front().c_str());
    fields.pop_front();

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
