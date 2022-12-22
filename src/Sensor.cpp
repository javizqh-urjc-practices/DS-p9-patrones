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
  this->id = id;
  this->type = type;
  this->active = active;
  this->magnitude = magnitude;
  this->valPerMin = valPerMin;
  this->area = "none";
}


std::string Sensor::getId(){
  return this->id;
};

void Sensor::setActive(bool active){
  this->active = active;
};

bool Sensor::isActive(){
  return this->active;
}

std::string Sensor::getType(){
  return this->type;
}

void Sensor::setArea(std::string area){
  this->area = area;
}

std::string Sensor::getArea(){
  return this->area;
}

void Sensor::setMagnitude(std::string magnitude){
  this->magnitude = magnitude;
}

std::string Sensor::getMagnitude(){
  return this->magnitude;
}

void Sensor::setValPerMin(int valPerMin){
  if (valPerMin <= 0) return;
  this->valPerMin = valPerMin;
}

int Sensor::getValPerMin(){
  return this->valPerMin;;
}

Sensor::~Sensor(){};