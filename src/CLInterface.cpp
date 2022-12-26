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
  if (tries == globalConfig->getTriesToLogin()) {cleanScreen();std::exit(0);}

  loginInterface = LoginInterface::Create();
  loginInterface->setGlobalConfig(globalConfig);
  this->loginInterface = loginInterface;

  User *currentUser = new User();
  this->user = currentUser;

  this->loginInterface->showWelcomeMessage();
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  usleep(2 * 1000000);
  try {
    loginInterface->checkUser(*user);
    printCenterFromFile("config/LANG/" + globalConfig->getLanguage() + "/login/succesful.txt",*globalConfig->getFontColor(),*globalConfig->getBackgroundColor());
    newLine();
    usleep(1 * 1000000);
    printColor("",*user->getConfiguration()->getFontColor(),*user->getConfiguration()->getBackgroundColor());
    cleanScreen(*user->getConfiguration()->getBackgroundColor());
    tries = 0;
  } catch (std::exception &e) {
    printCenterFromFile("config/LANG/" + globalConfig->getLanguage() + "/login/failed.txt", {255,0,0},*globalConfig->getBackgroundColor());
    newLine();
    usleep(1 * 1000000);
    tries++;
    login(tries);
  }
}