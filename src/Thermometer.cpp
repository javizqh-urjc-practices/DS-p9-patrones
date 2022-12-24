/**
 * @file Thermometer.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Thermometer.h"

int Thermometer::idNumber = 0;

Thermometer::Thermometer (bool active, int valPerMin):Sensor("therm" + std::to_string(Thermometer::idNumber ++),"thermometer","C",active,valPerMin){}

Thermometer::~Thermometer(){}
