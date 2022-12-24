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

AirQuality::~AirQuality(){}
