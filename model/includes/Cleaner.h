//---------- Interface de la classe <Cleaner> ----------------------------
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
    string getId();
    time_t getStart();
    time_t getStop();
	double getLongitude();
	double getLatitude();

//-------------------------------------------- Constructeurs - destructeur
	Cleaner();
    Cleaner(std::list<string> fields);
    virtual ~Cleaner();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string id;
	double latitude;
	double longitude;
    time_t start;
    time_t stop;
};

//---------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H
