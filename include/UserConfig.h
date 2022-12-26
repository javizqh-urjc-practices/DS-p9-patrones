/**
 * @file UserConfig.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of UserConfig.cpp
 * @version 0.1
 * @date 2022-12-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef USERCONFIG_H
#define	USERCONFIG_H

#include "Config.h"

class UserConfig: public Config{
  public:
    UserConfig(std::string language = "ENG", std::array<int,3> backgroundColor = {0,0,0}, std::array<int,3> fontColor = {255,255,255} , std::array<int,3> graphicColor = {255,0,0});

    std::array<int,3> * getGraphicColor(){ return &graphicColor;};
    void setGraphicColor(std::array<int,3> newGraphicColor);

    ~UserConfig();
  protected:
    std::array<int,3> graphicColor;

 };

#endif
 