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

CameraBW::~CameraBW(){}
