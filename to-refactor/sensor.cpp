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

Sensor::Sensor(string sensorID, string longitude, string latitude)
{
  this->sensorID = stol(sensorID);
  coord_t coordinates;
  coordinates.latitude = stol(latitude);
  coordinates.longitude = stol(longitude);
  this->coordinates = coordinates;
  #ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
  #endif
} //----- Fin de Sensor
