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

Database::Database(){
  std::ifstream inUsersFile ("server/database/users.dat", std::ios::in | std::ios::binary);
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
  std::filesystem::copy("server/database/users.dat", "server/database/users.dat~",std::filesystem::copy_options::update_existing);

  if (this->user.empty()){
    Admin *defaultAdmin = new Admin("98765","1234567A");
    this->user.insert(*defaultAdmin);
  }
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

void Database::addUsers(std::vector<User> newUsers){
  for (User newUser : newUsers){
    this->user.insert(newUser);
  }
};

void Database::deleteUsers(std::vector<User> deleteUsers){
  if (deleteUsers.empty()) return;
  if (this->user.size() == 1) return;
  
  std::set<User> updatedUsers;  
  for (User deleteUser : deleteUsers){
    for (User i: this->user){
      if (!(i.isSameEmployeeNumber(deleteUser.getEmployeeNumber()) && i.isSameNIF(deleteUser.getNIF()))){
        updatedUsers.insert(i);
      }
    }
  }
  this->user.clear();
  this->user = updatedUsers;
};

Database::~Database(){
  // Delete the file and create it again
  std::filesystem::remove("server/database/users.dat" );
  std::ofstream { "server/database/users.dat" };

  std::fstream outUsersFile ("server/database/users.dat", std::ios::in | std::ios::out | std::ios::binary); // ios::in will require an existing file
  if (!outUsersFile){
    // Create file if it doesn't exist
    std::ofstream {"server/database/users.dat" };
    outUsersFile.open("server/database/users.dat");
  }

  if (!outUsersFile) { // fstream could not open file
    std::cerr << "File could not be opened." << std::endl;
    exit (1);
  }

  int counter = 0;

  for (auto it = this->user.begin(); it != this->user.end(); it++){
    outUsersFile.seekp ( counter * sizeof (User));
    outUsersFile.write (reinterpret_cast <const char *> (&*it), sizeof (User));   
    counter++;
  }
}