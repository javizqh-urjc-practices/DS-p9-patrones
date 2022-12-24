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

CameraRGB::~CameraRGB(){}
