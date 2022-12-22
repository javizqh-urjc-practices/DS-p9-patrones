/**
 * @file CameraRGB.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CameraRGB.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef CAMERARGB_H 
#define	CAMERARGB_H 

class CameraRGB : public Sensor{
  public:
    /**
    * @brief Create a new RGB camera object
    * 
    * @param active By default off
    * @param valPerMin By default 1 val/min
    */
    CameraRGB(bool active = false, int valPerMin = 1);
    /**
    * @brief Request data from the rgb camera
    * 
    * @return std::vector<int>  Data values
    * @note This function is a placeholder, returns random values 
    */
    std::vector<int> requestData();
    ~CameraRGB();
  private:
    /**
    * @brief Id of all the rgb camera so there is not a duplicate id
    * 
    */
    static int idNumber ;
};

#endif