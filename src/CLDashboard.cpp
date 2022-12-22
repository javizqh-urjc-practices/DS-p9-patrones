/**
 * @file CLDashboard.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLDashboard.h"


CLDashboard::CLDashboard(const User &user):Dashboard(user){
  this->mainMenuIndex = 0;
  this->menuBar = MenuBar::Create();
  this->menu = Menu::Create();
}

void CLDashboard::showMainMenu(){
  this->menuBar->setUser(this->user);
  this->currentInterface = "..";
  changeInterface(this->currentInterface);
  startCustomTerminal(10);
  readCommand();
}

void CLDashboard::readCommand(){
  std::vector<std::string> command;
  int lineNumber = 0;
  clearCustomTerminal(10);
  while (true){
    lineNumber++;
    if (lineNumber >= 9){ lineNumber=0; clearCustomTerminal(10);}
    command = newCommand(this->user,this->currentInterface);
    /* Check if the command is empty */
    if (command.size() == 0);

    /* Command with only one word */
    else if (command.size() == 1){
      if (command[0].compare("ls") == 0){ lineNumber++; listSensor();}
      else if (command[0].compare("left") == 0) changeMainMenu(-1);
      else if (command[0].compare("right") == 0) changeMainMenu(1);
      else if (command[0].compare("log") == 0) std::cout << this->user.getTimestamp();
      else if (command[0].compare("clear") == 0) clearCustomTerminal(10);
      else if (command[0].compare("logout") == 0){ logout(); break;}
      else if (command[0].compare("exit") == 0){ exit(); break;}
      else if (command[0].compare("update") == 0) {
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else if (command[0].compare("back") == 0) {
        changeInterface(this->lastInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else errorCommand(command[0]);
    }

    /* Command with two words */
    /* Check if the command has two words */
    else if (command.size() == 2){
      if (command[0].compare("man") == 0) {lineNumber++; helpCommand(command[1]);}
      else if (command[0].compare("set") == 0) changeCurrentSensorInfo("state", command[1]);
      else if (command[0].compare("cs") == 0) {
        if (! changeInterface(command[1])) {lineNumber++;errorCommand("cs "+command[1]);}
        else {std::cout << "\u001b[u"; }// Reload cursor pos
      }
      else if (command[0].compare("add") == 0){
        if (! this->user.hasAdminPermission()){permissionError();continue;}
        addNewSensor(command[1]);
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
        lineNumber++;
      }
      else if (command[0].compare("rm") == 0){
        if (! this->user.hasAdminPermission()){permissionError();continue;}
        deleteSensor(command[1]);
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else errorCommand(command[0]);
    }

    /* Command with three words */
    /* Check if the command has three words */
    else if (command.size() == 3){
      if (command[0].compare("set") == 0) changeCurrentSensorInfo(command[1], command[2]);
      else errorCommand(command[0]);
    }
    
    else {lineNumber++;errorCommand(command[0]);}

    command.clear();
  }
}

void CLDashboard::listSensor(){
if (this->currentInterface.compare("..") != 0) return;

  for ( Sensor *s: this->mainMenu[this->mainMenuIndex]){
    std::cout << s->getId() << "\t";
  }
  std::cout << "\n";
}

void CLDashboard::changeMainMenu(int n){
  if (this->currentInterface.compare("..") == 0){ 
    moveWindowMainMenu(n);
    changeInterface("..");
    std::cout << "\u001b[u"; // Reload cursor pos
  }
}


void CLDashboard::helpCommand(std::string command){
  std::cout << "Help " << command << "\n";
}

void CLDashboard::errorCommand(std::string command){
  std::cout << command << ": command not found\n";
}

void CLDashboard::permissionError(){
  std::cout << this->user.getName() << " does not have the permissions required. Make sure to contact an administrator.\n";
}

CLDashboard::~CLDashboard(){
  std::cout << "\u001b[0m"; 
  system("clear");
}
