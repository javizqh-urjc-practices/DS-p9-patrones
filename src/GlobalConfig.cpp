/**
 * @file GlobalConfig.cpp
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 #include "GlobalConfig.h"

GlobalConfig::GlobalConfig( std::string language,int triesToLogin, std::array<int,3> backgroundColor,
 std::array<int,3> fontColor, std::array<int,3> logoColor): Config(language, backgroundColor, fontColor){
  setTriesToLogin(triesToLogin);
  setLogoColor(logoColor);
}

void GlobalConfig::setTriesToLogin(int newTriesToLogin){
  if (newTriesToLogin <= 0) this->triesToLogin = 1; // Bottom bound 
  else this->triesToLogin = newTriesToLogin;
}

void GlobalConfig::setLogoColor(std::array<int,3> newLogoColor){
  int colorValue;
  for (int index = 0; index < 3; index++){
    colorValue = newLogoColor[index];
    if ( colorValue > 255) colorValue = 255; // Upper bound
    else if (colorValue < 0) colorValue = 0; // Bottom bound 
    this->logoColor[index] = colorValue;
  }
}

GlobalConfig::~GlobalConfig(){};