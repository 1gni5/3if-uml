//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

using std::string;

#include "Model.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getUnique(void);
    time_t getStart(void);
    time_t getStop(void);
	long getLongitude(void);
	long getLatitude(void);

//-------------------------------------------- Constructeurs - destructeur
	Cleaner(void);
    Cleaner(std::list<string> fields);
    virtual ~Cleaner(void);

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

    void updateBackRefs(void);

//----------------------------------------------------- Attributs protégés

    string id;
	long latitude;
	long longitude;
    time_t start;
    time_t stop;

    // Attribute for Model use only
    size_t _id;

    friend class Model<Cleaner>;
};

//-------------------------- Autres définitions dépendantes de <Attribute>
time_t parseDateTime(string fdate, string fmt);

#endif // CLEANER_H
