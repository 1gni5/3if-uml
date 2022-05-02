/*************************************************************************
                           User  -  description
                             -------------------
    début                : $02/05/2022$
    copyright            : (C) $2022$ par $esoulier$
    e-mail               : $erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
// 
//
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    long getSensorID();
    long getUserID (); 
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User (long userID, long sensorID);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    long userID;
    long sensorID;

};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // User_H