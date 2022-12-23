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

#include <string>
#include <array>

#ifndef USERCONFIG_H
#define	USERCONFIG_H

class UserConfig{
  public:
    UserConfig(std::string language = "ENG", std::array<int,3> backgroundColor = {0,0,0}, std::array<int,3> fontColor = {255,255,255} , std::array<int,3> graphicColor = {255,0,0});

    std::string getlanguage() const { return language; };
    void setLanguage(std::string newLanguage);

    std::array<int,3> * getBackgroundColor(){ return &backgroundColor; };
    void setBackgroundColor(std::array<int,3> newBackgroundColor){ backgroundColor = newBackgroundColor;};

    std::array<int,3> * getFontColor(){ return &fontColor;};
    void setFontColor(std::array<int,3> newFontColor){ fontColor = newFontColor;};

    std::array<int,3> * getGraphicColor(){ return &graphicColor;};
    void setGraphicColor(std::array<int,3> newGraphicColor){ graphicColor = newGraphicColor;};

    ~UserConfig();
  private:
    char language [5];
    std::array<int,3> backgroundColor;
    std::array<int,3> fontColor;
    std::array<int,3> graphicColor;

 };

#endif
 