//---------- Interface de la classe <sensor> ----------------------------
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
	string getSensor();

//-------------------------------------------- Constructeurs - destructeur
	User();
    User(std::list<string> fields);
    virtual ~User();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string sensor;
};

//-------------------------- Autres définitions dépendantes de <Attribute>

#endif // USER_H
