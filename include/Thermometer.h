/**
 * @file Thermometer.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Thermometer.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef THERMOMETER_H 
#define	THERMOMETER_H

class Thermometer : public Sensor{
  public:
    /**
    * @brief Create a new Thermometer object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    Thermometer(bool active = false, int valPerMin = 1);
    /**
    * @brief Request data from the thermometer
    * 
    * @return std::vector<int>  Data values
    * @note This function is a placeholder, returns random values 
    */
    std::array<int,60> requestData();
    ~Thermometer();
  private:
    /**
    * @brief Id of all the thermometer so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif