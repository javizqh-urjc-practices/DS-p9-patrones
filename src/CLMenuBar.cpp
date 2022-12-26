/**
 * @file CLMenuBar.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLMenuBar.h"

CLMenuBar::CLMenuBar(){}

void CLMenuBar::show(){
  moveCursor(0,0);
  printLeftFromFile("config/LANG/" + this->user.getConfiguration()->getLanguage() + "/user/userDisplay.txt", *this->user.getConfiguration()->getFontColor(),*this->user.getConfiguration()->getBackgroundColor());
  printColor(this->user.getName(),*this->user.getConfiguration()->getFontColor(),*this->user.getConfiguration()->getBackgroundColor());
  printCenter(this->currentMenu,*this->user.getConfiguration()->getFontColor(),*this->user.getConfiguration()->getBackgroundColor());
  printRightFromFile("config/LANG/" + this->user.getConfiguration()->getLanguage() + "/exitTag.txt", *this->user.getConfiguration()->getFontColor(),*this->user.getConfiguration()->getBackgroundColor());
  newLine();
  reloadCursorPos(); // Reload cursor pos
}

