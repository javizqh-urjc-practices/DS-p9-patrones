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
  std::cout << "\u001b[0;0H";
  printLeft("User: " + this->userName);
  printCenter(this->currentMenu);
  printRight("Exit (exit) ");
  std::cout << "\n";
}

