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

UserConfig::~UserConfig(){};