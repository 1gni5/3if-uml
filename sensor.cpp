//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//-------------------------------------------- Méthodes

long Sensor::getSensorID()
{
  return this->sensorID;
}

coord_t Sensor::getCoordinates()
{
  return this->coordinates;
}
//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor(long sensorID, long longitude, long latitude)
{
  this->sensorID = sensorID;
  coord_t coordinates;
  coordinates.latitude = latitude;
  coordinates.longitude = longitude;
  this->coordinates = coordinates;
  #ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
  #endif
} //----- Fin de Sensor
