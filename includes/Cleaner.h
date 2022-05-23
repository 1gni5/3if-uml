//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    time_t getStart();
    time_t getStop();
	long getLongitude();
	long getLatitude();

//-------------------------------------------- Constructeurs - destructeur
	Cleaner();
    Cleaner(std::list<string> fields);
    virtual ~Cleaner();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	long latitude;
	long longitude;
    time_t start;
    time_t stop;
};

//-------------------------- Autres définitions dépendantes de <Attribute>
time_t parseDateTime(string fdate, string fmt);

#endif // CLEANER_H
