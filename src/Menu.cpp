/**
 * @file Menu.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Menu.h"
#include "CLMenu.h"

Menu::Menu(){}


Menu * Menu::Create(const std::string type){
  if (type == "CLI"){
    return new CLMenu;
  }
  else {
    throw std::runtime_error(type + " is not a defined Menu type");
    std::exit(1);
  }
}

Menu::~Menu(){}