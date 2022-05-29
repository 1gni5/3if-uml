//---------- Réalisation de la classe <measurement> ----------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>

using std::string;
using std::list;
using std::tm;

//------------------------------------------------------ Include personnel
#include "Measurement.h"
#include "Utilities.h"
#include "Model.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

time_t Measurement::getTimestamp()
{ 
    return timestamp; 
}

double Measurement::getValue()
{ 
    return value; 
}

Attribute* Measurement::getAttribute()
{ 
    return unit; 
}

Sensor* Measurement::getSensor()
{ 
    return sensor; 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement ()
{
	#ifdef MAP
		std::cout << "Appel au constructeur de <Measurement>" << std::endl;
	#endif
} //---- Fin du constructeur Measurement

Measurement::Measurement (list<string> fields)
{
    timestamp = parseDateTime(fields.front(), "%Y-%m-%d %H:%M:%S");
    fields.pop_front();

    idSensor = fields.front();
    fields.pop_front();

    idUnit = fields.front();
    fields.pop_front();

    value = atol(fields.front().c_str());
    fields.pop_front();

    unit = nullptr;
    sensor = nullptr;

    #ifdef MAP
        std::cout << "Appel au constructeur de <Measurement>" << std::endl;
    #endif
} //----- Fin du constructeur Measurement

Measurement::~Measurement ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <Measurement>" << std::endl;
	#endif
} //----- Fin de ~Measurement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Measurement::updateBackRefs(void)
{
    // Récupère l'unité dans le Model
    unit = &Model<Attribute>::get(idUnit);

    // Récupère le capteur dans le Model
    sensor = &Model<Sensor>::get(idSensor);

    #ifdef MAP
        // Print unit and sensor
        std::cout << "Unit: " << unit->getId() << std::endl;
        std::cout << "Sensor: " << sensor->getId() << std::endl;
	#endif

    if (unit != nullptr)
    {
        // Ajoute cette mesure à la liste des mesures de l'unité
        unit->measurements.push_back(_id); 
    } else {
        std::cout << "Unit not found" << std::endl;
    }

    if (sensor != nullptr)
    {
        // Ajoute cette mesure à la liste des mesures du capteur
        sensor->measurements.push_back(_id); 
    } else {
        std::cout << "Sensor not found" << std::endl;
    }
}

string Measurement::getUnique(void)
{
    return toString(_id);
}