/**
 * @file Moisture.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Moisture.h"

int Moisture::idNumber = 0;

Moisture::Moisture (bool active, int valPerMin):Sensor("moist" + std::to_string(Moisture::idNumber ++),"moisture sensor","% MC",active,valPerMin){}

Moisture::~Moisture(){}
