/**
 * @file Database.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Database.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Admin.h"
#include <set>
#include <fstream>
#include <iostream>
#include <iterator>
#include <filesystem>

#ifndef DATABASE_H 
#define	DATABASE_H 

class Database{
  public:
    Database(); /* basic constructor */
    ~Database();
    /**
     * @brief Get the User object in the database, if not throws an exception
     * 
     * @param employeeNumber 
     * @param NIF 
     * @param currentUser 
     */
    void getUser(std::string employeeNumber,std::string NIF, User &currentUser);
    void resetUser(User &currentUser);
    void addUsers(std::vector<User> newUsers);
  private:
    std::set<User> user;
};

#endif