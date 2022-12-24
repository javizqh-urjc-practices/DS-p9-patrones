/**
 * @file Humidity.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Humidity.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef HUMIDITY_H 
#define	HUMIDITY_H

class Humidity : public Sensor{
  public:
    /**
    * @brief Create a new Humidity object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    Humidity(bool active = false, int valPerMin = 1);
    ~Humidity();
  private:
    /**
    * @brief Id of all the humidity sensor so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif