//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>
#include <vector>

using std::string;

#include "Model.h"
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getUnique(void);
	Cleaner getCleaner(void);

//-------------------------------------------- Constructeurs - destructeur
	Provider(void);
    Provider(std::list<string> fields);
    virtual ~Provider(void);

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

    void updateBackRefs(void);

//----------------------------------------------------- Attributs protégés
    string id;
    Cleaner* cleaner;
    
    // Attribute for Model use only
    size_t _id;

    friend class Model<Provider>;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // PROVIDER_H
