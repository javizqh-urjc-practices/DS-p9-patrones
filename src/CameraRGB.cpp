/**
 * @file CameraRGB.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CameraRGB.h"

int CameraRGB::idNumber = 0;

CameraRGB::CameraRGB (bool active, int valPerMin):Sensor("rgbcam" + std::to_string(CameraRGB::idNumber ++),"camera","-",active,valPerMin){}

std::vector<int> CameraRGB::requestData(){
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

CameraRGB::~CameraRGB(){}
