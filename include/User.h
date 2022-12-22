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
  ~User();
  bool isSameNIF(std::string NIF);
  bool isSameEmployeeNumber(std::string NIF);
  /**
  * @brief Returns the user name
  * 
  * @return std::string User name
  */
  std::string getName() const;
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
protected:
  char name [21];
  char NIF [9]; /* 8 digits */
  char employeeNumber [6]; /* 5 digits */
  char lastLogTime [25];
  bool adminPermission;

};

#endif