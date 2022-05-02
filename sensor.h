//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if !defined(Sensor_H)
#define Sensor_H

#include <string>
#include "Coordinates.h"
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
  //----------------------------------------------------------------- PUBLIC
public:
  //----------------------------------------------------- Méthodes publiques
  long getSensorID();

  coord_t getCoordinates();

  //-------------------------------------------- Constructeurs - destructeur
  Sensor(const Sensor &aSensor);

  Sensor(long sensorID, long longitude, long latitude);

  //------------------------------------------------------------------ PRIVE

private:
  long sensorID;
  coord_t coordinates;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // Sensor_H
