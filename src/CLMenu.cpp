/**
 * @file CLMenu.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLMenu.h"

CLMenu::CLMenu(){}

void CLMenu::show(std::vector <Sensor *> sensors){
  std::cout << "\u001b[s"; // Save cursor pos
  if (sensors.size() == 0) return;
  int graphicsInX = 3;
  int graphicsInY = 2;
  // Graphic size 30 * 15
  int positionsX = getTerminalWidth() / graphicsInX;
  int positionsY = ( getTerminalHeight() / graphicsInY ) - 5;
  clearMenu();
  for (int index = 0; index < sensors.size(); index++){
    Sensor *sensorToDisplay = sensors[index];
    if ( sensorToDisplay->getType().compare("camera") == 0 ){
      moveCursor(positionsX * (index % graphicsInX) + 10 + 8 , positionsY * (index / graphicsInX) + 5 + 7);
      std::cout << "No image available";
    } else {
      printGraphic(sensorToDisplay->requestData(),sensorToDisplay->getValPerMin(),positionsX * (index % graphicsInX) + 10, positionsY * (index / graphicsInX) + 5,2);
    }
    // Prin id below

    moveCursor(positionsX * (index % graphicsInX) + 10 + 16 , positionsY * (index / graphicsInX) + 5 + 18);
    std::cout << sensorToDisplay->getId();
  }
  std::cout << "\u001b[u"; // Reload cursor pos
}

void CLMenu::show(Sensor *sensorToDisplay){
  std::cout << "\u001b[s"; // Save cursor pos
  // Graphic size 60 * 30
  clearMenu();
  if ( sensorToDisplay->getType().compare("camera") == 0 ){
    moveCursor(10 + 25 , 10 + 15);
    std::cout << "No image available";
  }
  else {
    printGraphic(sensorToDisplay->requestData(),sensorToDisplay->getValPerMin(),10,10,1);
  }
  // Prin id below
  moveCursor(10 + 30 , 10 + 35);
  std::cout << sensorToDisplay->getId();

  // Print side information
  moveCursor(100 , 25 + 0);
  std::cout << "Id: "<<sensorToDisplay->getId();
  moveCursor(100 , 25 + 2);
  std::cout << "Type: "<<sensorToDisplay->getType();
  moveCursor(100 , 25 + 4);
  std::cout << "Area: "<<sensorToDisplay->getArea();
  moveCursor(100 , 25 + 6);
  std::cout << "Magnitude: "<<sensorToDisplay->getMagnitude();
  moveCursor(100 , 25 + 8);
  std::cout << "Values per minute: "<<sensorToDisplay->getValPerMin();
  moveCursor(100 , 25 + 10);
  std::cout << "Current state: ";
  if (sensorToDisplay->isActive()) printColor("On","green");
  else printColor("Off","red");
  std::cout << "\u001b[u"; // Reload cursor pos
}

void CLMenu::clearMenu(){
  std::cout << "\u001b[" << getTerminalHeight() - 12 << ";0H" << "\u001b[1J";
}