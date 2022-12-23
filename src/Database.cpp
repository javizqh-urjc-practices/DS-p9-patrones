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
#include <iterator>

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
  //User *user1 = new User("10000","1234567A","paco");
  //UserConfig *user2Config = new UserConfig("ENT",{255,255,255},{0,0,150},{200,200,0});
  //User *user2 = new User(*user2Config,"20000","1234527J", "juan");
  //Admin *admin1 = new Admin("30000","1234567C", "ELBOSS");
  //this->user.insert(*user1);
  //this->user.insert(*user2);
  //this->user.insert(*admin1);
}

void Database::getUser(std::string employeeNumber, std::string NIF, User &user){
  for (User i: this->user){
    if (i.isSameEmployeeNumber(employeeNumber) && i.isSameNIF(NIF)){
      i.addTimestamp();
      user = i;
      return;
    }
  }
  throw NotFoundUserException();
}

void Database::resetUser(User &newUser){
  this->user.erase(newUser);
  this->user.insert(newUser);
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