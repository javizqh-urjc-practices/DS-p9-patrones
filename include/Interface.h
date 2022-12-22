/**
 * @file Interface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Interface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LoginInterface.h"
#include "Dashboard.h"
#include "Admin.h" // Also includes User

#ifndef INTERFACE_H 
#define	INTERFACE_H 

class Interface{
public:
  /**
  * @brief Create a new Interface instance of the type specified
  * 
  * @param type Type of interface
  * @return Interface* New Interface instance
  */
  static Interface *Create(const std::string type = "CLI");
  Interface(); /* basic constructor */
  /**
   * @brief Virtual interface for the login method
   * 
   * @param tries 
   */
  virtual void login(int tries) = 0;
  /**
  * @brief Default login method withouth any interface
  * 
  * @param userNumber 
  * @param nif 
  * @note This method is used when the user executes the main with the NIF and employee number
  */
  void login(std::string userNumber, std::string nif);
  /**
  * @brief Creates and loads the dashboard
  * 
  * @return true = exit
  * @return false = login again
  */
  bool loadMenu();
  virtual ~Interface();

protected:
  LoginInterface * loginInterface;
  Dashboard * dashboard;
  User user;
};

#endif