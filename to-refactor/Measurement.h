//---------- Interface de la classe <measurement> ------------------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
#include <ctime>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    t_time getTimeStamp();
    void setTimeStamp(t_time time);
    long getValue();
    void setValue(long value);

//-------------------------------------------- Constructeurs - destructeur
    Measurement(std::list<std::string> fields);
    ~Measurement();

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    DateTime timeStamp;
    long value;
};

//----------------------- Autres définitions dépendantes de <Measurement> 

#endif // MEASUREMENT_H
