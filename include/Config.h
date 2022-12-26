/**
 * @file Config.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <string>
#include <array>
#include <filesystem>

class Config{
  public:
    Config(std::string language, std::array<int,3> backgroundColor , std::array<int,3> fontColor);

    std::string getLanguage() const { return language; };
    void setLanguage(std::string newLanguage);

    std::array<int,3> * getBackgroundColor(){ return &backgroundColor; };
    void setBackgroundColor(std::array<int,3> newBackgroundColor);

    std::array<int,3> * getFontColor(){ return &fontColor;};
    void setFontColor(std::array<int,3> newFontColor);

    ~Config();
  protected:
    char language [5];
    std::array<int,3> backgroundColor;
    std::array<int,3> fontColor;

 };

#endif
 