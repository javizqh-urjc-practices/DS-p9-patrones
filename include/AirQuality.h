/**
 * @file AirQuality.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of AirQuality.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef AIRQUALITY_H 
#define	AIRQUALITY_H

class AirQuality : public Sensor{
  public:
    /**
    * @brief Create a new Air Quality object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    AirQuality(bool active = false, int valPerMin = 1);
    /**
    * @brief Request data from the air quality sensor
    * 
    * @return std::vector<int>  Data values
    * @note This function is a placeholder, returns random values 
    */
    std::vector<int> requestData();
    ~AirQuality();
  private:
    /**
    * @brief Id of all the air quality sensor so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif