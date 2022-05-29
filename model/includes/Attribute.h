//---------- Interface de la classe <attribute> --------------------------
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

#include "Measurement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
    Attribute ();
    Attribute (list<string> fields); 
    virtual ~Attribute ();

    string getUnit();
    string getDescription();

    void addMeasurement(const Measurement& m);
    std::list<Measurement>& getMeasurements();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string unit;
    string description;

    std::list<Measurement> measurements;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H