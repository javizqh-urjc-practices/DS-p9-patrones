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

void CLMenu::show(std::vector <Sensor *> sensors, UserConfig &config){
  std::cout << "\u001b[s"; // Save cursor pos
  if (sensors.size() == 0) return;
  int graphicsInX = 3;
  int graphicsInY = 2;
  // Graphic size 30 * 15
  int positionsX = getTerminalWidth() / graphicsInX;
  int positionsY = ( getTerminalHeight() / graphicsInY ) - 5;
  clearMenu();
  for (int index = 0; index < sensors.size(); index++){
    if ( sensors[index]->getType().compare("camera") == 0 ){
      moveCursor(positionsX * (index % graphicsInX) + 10 + 8 , positionsY * (index / graphicsInX) + 5 + 7);
      printColor("No image available",*config.getFontColor(),*config.getBackgroundColor());
    } else {
      printGraphic(sensors[index]->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensors[index]->getValPerMin(),positionsX * (index % graphicsInX) + 10, positionsY * (index / graphicsInX) + 5,2);
    }
    // Print id below

    moveCursor(positionsX * (index % graphicsInX) + 10 + 16 , positionsY * (index / graphicsInX) + 5 + 18);
    printColor(sensors[index]->getId(),*config.getFontColor(),*config.getBackgroundColor());
  }
  std::cout << "\u001b[u"; // Reload cursor pos
}

void CLMenu::show(Sensor * sensorToDisplay, UserConfig &config){
  std::cout << "\u001b[s"; // Save cursor pos
  // Graphic size 60 * 30
  clearMenu();
  if ( sensorToDisplay->getType().compare("camera") == 0 ){
    moveCursor(10 + 25 , 10 + 15);
    printColor("No image available",*config.getFontColor(),*config.getBackgroundColor());
  }
  else { 
    printGraphic(sensorToDisplay->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensorToDisplay->getValPerMin(),10,10,1);
  }
  // Prin id below
  moveCursor(10 + 30 , 10 + 35);
  printColor(sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  // Print side information
  moveCursor(100 , 25 + 0);
  printColor("Id: " + sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(100 , 25 + 2);
  printColor("Type: " + sensorToDisplay->getType(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(100 , 25 + 4);
  printColor("Area: " + sensorToDisplay->getArea(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(100 , 25 + 6);
  printColor("Magnitude: " + sensorToDisplay->getMagnitude(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(100 , 25 + 8);
  printColor("Values per minute: " + std::to_string(sensorToDisplay->getValPerMin()),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(100 , 25 + 10);
  printColor("Current state: ",*config.getFontColor(),*config.getBackgroundColor());
  if (sensorToDisplay->isActive()) printColor("On",{0,255,0},*config.getBackgroundColor());
  else printColor("Off",{255,0,0},*config.getBackgroundColor());

  std::cout << "\u001b[u"; // Reload cursor pos
}

void CLMenu::show(User &user){
  std::cout << "\u001b[s"; // Save cursor pos

  int xPadding = 20;
  int yPadding = 10;

  clearMenu();
  UserConfig *config = user.getConfiguration();
  std::array<int, 3> font = *config->getFontColor();
  std::array<int, 3> background = *config->getBackgroundColor();
  std::array<int, 3> graphic = *config->getGraphicColor();
  // Print side information
  moveCursor(xPadding - 2 , yPadding - 2);
  printColor("User info: ",font,background);

  moveCursor(xPadding , yPadding + 0);
  printColor("Name: " + user.getName(),font,background);
  
  moveCursor(xPadding , yPadding + 2);
  printColor("Employee number: " + user.getEmployeeNumber(),font,background);

  moveCursor(xPadding , yPadding + 4);
  printColor("NIF: " + user.getNIF(),font,background);

  moveCursor(xPadding , yPadding + 6);
  printColor("Last log time: " + user.getTimestamp(),font,background);

  moveCursor(xPadding , yPadding + 8);
  printColor("Admin permissions: ",font,background);
  if (user.hasAdminPermission()) printColor("True",font,background);
  else printColor("False",font,background);
  
  moveCursor(xPadding , yPadding + 10);
  printColor("Language: " + (*user.getConfiguration()).getlanguage(),font,background);

  moveCursor(xPadding , yPadding + 14);
  printColor("Themes configuration:",font,background);

  moveCursor(xPadding + 2 , yPadding + 16);
  printColor("- Font color (r,g,b): " + std::to_string(font[0]) + "," + std::to_string(font[1]) + "," + std::to_string(font[2]),font,background);

  moveCursor(xPadding + 2, yPadding + 18);
  printColor("- Background color (r,g,b): " + std::to_string(background[0]) + "," + std::to_string(background[1]) + "," + std::to_string(background[2]),font,background);

  moveCursor(xPadding  + 2, yPadding + 20);
  printColor("- Graphics color (r,g,b): " + std::to_string(graphic[0]) + "," + std::to_string(graphic[1]) + "," + std::to_string(graphic[2]),font,background);

  std::cout << "\u001b[u"; // Reload cursor pos
}


void CLMenu::clearMenu(){
  moveCursor(getTerminalWidth(),getTerminalHeight() - 12);
  std::cout << "\u001b[1J";
}