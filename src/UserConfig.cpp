/**
 * @file UserConfig.cpp
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "UserConfig.h"

UserConfig::UserConfig( std::string language, std::array<int,3> backgroundColor, std::array<int,3> fontColor,
 std::array<int,3> graphicColor): Config(language, backgroundColor, fontColor){
  setGraphicColor(graphicColor);
}

void UserConfig::setGraphicColor(std::array<int,3> newGraphicColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newGraphicColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->graphicColor[index] = colorValue;
  }
}

UserConfig::~UserConfig(){};