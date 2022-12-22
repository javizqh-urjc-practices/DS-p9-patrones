/**
 * @file CLLoginInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLLoginInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LoginInterface.h"
#include "CLIUtils.h"

#ifndef CLLOGININTERFACE_H
#define	CLLOGININTERFACE_H

class CLLoginInterface : public LoginInterface{
  public:
    CLLoginInterface(); /* basic constructor */
    /**
    * @brief Show the login screen messages in the command line
    * 
    */
    void showWelcomeMessage();
    /**
    * @brief Ask the user to input the employee number from the command line
    * 
    */
    void askEmployeeNumber();
    /**
    * @brief Default setter of employee number
    * @note This method is used when the user executes the main with the NIF and employee number
    * @param userNumber 
    */
    void askEmployeeNumber(const std::string  & userNumber);
    /**
    * @brief Ask the user to input the employee nif from the command line
    * 
    */
    void askNIF();
    /**
    * @brief Default setter of employee nif
    * @note This method is used when the user executes the main with the NIF and employee number
    * @param nif 
    */
    void askNIF(const std::string & nif);
    ~CLLoginInterface();
};

#endif