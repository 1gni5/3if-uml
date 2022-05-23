//---------- Interface de la classe <cleaner> ----------------------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
#include <list>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	string getCleaner();

//-------------------------------------------- Constructeurs - destructeur
	Provider();
    Provider(std::list<string> fields);
    virtual ~Provider();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string cleaner;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // PROVIDER_H
