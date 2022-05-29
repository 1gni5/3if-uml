//---------- Interface de la classe <Provider> ---------------------------
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

//--------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H
