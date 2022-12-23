/**
 * @file Sensor.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"
#include "Thermometer.h"
#include "Humidity.h"
#include "Moisture.h"
#include "AirQuality.h"
#include "CameraBW.h"
#include "CameraRGB.h"

std::array<std::string,6> Sensor::availableTypesId = {"therm","hum","airqual","bwcam","rgbcam","moist"};
std::array<std::string,6> Sensor::availableTypes = {"thermometer","humidity","airquality","bwcamera","rgbcamera","moisture"};

/**
 * @brief Creates an instance of the sensor type
 * 
 * @param type 
 * @return Sensor* 
 */
Sensor *Sensor::Create(std::string type){
  if (type == "thermometer"){
    return new Thermometer;
  }
  else if (type == "humidity"){
    return new Humidity;
  }
  else if (type == "moisture"){
    return new Moisture;
  }
  else if (type == "airquality"){
    return new AirQuality;
  }
  else if (type == "bwcamera"){
    return new CameraBW;
  }
  else if (type == "rgbcamera"){
    return new CameraRGB;
  }
  else {
    throw std::runtime_error(type + " is not a defined sensor type");
    std::exit(1);
  }
};

Sensor::Sensor(std::string id, std::string type, std::string magnitude, bool active, int valPerMin){
  setId(id);
  setType(type);
  setArea("none");
  setMagnitude(magnitude);
  setActive(active);
  setValPerMin(valPerMin);
}

void Sensor::setId(std::string newId){
  int length = newId.size();
  length = (length < 11 ? length : 10);
  newId.copy (id, length);
  id [length] = '\0';
};

void Sensor::setType(std::string newType){
  int length = newType.size();
  length = (length < 21 ? length : 20);
  newType.copy (type, length);
  type [length] = '\0';
};

void Sensor::setArea(std::string newArea){
  int length = newArea.size();
  length = (length < 21 ? length : 20);
  newArea.copy (area, length);
  area [length] = '\0';
}

void Sensor::setMagnitude(std::string newMagnitude){
  int length = newMagnitude.size();
  length = (length < 11 ? length : 10);
  newMagnitude.copy (magnitude, length);
  magnitude [length] = '\0';
}

void Sensor::setActive(bool active){
  this->active = active;
};

void Sensor::setValPerMin(int valPerMin){
  valPerMin = (valPerMin > 0 ? valPerMin : 1); 
  this->valPerMin = valPerMin;
}

Sensor::~Sensor(){};