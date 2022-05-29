//---------- Réalisation de la classe <System> --------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Deserialize.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
System::System()
{
    // Charge le fichier CSV en mémoire
    deserialize<Attribute>(
        "datasets/attributes.csv",
        attributes, 0, true
    );

    deserialize<Cleaner>(
        "datasets/cleaners.csv",
        cleaners, 0
    );

    deserialize<Measurement>(
        "datasets/measurements-50.csv",
        measurements, 0, true, false
    );

    deserialize<Provider>(
        "datasets/providers.csv",
        providers, 0
    );

    deserialize<Sensor>(
        "datasets/sensors.csv",
        sensors, 0
    );

    deserialize<User>(
        "datasets/users.csv",
        users, 0
    );
    
    // Création des relations entre les objets
    for (auto &measurement : measurements)
    {
        // Récupère le capteur et ajoute la mesure.
        string idSensor = measurement.second.getSensor();
        Sensor& sensor = sensors[idSensor];
        sensor.addMeasurement(measurement.second);

        // Récupère l'attribut et ajoute la mesure.
        string idAttribute = measurement.second.getUnit();
        Attribute& attribute = attributes[idAttribute];
        attribute.addMeasurement(measurement.second);
    }

    #ifdef MAP
        std::cout << "Appel au constructeur par défaut de <System>" << std::endl;
    #endif
}//----- Fin de System

System::~System ( )
{	
	#ifdef MAP
		std::cout << "Appel au destructeur de <System>" << std::endl;
	#endif
} //----- Fin de ~System


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
