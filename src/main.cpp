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
  Interface *interfaceCli;
  interfaceCli = Interface::Create();
  if ( argc - 1  == 0 ){
    bool isRunning = true;
    while (isRunning) {
      // Execute the program until exit is requested
      interfaceCli->login(0);
      isRunning = ! interfaceCli->loadMenu();
    }
  }
  else if (argc - 1 == 2){
    interfaceCli->login(argv[1],argv[2]);
    interfaceCli->loadMenu();
  }
  delete interfaceCli;
}
