/**
 * @file CameraBW.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CameraBW.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef CAMERABW_H 
#define	CAMERABW_H 

class CameraBW : public Sensor{
  public:
    /**
    * @brief Create a new BW camera object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    CameraBW(bool active = false, int valPerMin = 1);
    /**
    * @brief Request data from the bw camera
    * 
    * @return std::vector<int>  Data values
    * @note This function is a placeholder, returns random values 
    */
    std::vector<int> requestData();
    ~CameraBW();
  private:
    /**
    * @brief Id of all the black and white camera so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif