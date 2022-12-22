/**
 * @file CameraBW.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CameraBW.h"

int CameraBW::idNumber = 0;

CameraBW::CameraBW (bool active, int valPerMin):Sensor("bwcam" + std::to_string(CameraBW::idNumber ++),"camera","-",active,valPerMin){}

std::vector<int> CameraBW::requestData(){
  int valueRange = 1;
  this->data.clear();
  int newVal = rand() % valueRange;;
  int med = newVal;
  this->data.push_back(med);
  for (int i = 0; i < 60 * this->valPerMin - 1; i++){
    newVal = rand() % valueRange;
    med = ( med + newVal ) / 2;
    this->data.push_back(med);
  }
  
  return this->data;
}

CameraBW::~CameraBW(){}
