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

UserConfig::UserConfig( std::string language, std::array<int,3> backgroundColor, std::array<int,3> fontColor, std::array<int,3> graphicColor){
  setLanguage(language);
  setBackgroundColor(backgroundColor);
  setFontColor(fontColor);
  setGraphicColor(graphicColor);
}

void UserConfig::setLanguage(std::string newLanguage){
  int length = newLanguage.size();
  length = (length < 5 ? length : 4);
  newLanguage.copy (language, length);
  language [length] = '\0';
}

void UserConfig::setBackgroundColor(std::array<int,3> newBackgroundColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newBackgroundColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->backgroundColor[index] = colorValue;
  }
}

void UserConfig::setFontColor(std::array<int,3> newFontColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newFontColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->fontColor[index] = colorValue;
  }
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