/**
 * @file CLMenuBar.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLMenuBar.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "MenuBar.h"
#include "CLIUtils.h"

#ifndef CLMENUBAR_H
#define	CLMENUBAR_H

class CLMenuBar : public MenuBar{
  public:
    CLMenuBar(); /* basic constructor */
    /**
    * @brief Show the menu bar in the command line
    * 
    */
    void show();

};

#endif