/**
 * @file Interface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Interface.h"
#include "CLInterface.h"

Interface::Interface(){};

Interface *Interface::Create(const std::string type){
  if (type == "CLI"){
    try {
      return new CLInterface;
    }
    catch(std::bad_alloc &except) {
     std::cerr << "Exception: " << except.what() << std::endl;
     std::exit(EXIT_FAILURE);
    } catch(std::exception &e){
      throw e;
    }
  }
  else {
    throw std::runtime_error(type + " is not a defined Interface type");
    std::exit(EXIT_FAILURE);
  }
};

void Interface::login(const std::string userNumber, const std::string nif){
  loginInterface = LoginInterface::Create();
  this->loginInterface = loginInterface;
  this->loginInterface->askEmployeeNumber(userNumber);
  this->loginInterface->askNIF(nif);
  try {
    this->user = this->loginInterface->checkUser();
    system("clear");
    delete this->loginInterface;
  } catch (std::exception &e) {
    throw; // exception raised again
    exit(1);
  }
};

bool Interface::loadMenu(){
  dashboard = Dashboard::Create(this->user);
  this->dashboard = dashboard;
  this->dashboard->showMainMenu();
  bool canExit = this->dashboard->canExit();
  delete this->dashboard;
  return canExit;
};

Interface::~Interface(){};