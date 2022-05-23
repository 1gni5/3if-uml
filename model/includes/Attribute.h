//---------- Interface de la classe <attribute> --------------------------
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

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
    Attribute ( const Attribute &obj); 
    Attribute (list<string> fields); 
    virtual ~Attribute ();

    string getUnit();
    string getDescription();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
	
	friend std::ostream& operator<<(
        std::ostream& cout, 
        const Attribute& obj
    );

//----------------------------------------------------- Attributs protégés
    string unit;
    string description;
};

//----------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H