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


CLDashboard::CLDashboard(User &user):Dashboard(user){
  this->mainMenuIndex = 0;
  this->menuBar = MenuBar::Create();
  this->menu = Menu::Create();
}

void CLDashboard::showMainMenu(){
  this->menuBar->setUser(*this->user);
  this->currentInterface = "..";
  cleanScreen(*this->user->getConfiguration()->getBackgroundColor());
  changeInterface(this->currentInterface);
  readCommand();
}

void CLDashboard::readCommand(){
  std::vector<std::string> command;
  int lineNumber = 0;
  clearCustomTerminal(*this->user,10);
  while (true){
    lineNumber++;
    if (lineNumber >= 9){ lineNumber=0; clearCustomTerminal(*this->user,10);}
    command = newCommand(*this->user,this->currentInterface);
    /* Check if the command is empty */
    if (command.size() == 0);

    /* Command with only one word */
    else if (command.size() == 1){
      if (command[0].compare("ls") == 0){ lineNumber++; listSensor();}
      else if (command[0].compare("left") == 0) changeMainMenu(-1);
      else if (command[0].compare("right") == 0) changeMainMenu(1);
      else if (command[0].compare("log") == 0) std::cout << this->user->getTimestamp();
      else if (command[0].compare("clear") == 0) { lineNumber=0; clearCustomTerminal(*this->user,10);;}
      else if (command[0].compare("logout") == 0){ logout(); break;}
      else if (command[0].compare("exit") == 0){ exit(); break;}
      else if (command[0].compare("config") == 0) {
        changeInterface("config");
        reloadCursorPos(); // Reload cursor pos
      }
      else if (command[0].compare("update") == 0) {
        changeInterface(this->currentInterface);
        reloadCursorPos(); // Reload cursor pos
      }
      else if (command[0].compare("back") == 0) {
        changeInterface(this->lastInterface);
        reloadCursorPos(); // Reload cursor pos
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
        else {reloadCursorPos(); }// Reload cursor pos
      }
      else if (command[0].compare("add") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        addNewSensor(command[1]);
        changeInterface(this->currentInterface);
        reloadCursorPos(); // Reload cursor pos
        lineNumber++;
      }
      else if (command[0].compare("rm") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        deleteSensor(command[1]);
        changeInterface(this->currentInterface);
        reloadCursorPos(); // Reload cursor pos
      }
      else if (command[0].compare("name") == 0){
        this->user->setName(command[1]);
        this->menuBar->setUser(*this->user);
        changeInterface(this->currentInterface);
        reloadCursorPos(); // Reload cursor pos
      }
      else if (command[0].compare("lang") == 0){
        this->user->setLanguage(command[1]);
        this->menuBar->setUser(*this->user);
        cleanScreen(*this->user->getConfiguration()->getBackgroundColor()); 
        changeInterface(this->currentInterface);
        lineNumber = 0; 
        clearCustomTerminal(*this->user,10);
      }
      else errorCommand(command[0]);
    }

    /* Command with three words */
    /* Check if the command has three words */
    else if (command.size() == 3){
      if (command[0].compare("set") == 0) changeCurrentSensorInfo(command[1], command[2]);
      else if (command[0].compare("user") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        if (command[1].size() != 5 && command[2].size() != 8) errorCommand(command[0]);
        User *user = new User(command[1], command[2]);
        this->newUsers.push_back(*user);
      }
      else if (command[0].compare("admin") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        if (command[1].size() != 5 && command[2].size() != 8) errorCommand(command[0]);
        Admin *admin = new Admin(command[1], command[2]);
        this->newUsers.push_back(*admin);
      }
      else errorCommand(command[0]);
    }

    /* Command with four words */
    /* Check if the command has four words */
    else if (command.size() == 4){
      if (command[0].compare("user") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        if (command[1].size() != 5 && command[2].size() != 8) errorCommand(command[0]);
        User *user = new User(command[1], command[2], command[3]);
        this->newUsers.push_back(*user);
      }
      else if (command[0].compare("admin") == 0){
        if (! this->user->hasAdminPermission()){permissionError();continue;}
        if (command[1].size() != 5 && command[2].size() != 8) errorCommand(command[0]);
        Admin *admin = new Admin(command[1], command[2], command[3]);
        this->newUsers.push_back(*admin);
      }
      else if (command[0].compare("font") == 0){
        try {
          this->user->setFontColor({std::stoi(command[1]),std::stoi(command[2]),std::stoi(command[3])});
          this->menuBar->setUser(*this->user);
          cleanScreen(*this->user->getConfiguration()->getBackgroundColor()); 
          changeInterface(this->currentInterface);
          lineNumber = 0; 
          clearCustomTerminal(*this->user,10);
        } catch(const std::exception& e) {lineNumber++;errorCommand(command[0]);} 
      }
      else if (command[0].compare("background") == 0){
        try {
          this->user->setBackgroundColor({std::stoi(command[1]),std::stoi(command[2]),std::stoi(command[3])});
          this->menuBar->setUser(*this->user);
          cleanScreen(*this->user->getConfiguration()->getBackgroundColor());
          changeInterface(this->currentInterface);
          lineNumber = 0; 
          clearCustomTerminal(*this->user,10);
        } catch(const std::exception& e) {lineNumber++;errorCommand(command[0]);} 
      }
      else if (command[0].compare("graphic") == 0){
        try {
          this->user->setGraphicColor({std::stoi(command[1]),std::stoi(command[2]),std::stoi(command[3])});
          this->menuBar->setUser(*this->user);
          cleanScreen(*this->user->getConfiguration()->getBackgroundColor());
          changeInterface(this->currentInterface);
          clearCustomTerminal(*this->user,10);
        } catch(const std::exception& e) {lineNumber++;errorCommand(command[0]);} 
      }
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
  newLine();
}

void CLDashboard::changeMainMenu(int n){
  if (this->currentInterface.compare("..") == 0){ 
    moveWindowMainMenu(n);
    changeInterface("..");
    reloadCursorPos(); // Reload cursor pos
  }
}


void CLDashboard::helpCommand(std::string command){
  //TODO: add help command
  std::cout << "Help " << command << "\n";
}

void CLDashboard::errorCommand(std::string command){
  printColor(command,*user->getConfiguration()->getFontColor(),*user->getConfiguration()->getBackgroundColor());
  printColorFromFile("config/LANG/" + user->getConfiguration()->getLanguage() + "/commands/notFound.txt", *user->getConfiguration()->getFontColor(),*user->getConfiguration()->getBackgroundColor());
  newLine();
}

void CLDashboard::permissionError(){
  printColor(this->user->getName(),*user->getConfiguration()->getFontColor(),*user->getConfiguration()->getBackgroundColor());
  printColorFromFile("config/LANG/" + user->getConfiguration()->getLanguage() + "/commands/permissionError.txt", *user->getConfiguration()->getFontColor(),*user->getConfiguration()->getBackgroundColor());
  newLine();
}

CLDashboard::~CLDashboard(){
  cleanScreen();
}
