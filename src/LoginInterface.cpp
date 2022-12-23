/**
 * @file LoginInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LoginInterface.h"
#include "CLLoginInterface.h"
#include <stdexcept> 

LoginInterface::LoginInterface(){
  Database* db = new Database();
  this->database = db;
}

LoginInterface* LoginInterface::singleLoginInterface = nullptr;

LoginInterface *LoginInterface::Create(const std::string type){
  if (singleLoginInterface == nullptr){
    if (type == "CLI"){
      singleLoginInterface = new CLLoginInterface();
    }
    else {
      throw std::runtime_error(type + " is not a defined LoginInterface type");
      std::exit(1);
    }
  }
  return singleLoginInterface;
};

void LoginInterface::checkUser(User &currentUser){
  try {
    database->getUser(this->inputEmployeeNumber,this->inputNIF, currentUser);
  } catch (std::exception &e) {
    throw; // exception raised again
  }
}

LoginInterface::~LoginInterface(){
  delete database;
}