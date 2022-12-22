/**
 * @file CLMenu.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLMenu.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Menu.h"
#include "CLIUtils.h"

#ifndef CLMENU_H
#define	CLMENU_H

class CLMenu : public Menu{
  public:
    CLMenu(); /* basic constructor */
    /**
    * @brief Shows the menu with six or less smaller sensors displayed in the command line
    * 
    * @param sensors Array of sensor to display <= 7
    */
    void show(std::vector <Sensor *> );
    /**
    * @brief Shows the menu for the sensor selected in a detailed format in the command line
    * 
    * @param sensorToDisplay Sensor to display
    */
    void show(Sensor *sensor);

  protected:
    /**
    * @brief Clear the menu in the command line
    * 
    */
    void clearMenu();
};

#endif