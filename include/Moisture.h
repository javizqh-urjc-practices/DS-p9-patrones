/**
 * @file Moisture.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Moisture.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef MOISTURE_H 
#define	MOISTURE_H

class Moisture : public Sensor{
  public:
    /**
    * @brief Create a new Moisture object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    Moisture(bool active = false, int valPerMin = 1);
    /**
    * @brief Request data from the moisture sensor
    * 
    * @return std::vector<int>  Data values
    * @note This function is a placeholder, returns random values 
    */
    std::vector<int> requestData();
    ~Moisture();
  private:
    /**
    * @brief Id of all the moisture sensor so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif