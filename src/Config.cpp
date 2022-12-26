/**
 * @file Config.cpp
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

 #include "Config.h"

Config::Config( std::string language, std::array<int,3> backgroundColor, std::array<int,3> fontColor){
  setLanguage(language);
  setBackgroundColor(backgroundColor);
  setFontColor(fontColor);
}

void Config::setLanguage(std::string newLanguage){
  // Check if the LANG config exists
  if (!std::filesystem::is_directory("config/LANG/" + newLanguage) || !std::filesystem::exists("config/LANG/" + newLanguage)) { // Check if folder exists
    newLanguage = "ENG"; // If not, put it in english language.
  } 
  int length = newLanguage.size();
  length = (length < 5 ? length : 4);
  newLanguage.copy (language, length);
  language [length] = '\0';
}

void Config::setBackgroundColor(std::array<int,3> newBackgroundColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newBackgroundColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->backgroundColor[index] = colorValue;
  }
}

void Config::setFontColor(std::array<int,3> newFontColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newFontColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->fontColor[index] = colorValue;
  }
}

Config::~Config(){};