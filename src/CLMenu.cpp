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
  saveCursorPos(); // Save cursor pos
  if (sensors.size() == 0) return;
  // TODO: add local config
  int graphicsInX = 3;
  int graphicsInY = 2;
  // Graphic size 30 * 15
  int positionsX = getTerminalWidth() / graphicsInX;
  int positionsY = ( getTerminalHeight() / graphicsInY ) - 5;
  clearMenu();
  for (int index = 0; index < sensors.size(); index++){
    if ( sensors[index]->getType().compare("camera") == 0 ){
      moveCursor(positionsX * (index % graphicsInX) + 10 + 8 , positionsY * (index / graphicsInX) + 5 + 7);
      printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/noImage.txt", *config.getFontColor(),*config.getBackgroundColor());
    } else {
      printGraphic(sensors[index]->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensors[index]->getValPerMin(),positionsX * (index % graphicsInX) + 10, positionsY * (index / graphicsInX) + 5,2);
    }
    // Print id below

    moveCursor(positionsX * (index % graphicsInX) + 10 + 16 , positionsY * (index / graphicsInX) + 5 + 18);
    printColor(sensors[index]->getId(),*config.getFontColor(),*config.getBackgroundColor());
  }
  reloadCursorPos(); // Reload cursor pos
}

void CLMenu::show(Sensor * sensorToDisplay, UserConfig &config){
  saveCursorPos(); // Save cursor pos

  // Graphic size 60 * 30
  clearMenu();
  if ( sensorToDisplay->getType().compare("camera") == 0 ){
    moveCursor(10 + 25 , 10 + 15);
    printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/noImage.txt", *config.getFontColor(),*config.getBackgroundColor());
  }
  else { 
    printGraphic(sensorToDisplay->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensorToDisplay->getValPerMin(),10,10,1);
  }
  // Prin id below
  moveCursor(10 + 30 , 10 + 35);
  printColor(sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  int xPadding = 100;
  int yPadding = 25;
  // Print side information
  moveCursor(xPadding , yPadding + 0);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/idTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(xPadding , yPadding + 2);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/typeTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getType(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(xPadding , yPadding + 4);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/areaTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getArea(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(xPadding , yPadding + 6);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/magnitudeTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getMagnitude(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(xPadding , yPadding + 8);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/valPerMinTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(std::to_string(sensorToDisplay->getValPerMin()),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(xPadding , yPadding + 10);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/stateTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  if (sensorToDisplay->isActive()) printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/onTag.txt", {0,255,0},*config.getBackgroundColor());
  else printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/offTag.txt", {255,0,0},*config.getBackgroundColor()); // TODO: add font color here
  
  reloadCursorPos(); // Reload cursor pos
}

void CLMenu::show(User &user){
  saveCursorPos(); // Save cursor pos

  int xPadding = 20;
  int yPadding = 10;

  clearMenu();
  UserConfig *config = user.getConfiguration();
  std::string lang = config->getLanguage();
  std::array<int, 3> font = *config->getFontColor();
  std::array<int, 3> background = *config->getBackgroundColor();
  std::array<int, 3> graphic = *config->getGraphicColor();
  // Print side information
  moveCursor(xPadding - 2 , yPadding - 2);
  printColorFromFile("config/LANG/" + lang + "/user/userHeader.txt", font,background);

  moveCursor(xPadding , yPadding + 0);
  printColorFromFile("config/LANG/" + lang + "/user/nameTag.txt", font,background);
  printColor(user.getName(),font,background);
  
  moveCursor(xPadding , yPadding + 2);
  printColorFromFile("config/LANG/" + lang + "/user/numberTag.txt", font,background);
  printColor(user.getEmployeeNumber(),font,background);

  moveCursor(xPadding , yPadding + 4);
  printColorFromFile("config/LANG/" + lang + "/user/nifTag.txt", font,background);
  printColor(user.getNIF(),font,background);

  moveCursor(xPadding , yPadding + 6);
  printColorFromFile("config/LANG/" + lang + "/user/logTag.txt", font,background);
  printColor(user.getTimestamp(),font,background);

  moveCursor(xPadding , yPadding + 8);
  printColorFromFile("config/LANG/" + lang + "/user/permissionTag.txt", font,background);
  if (user.hasAdminPermission()) printColorFromFile("config/LANG/" + lang + "/user/hasPermissTag.txt", font,background);
  else printColorFromFile("config/LANG/" + lang + "/user/notPermissTag.txt", font,background);
  
  moveCursor(xPadding , yPadding + 10);
  printColorFromFile("config/LANG/" + lang + "/user/langTag.txt", font,background);
  printColor((*user.getConfiguration()).getLanguage(),font,background);

  moveCursor(xPadding , yPadding + 14);
  printColorFromFile("config/LANG/" + lang + "/user/themesHeader.txt", font,background);

  moveCursor(xPadding + 2 , yPadding + 16);
  printColorFromFile("config/LANG/" + lang + "/user/fontTag.txt", font,background);
  printColor(std::to_string(font[0]) + "," + std::to_string(font[1]) + "," + std::to_string(font[2]),font,background);

  moveCursor(xPadding + 2, yPadding + 18);
  printColorFromFile("config/LANG/" + lang + "/user/backgroundTag.txt", font,background);
  printColor(std::to_string(background[0]) + "," + std::to_string(background[1]) + "," + std::to_string(background[2]),font,background);

  moveCursor(xPadding  + 2, yPadding + 20);
  printColorFromFile("config/LANG/" + lang + "/user/graphTag.txt", font,background);
  printColor(std::to_string(graphic[0]) + "," + std::to_string(graphic[1]) + "," + std::to_string(graphic[2]),font,background);

  reloadCursorPos(); // Reload cursor pos
}


void CLMenu::clearMenu(){
  moveCursor(getTerminalWidth(),getTerminalHeight() - 12);
  std::cout << "\u001b[1J";
}