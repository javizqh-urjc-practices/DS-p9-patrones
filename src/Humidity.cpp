/**
 * @file Humidity.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Humidity.h"

int Humidity::idNumber = 0;

Humidity::Humidity (bool active, int valPerMin):Sensor("hum" + std::to_string(Humidity::idNumber ++),"humidity sensor","g/m³",active,valPerMin){}


std::array<int,60> Humidity::requestData(){
  //int valueRange = 20;
  //this->data.clear();
  //int newVal = rand() % valueRange;
  //if (newVal < 0) newVal *= -1 ;
  //int med = newVal;
  //this->data.push_back(med);
  //for (int i = 0; i < 60 * this->valPerMin - 1; i++){
  //  newVal = rand() % valueRange;
  //  med = ( med + newVal ) / 2;
  //  this->data.push_back(med);
  //}
  //
  //return this->data;
  return {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,};
}

Humidity::~Humidity(){}
