/**
 * @file CLInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLInterface.h"

CLInterface::CLInterface(){
  setTerminalSize();
};

void CLInterface::login(int tries){
  if (tries == 0){
    loginInterface = LoginInterface::Create();
    this->loginInterface = loginInterface;
  }
  if (tries == 5) std::exit(0);

  this->loginInterface->showWelcomeMessage();
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  usleep(2 * 1000000);
  try {
    this->user = this->loginInterface->checkUser();
    printCenter("Login successful" );
    std::cout << "\n";
    usleep(1 * 1000000);
    system("clear");
    tries = 0;
    delete this->loginInterface;
  } catch (std::exception &e) {
    printCenter("Failed login\n", "red");
    usleep(1 * 1000000);
    tries++;
    login(tries);
  }
}