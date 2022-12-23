/**
 * @file Dashboard.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Dashboard.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Admin.h" // Also includes User
#include "MenuBar.h"
#include "Menu.h"
#include <filesystem>


#ifndef DASHBOARD_H
#define	DASHBOARD_H

class Dashboard{
  public:
    /**
    * @brief Create a new instance of the desired Dashboard interface
    * 
    * @param type Type of Dashboard interface
    * @return Dashboard*  
    */
    static Dashboard *Create(User &user, const std::string type = "CLI");
    virtual ~Dashboard();
    void setUser(User &user){this->user=&user;};
    virtual void showMainMenu() = 0;
    /**
    * @brief Changes the current interface to the input one
    * 
    * @param newInterface Desired interface to change ( .. = main Menu)
    * @return true = can change interface
    * @return false = cannot change interface
    */
    bool changeInterface(std::string newInterface = "");
    /**
    * @brief Adds all the current sensors to the dashboard
    * @note Only called at the start of the program
    */
    void addToMainMenu();
    /**
    * @brief Adds a sensor to the dashboard
    * 
    * @param sensor Sensor to add
    */
    void addToMainMenu(Sensor *sensor);
    /**
    * @brief Shifts the main menu n pages
    * 
    * @param n Number of pages to shift ( positive to the right )
    */
    void moveWindowMainMenu(int n = 1);
    /**
    * @brief Changes the current sensor values
    * 
    * @param toChange Desired value to change
    * @param newValue New value to add
    */
    void changeCurrentSensorInfo(std::string toChange, std::string newValue);
    /**
    * @brief Creates the new sensor and calls addToMainMenu
    * 
    * @param type New sensor type
    * @see addToMainMenu
    */
    void addNewSensor(std::string type);
    /**
    * @brief Deletes the desired sensor from the dashboard
    * 
    * @param id ID of the sensor to delete
    * @see addToMainMenu
    */
    void deleteSensor(std::string id);
    /**
    * @brief Exits the dashboard and finishes the program
    * @see cleanSensor
    */
    void exit();
    /**
    * @brief Exits the dashboard and goes back to the login screen
    * @see cleanSensor
    */
    void logout();
    /**
    * @brief Called from main, checks if the program is allowed to exit
    * 
    * @return true End the program
    * @return false Cannot exit, goes to login screen 
    */
    bool canExit();

  protected:
    Dashboard(User &user); /* basic constructor */
    /**
     * @brief Vector of all the vectors in the dashboard
     */
    std::vector <Sensor *> sensor;
    /**
     * @brief Vetor that contains the pages of the main Menu
     */
    std::vector <std::vector <Sensor *>> mainMenu;
    /**
     * @brief Current page of the main Menu 
     */
    int mainMenuIndex;
    MenuBar * menuBar;
    Menu * menu;
    User * user;
    /**
     * @brief Current interface, can be a sensor ID or the main menu (..)
     */
    std::string currentInterface;
    /**
     * @brief Last interface, can be a sensor ID or the main menu (..)
     */
    std::string lastInterface;
    /**
     * @brief If the currentInterface is a sensor then the value would be that sensor, if not the value is nullptr
     */
    Sensor * currentSensor;
    bool allowedToExit;

private:
  static Dashboard* singleDashboard;
};

#endif