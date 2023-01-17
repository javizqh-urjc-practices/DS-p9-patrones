/**
 * @file CLLoginInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLLoginInterface.h"

CLLoginInterface::CLLoginInterface(){}

void CLLoginInterface::showWelcomeMessage(){
  cleanScreen(*globalConfig->getBackgroundColor());
  
  // Size used 180 * 35
  int logoX = 180;

  // Calculate number of sensors per menu horizontal
  int availableSizeX = getTerminalWidth();
  if (availableSizeX > logoX) printLogo("config/LANG/" + globalConfig->getLanguage() + "/logo.txt", *globalConfig->getLogoColor(),*globalConfig->getBackgroundColor());
  else printLogo("config/LANG/" + globalConfig->getLanguage() + "/logoS.txt", *globalConfig->getLogoColor(),*globalConfig->getBackgroundColor());
  
  newLine(3);
  printCenterFromFile("config/LANG/" + globalConfig->getLanguage() + "/login/askNumber.txt",*globalConfig->getFontColor(),*globalConfig->getBackgroundColor(),5);
  newLine(3);
  printCenterFromFile("config/LANG/" + globalConfig->getLanguage() + "/login/askNIF.txt",*globalConfig->getFontColor(),*globalConfig->getBackgroundColor(),8);
  saveCursorPos();
}

void CLLoginInterface::askEmployeeNumber(){
  std::cout << "\u001b[7C\u001b[3A"; // Go to end of the propmpt
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputEmployeeNumber = inputBuffer;
  delete inputBuffer;
}

void CLLoginInterface::askEmployeeNumber(const std::string & userNumber){
  this->inputEmployeeNumber = userNumber;
}

void CLLoginInterface::askNIF(){
  reloadCursorPos(); // Go to end of the propmpt
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputNIF = inputBuffer;
  delete inputBuffer;
  newLine(3);
}

void CLLoginInterface::askNIF(const std::string & nif){
  this->inputNIF = nif;
}

CLLoginInterface::~CLLoginInterface(){}