/**
 * @file Database.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Database.h"
#include "NotFoundUserException.h"
#include <fstream>
#include <iostream>

Database::Database(){
  std::ifstream inUsersFile ("data/users.dat", std::ios::in | std::ios::binary);
  if (!inUsersFile) { // fstream could not open file
    std::cerr << "File could not be opened." << std::endl;
    exit (1);
  }
  User user;
  inUsersFile.read (reinterpret_cast <char *>(&user), sizeof (User));

  while (inUsersFile && !inUsersFile.eof()) {
    this->user.insert(user);
    inUsersFile.read (reinterpret_cast <char *>(&user), 
      sizeof (User));
  }
}

User Database::getUser(std::string employeeNumber, std::string NIF){
  
  for (User i: this->user){
    if (i.isSameEmployeeNumber(employeeNumber) && i.isSameNIF(NIF)){
      i.addTimestamp();
      return i;
    }
  }
  throw NotFoundUserException();
}

Database::~Database(){
  std::fstream outUsersFile ("data/users.dat", std::ios::in | std::ios::out | std::ios::binary); // ios::in will require an existing file

  if (!outUsersFile) { // fstream could not open file
    std::cerr << "File could not be opened." << std::endl;
    exit (1);
  }

  User user;
  int counter = 0;

  for (auto it = this->user.begin(); it != this->user.end(); it++){
    outUsersFile.seekp ( counter * sizeof (User));
    outUsersFile.write (reinterpret_cast <const char *> (&*it), sizeof (User));   
    counter++;
  }
}