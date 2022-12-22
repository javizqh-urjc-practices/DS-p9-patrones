/**
 * @file Admin.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Admin.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"

#ifndef ADMIN_H
#define	ADMIN_H

class Admin : public User{
  public:
    /**
    * @brief Creates a new Admin object
    * 
    * @param employeeNumber 
    * @param NIF 
    * @param name 
    */
    Admin(std::string number = "00000",std::string nif = "00000000",std::string name = "default");
    ~Admin();
};

#endif