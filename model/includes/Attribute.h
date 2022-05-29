//---------- Interface de la classe <attribute> --------------------------
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
#include <vector>

using std::string;

#include "Model.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string getId(void);
    string getUnit(void);
    string getDescription(void);

    std::vector<size_t>& getMeasurements(void);

//-------------------------------------------- Constructeurs - destructeur
    Attribute (void);
    Attribute (std::list<string> fields); 
    virtual ~Attribute ();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    
    void updateBackRefs(void);
    string getUnique(void);

//----------------------------------------------------- Attributs protégés

    string id;
    string unit;
    string description;

    // Fonctionnement interne de Model<>
    size_t _id;
    std::vector<size_t> measurements;

    friend class Model<Attribute>;
    friend class Measurement;
};

//----------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H