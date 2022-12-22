/**
 * @file MenuBar.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of MenuBar.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>

#ifndef MENUBAR_H
#define	MENUBAR_H

class MenuBar{
  public:
    /**
    * @brief Create a new Menu bar instance of the type specified
    * 
    * @param type Type of menu bar
    * @return MenuBar* New menu bar instance
    */
    static MenuBar *Create(const std::string type = "CLI");
    MenuBar(); /* basic constructor */
    virtual ~MenuBar();
    virtual void show() = 0;
    /**
    * @brief Sets the user name 
    * 
    * @param userName 
    */
    void setUserName(std::string userName);
    /**
    * @brief Sets the current menu
    * 
    * @param currentMenu 
    */
    void setCurrentMenu(std::string currentMenu);
  protected:
    std::string userName;
    std::string currentMenu;
};

#endif