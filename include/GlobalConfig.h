/**
 * @file GlobalConfig.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GLOBALCONFIG_H
#define	GLOBALCONFIG_H

#include "Config.h"

class GlobalConfig: public Config{
  public:
    GlobalConfig(std::string language = "ENG",int triesToLogin = 5, std::array<int,3> backgroundColor = {0,0,0},
     std::array<int,3> fontColor = {255,255,255} , std::array<int,3> logoColor = {255,0,0});

    int getTriesToLogin() const { return triesToLogin; };
    void setTriesToLogin(int newTriesToLogin);

    std::array<int,3> * getLogoColor(){ return &logoColor;};
    void setLogoColor(std::array<int,3> newLogoColor);

    ~GlobalConfig();
  protected:
    int triesToLogin;
    std::array<int,3> logoColor;

 };

#endif
 