/**
 * @file User.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 2.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"
#include <iostream>
#include <iomanip> // I/O manipulation library

std::ostream &operator<< (std::ostream &output, const User &user){
  output << "( " << user.name << ", " << user.employeeNumber << ", " << user.NIF << " ) ";
  return output;
}

User::User(std::string employeeNumber, std::string NIF, std::string name){
  this->setName(name);
  this->setEmployeeNumber(employeeNumber);
  this->setNIF(NIF);
  this->addTimestamp();
  this->adminPermission = false;
}

bool User::operator<(const User& user) const {
   return NIF > user.NIF || employeeNumber < user.employeeNumber;  //assume that you compare the record based on a
}

bool User::operator==(const User& user) const {
   return NIF == user.NIF && employeeNumber == user.employeeNumber;  //assume that you compare the record based on a
}

void User::setNIF(std::string newNIF){
  int length = newNIF.size();
  length = (length < 9 ? length : 8);
  newNIF.copy (NIF, length);
  NIF [length] = '\0';
};

void User::setName(std::string newName){
  int length = newName.size();
  length = (length < 21 ? length : 20);
  newName.copy (name, length);
  name [length] = '\0'; // null character
}

void User::setEmployeeNumber(std::string newEmployeeNumber){
  int length = newEmployeeNumber.size();
  length = (length < 6 ? length : 5);
  newEmployeeNumber.copy (employeeNumber, length);
  employeeNumber [length] = '\0';
};

bool User::isSameNIF(std::string compareNIF){
  return NIF == compareNIF;
};

bool User::isSameEmployeeNumber(std::string compareEmployeeNumber){
  return employeeNumber == compareEmployeeNumber;
};



std::string User::getName() const{
  return this->name;
};

void User::addTimestamp(){
  auto date = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(date);

  std::string newLastLogTime = std::ctime(&t);
  int length = newLastLogTime.size();
  length = (length < 25 ? length : 24);
  newLastLogTime.copy (lastLogTime, length);
  lastLogTime [length] = '\0';
};

std::string User::getTimestamp() const{
  return this->lastLogTime;
};

bool User::hasAdminPermission(){
  return this->adminPermission;
}

User::~User(){};