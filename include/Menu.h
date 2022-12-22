/**
 * @file Menu.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Menu.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"

#ifndef MENU_H
#define	MENU_H

class Menu{
  public:
    /**
    * @brief Create a new Menu instance of the type specified
    * 
    * @param type Type of menu
    * @return Menu* New menu instance
    */
    static Menu *Create(const std::string type = "CLI");
    Menu(); /* basic constructor */
    virtual void show(std::vector <Sensor *> ) = 0;
    virtual void show(Sensor *) = 0;
    virtual ~Menu();
};

#endif