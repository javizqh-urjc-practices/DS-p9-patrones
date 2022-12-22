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

LoginInterface::LoginInterface(){}

LoginInterface *LoginInterface::Create(const std::string type){
  if (type == "CLI"){
    return new CLLoginInterface;
  }
  else {
    throw std::runtime_error(type + " is not a defined LoginInterface type");
    std::exit(1);
  }
};

User LoginInterface::checkUser(){
  try {
    User *user = new User();
    *user = this->dastabase.getUser(this->inputEmployeeNumber,this->inputNIF);
    return *user;
  } catch (std::exception &e) {
    throw; // exception raised again
  }
}

LoginInterface::~LoginInterface(){}