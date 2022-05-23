/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ----------------
#if ! defined ( CONTROLEUR_H )
#define CONTROLEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "../model/includes/System.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controleur>
//
//
//------------------------------------------------------------------------

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    System sys;

};

//-------------------------------- Autres définitions dépendantes de <Controleur>

#endif // Controleur_H

