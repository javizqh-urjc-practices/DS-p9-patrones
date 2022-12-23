/**
 * @file User.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of User.cpp
 * @version 2.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <ostream>
#include "UserConfig.h"
#ifndef USER_H
#define	USER_H

class User{
friend std::ostream &operator<< (std::ostream &,const User &);
public:
  /**
  * @brief Create a new User
  * 
  * @param employeeNumber 
  * @param NIF 
  * @param name 
  */
  User(std::string number = "00000",std::string nif = "00000000",std::string name = "default");
  User(UserConfig UserConfig, std::string number = "00000",std::string nif = "00000000",std::string name = "default");
  ~User();
  std::string getNIF() const {return NIF;};
  bool isSameNIF(std::string NIF);

  std::string getEmployeeNumber() const {return employeeNumber;};
  bool isSameEmployeeNumber(std::string employeeNumber);
  /**
  * @brief Returns the user name
  * 
  * @return std::string User name
  */
  std::string getName() const {return name;};
  void setName(std::string newName);
  /**
  * @brief Set the timestamp 
  * 
  */
  void addTimestamp();
  /**
  * @brief Returns the timestamp
  * 
  * @return std::string Timestamp
  */
  std::string getTimestamp() const;
  /**
  * @brief Returns the user permissions
  * 
  * @return true = has admin pemissions 
  * @return false = does not have admin permissions
  */
  bool hasAdminPermission();
  bool operator<(const User &) const;
  bool operator==(const User &) const;

  /**
  * @brief Set the user NIF
  * 
  * @param NIF 
  */
  void setNIF(std::string);
  /**
  * @brief Set the user employee number
  * 
  * @param employeeNumber 
  */
  void setEmployeeNumber(std::string);

  void setConfig(UserConfig newConfig) {userConfiguration = newConfig;};
  UserConfig* getConfiguration(){ return &userConfiguration;};
  
protected:
  char name [21];
  char NIF [9]; /* 8 digits */
  char employeeNumber [6]; /* 5 digits */
  char lastLogTime [25];
  bool adminPermission;
  UserConfig userConfiguration;

};

#endif