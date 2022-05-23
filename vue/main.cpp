/*************************************************************************
                           main  -  description
                             -------------------
    début                : $23/05/2022$
    copyright            : (C) $2021$ par $esoulier$
    e-mail               : $erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "main.h"
#include "../controleur/Controleur.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
time_t parseDateTimeFromMain(string fdate, string fmt)
{
    tm time;
//    strptime(fdate.c_str(), "%Y-%m-%d %H:%M:%S", &time);
    strptime(fdate.c_str(), fmt.c_str(), &time);
    return mktime(&time);
}

int main ()
// Algorithme :
//
{
  char input = '0';
  long latitude, longitude;
  time_t date;
  string date_str, jour_str, heure_str;
  //Initialiser le controller ici
  Controleur *c = new Controleur();
  //c->test();
  do 
  {
    cout<<endl;
    cout << "==================== MENU ====================" << endl;
    cout << "Choisir un service: " << endl;
    cout << "0 : Vérifier la validité des capteurs" << endl;
    cout << "1 : Calculer validité de l'air en un point et instant donné" << endl;
    cout << "2 : Quitter l'application" << endl;
    cin >> input;
    cout << "==============================================" << endl;
    switch (input)
    { 
      case '0':
        //Lancer la validation des capteurs avec le controller
        //c->verifieSensorValidity(); 
        break;
      case '1':
        cout << "Donnez la latitude: " << endl;
        cin >> latitude;
        cout << "Donnez la longitude: " << endl;
        cin >> longitude;
        cout << "Donnez la date: (format Y-m-d) " << endl;
        cin >> jour_str;
        cout << "Donnez la date: (format H:M:S) " << endl;
        cin >> heure_str;
        date_str = jour_str + ' ' + heure_str;
        date = parseDateTimeFromMain(date_str, "%Y-%m-%d %H:%M:%S"); //Test : 2019-01-01 12:00:00
        cout << date_str << endl;
        cout << date << endl;
        //Lancer le calcul de la validité de l'air
        //c->computeAirQuality(longitude, latitude, date);
        break;
      case '2':
        cout << "Au revoir..." << endl;
        break;
      default:
        cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 4" << endl;
    }
  } while (input != '2');
  return 0;
} //----- fin de main