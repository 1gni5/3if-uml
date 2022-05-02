//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

#include "Coordinates.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    t_time getStart();
    t_time getStop();
    coord_t getCoordinates();

//-------------------------------------------- Constructeurs - destructeur
    Cleaner(std::list<std::string> fields);
    virtual ~Cleaner();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    coord_t location;
    t_time start;
    t_time stop;
};

//----------------------- Autres définitions dépendantes de <Attribute>

#endif // CLEANER_H
