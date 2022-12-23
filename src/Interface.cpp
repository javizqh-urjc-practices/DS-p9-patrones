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
  User *currentUser = new User();
  this->user = currentUser;
  this->loginInterface->askEmployeeNumber(userNumber);
  this->loginInterface->askNIF(nif);
  try {
    this->loginInterface->checkUser(*user);
    system("clear");
  } catch (std::exception &e) {
    throw; // exception raised again
    exit(1);
  }
};

bool Interface::loadMenu(){
  dashboard = Dashboard::Create(*user);
  this->dashboard = dashboard;
  this->dashboard->showMainMenu();
  try {
    this->loginInterface->database->resetUser(*user);
    system("clear");
  } catch (std::exception &e) {
    throw; // exception raised again
    exit(1);
  }
  bool canExit = this->dashboard->canExit();
  return canExit;
};

Interface::~Interface(){
  delete this->loginInterface;
  delete this->dashboard;
};