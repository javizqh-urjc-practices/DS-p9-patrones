/**
 * @file CLDashboard.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLDashboard.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Dashboard.h"
#include "CLIUtils.h"

#ifndef CLDASHBOARD_H
#define	CLDASHBOARD_H

class CLDashboard : public Dashboard{
  public:
    /**
    * @brief Create a new Dashboard for the command line
    * 
    */
    CLDashboard(User &user); /* basic constructor */
    /**
    * @brief Shows the default menu and starts the custom terminal
    * 
    */
    void showMainMenu();
    ~CLDashboard();
  protected:
    /**
    * @brief Change the page of the menu
    * 
    * @param n Number of pages to shift ( positive to the right )
    */
    void changeMainMenu(int n);
    /**
    * @brief Reads and executes a command from the terminal 
    * 
    */
    void readCommand();
    /**
    * @brief Command that lists the sensors in the current menu page
    * 
    */
    void listSensor();
    /**
    * @brief Displays the use of the command 
    * 
    * @param command Command to display info about
    * @param lineNumber Number of lines displayed
    */
    void helpCommand(std::string command, int &lineNumber);
    /**
    * @brief Shows error message because the command not being found
    * 
    * @param command Command input
    * @param lineNumber Number of lines displayed
    */
    void errorCommand(std::string command, int &lineNumber  );
    /**
    * @brief Shows error message because the permission being denied to execute it
    * 
    * @param lineNumber Number of lines displayed
    */
    void permissionError(int &lineNumber);
};

#endif