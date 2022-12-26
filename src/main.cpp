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

int main(int argc,char* argv[]){
  GlobalConfig *globalConfig = new GlobalConfig("ESP",5,{0,130,50},{0,0,0},{255,255,255});
  Interface *interface;
  interface = Interface::Create();
  interface->setGlobalConfig(globalConfig);
  if ( argc - 1  == 0 ){
    bool isRunning = true;
    while (isRunning) {
      // Execute the program until exit is requested
      interface->login(0);
      isRunning = ! interface->loadMenu();
    }
  }
  else if (argc - 1 == 2){
    interface->login(argv[1],argv[2]);
    interface->loadMenu();
  }
  delete interface;
}
