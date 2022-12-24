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

Humidity::~Humidity(){}
