/**
 * @file AirQuality.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "AirQuality.h"

int AirQuality::idNumber = 0;

AirQuality::AirQuality (bool active, int valPerMin):Sensor("airqual" + std::to_string(AirQuality::idNumber ++),"air quality sensor","µg/m³",active,valPerMin){}

std::vector<int> AirQuality::requestData(){
  int valueRange = 150;
  this->data.clear();
  int newVal = rand() % valueRange;
  if (newVal < 0) newVal *= -1 ;
  int med = newVal;
  this->data.push_back(med);
  for (int i = 0; i < 60 * this->valPerMin - 1; i++){
    newVal = rand() % valueRange;
    med = ( med + newVal ) / 2;
    this->data.push_back(med);
  }
  
  return this->data;
}

AirQuality::~AirQuality(){}
