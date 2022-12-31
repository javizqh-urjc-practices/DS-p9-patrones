/**
 * @file main.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "main.h"

int main(int argc,char* argv[],char *envp[]){
  std::string env = *envp;
  if (! env.find('/')) exit(1); // Not linux or mac, exit with error

  GlobalConfig *globalConfig = new GlobalConfig();
  Interface *interface;
  interface = Interface::Create();

  std::string userNumber ;
  std::string userNif ;

  // Process arguments
  std::vector<std::string> args(argv + 1, argv + argc);

  for (int index = 0; index < args.size(); index++){
    // First Check for config settings
    if (args[index].compare("-b") == 0 || args[index].compare("--background") == 0){
      //Check if index + 3 is valid index
      if (! checkArgumentIndex(index + 3, args.size())) break;

      try {
        globalConfig->setBackgroundColor({std::stoi(args[index + 1]), std::stoi(args[index + 2]), std::stoi(args[index + 3])});
      } catch (const std::exception &e) {
        throw NotFoundArgument();
      }

      //std::cout << "Background :" << args[index + 1] << "," << args[index + 2] << "," << args[index + 3] << std::endl; // DEBUG
    } 
    else if (args[index].compare("-f") == 0 || args[index].compare("--font") == 0){
      //Check if index + 3 is valid index
      if (! checkArgumentIndex(index + 3, args.size())) break;

      try {
        globalConfig->setFontColor({std::stoi(args[index + 1]), std::stoi(args[index + 2]), std::stoi(args[index + 3])});
      } catch (const std::exception &e) {
        throw NotFoundArgument();
      }

      //std::cout << "Font :" << args[index + 1] << "," << args[index + 2] << "," << args[index + 3] << std::endl; // DEBUG
    } 
    else if (args[index].compare("-l") == 0 || args[index].compare("--logo") == 0){
      //Check if index + 3 is valid index
      if (! checkArgumentIndex(index + 3, args.size())) break;

      try {
        globalConfig->setLogoColor({std::stoi(args[index + 1]), std::stoi(args[index + 2]), std::stoi(args[index + 3])});
      } catch (const std::exception &e) {
        throw NotFoundArgument();
      }

      //std::cout << "Logo :" << args[index + 1] << "," << args[index + 2] << "," << args[index + 3] << std::endl; // DEBUG
    } 
    else if (args[index].compare("-L") == 0 || args[index].compare("--lang") == 0){
      //Check if index + 1 is valid index
      if (! checkArgumentIndex(index + 1, args.size())) break;

      try {
        globalConfig->setLanguage(args[index + 1]);
      } catch (const std::exception &e) {
        throw NotFoundArgument();
      }

      //std::cout << "Language :" << args[index + 1] << std::endl; // DEBUG
    } 
    // Then check for Nif and employee number
    else if (args[index].compare("-u") == 0 || args[index].compare("--user") == 0){
      //Check if index + 2 is valid index
      if (! checkArgumentIndex(index + 2, args.size())) break;

      try {
        userNumber = args[index + 1];
        userNif = args[index + 2];
        break; // If passed user, no need to login, then no need for the global interface
      } catch (const std::exception &e) {
        throw NotFoundArgument();
      }
      
      //std::cout << "User :" << userNumber << "," << userNif << std::endl; // DEBUG
    } 
  }
  // Start the program

  interface->setGlobalConfig(globalConfig);
  
  if ( userNumber.empty() ){
    bool isRunning = true;
    while (isRunning) {
      // Execute the program until exit is requested
      interface->login(0);
      isRunning = ! interface->loadMenu();
    }
  }
  else {
    interface->login(userNumber,userNif);
    interface->loadMenu();
  }
  delete interface;
  
}