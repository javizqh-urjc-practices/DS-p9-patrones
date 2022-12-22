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
  std::cout << "\u001b[0m"; // No color
  system("clear");
  std::cout << "\u001b[2J\u001b[0;0H";
  printCenterFromFile("config/CLIWelcomeMessage.ascii", {0,255,0},{0,0,0});
  std::cout << "\n\n\n";
  printCenter("Enter your employee number: ",{255,255,255},{0,0,0},5);
  std::cout << "\n\n\n";
  printCenter("Enter your NIF: ",{255,255,255},{0,0,0},8);
  std::cout << "\u001b[s";
}

void CLLoginInterface::askEmployeeNumber(){
  std::cout << "\u001b[7C\u001b[3A";
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputEmployeeNumber = inputBuffer;
  delete inputBuffer;
}

void CLLoginInterface::askEmployeeNumber(const std::string & userNumber){
  this->inputEmployeeNumber = userNumber;
}

void CLLoginInterface::askNIF(){
  std::cout << "\u001b[u";
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputNIF = inputBuffer;
  delete inputBuffer;
  std::cout << "\n\n\n";
}

void CLLoginInterface::askNIF(const std::string & nif){
  this->inputNIF = nif;
}

CLLoginInterface::~CLLoginInterface(){}