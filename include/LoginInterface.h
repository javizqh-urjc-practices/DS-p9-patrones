/**
 * @file LoginInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of LoginInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Database.h"

#ifndef LOGININTERFACE_H
#define	LOGININTERFACE_H

class LoginInterface{
public:
  /**
  * @brief Create a new Login interface instance of the type specified
  * 
  * @param type Type of login interface
  * @return LoginInterface* New login interface instance
  */
  static LoginInterface *Create(const std::string = "CLI");
  LoginInterface(); /* basic constructor */
  virtual ~LoginInterface();
  virtual void showWelcomeMessage() = 0;
  virtual void askEmployeeNumber() = 0;
  virtual void askEmployeeNumber(const std::string & userNumber) = 0;
  virtual void askNIF() = 0;
  virtual void askNIF(const std::string & userNumber) = 0;
  /**
   * @brief Returns the user in the database with the corresponding employee number and NIF
   * 
   * @return User 
   */
  User checkUser();

protected:
  std::string inputNIF; /* 8 digits */
  std::string inputEmployeeNumber; /* 5 digits */
  Database dastabase;
};

#endif