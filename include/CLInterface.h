/**
 * @file CLInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Interface.h"
#include "CLIUtils.h"
#include <unistd.h>

#ifndef CLINTERFACE_H 
#define	CLINTERFACE_H 

class CLInterface : public Interface{
  public:
    /**
    * @brief Create a new Interface for the command line
    * @note Also gets the terminal size 
    */
    CLInterface(); /* basic constructor */
    /**
    * @brief Controls the login interface for the command line
    * 
    * @param tries Number of tries to login
    * @note If exceeded the number of tries, then the program will exit
    */
    void login(int tries);
};

#endif