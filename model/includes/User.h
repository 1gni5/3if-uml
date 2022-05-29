//------------- Interface de la classe <User> ----------------------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getId();
	string getSensor();

//-------------------------------------------- Constructeurs - destructeur
	User();
    User(std::list<string> fields);
    virtual ~User();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string id;
    string sensor;
};

//-------------------------- Autres définitions dépendantes de <User> ----

#endif // USER_H
