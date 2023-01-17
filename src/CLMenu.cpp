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

  // Size used 35 * 20
  // Graphic size 30 * 15
  int sensorX = 35;
  int sensorY = 20;

  // Calculate number of sensors per menu horizontal
  int availableSizeX = getTerminalWidth();
  int graphicsInX = availableSizeX / sensorX;
  graphicsInX  = (graphicsInX < 3 ? graphicsInX : 3);

  int paddingX = (availableSizeX/graphicsInX) - sensorX ;
  int paddingXRight =  paddingX / 2;

  int positionsX = sensorX + paddingX;

  // Calculate number of sensors per menu vertical
  int terminalSizeY = 11;
  int menuBarSizeY = 2;
  int availableSizeY = getTerminalHeight() - terminalSizeY - menuBarSizeY;
  int graphicsInY = availableSizeY / sensorY;
  graphicsInY  = (graphicsInY < 2 ? graphicsInY : 2);

  int paddingY = (availableSizeY/graphicsInY) - sensorY ;
  int paddingYTop = menuBarSizeY + paddingY / 2;

  int positionsY = sensorY + paddingY;


  clearMenu();
  for (int index = 0; index < sensors.size(); index++){
    if ( sensors[index]->getType().compare("camera") == 0 ){
      moveCursor(positionsX * (index % graphicsInX) + paddingXRight + 8 , positionsY * (index / graphicsInX) + paddingYTop + 7);
      printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/noImage.txt", *config.getFontColor(),*config.getBackgroundColor());
    } else {
      printGraphic(sensors[index]->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensors[index]->getValPerMin(),positionsX * (index % graphicsInX) + paddingXRight, positionsY * (index / graphicsInX) + paddingYTop,2);
    }
    // Print id below

    moveCursor(positionsX * (index % graphicsInX) + paddingXRight + 16 , positionsY * (index / graphicsInX) + paddingYTop + 18);
    printColor(sensors[index]->getId(),*config.getFontColor(),*config.getBackgroundColor());
  }
  reloadCursorPos(); // Reload cursor pos
}

void CLMenu::show(Sensor * sensorToDisplay, UserConfig &config){
  saveCursorPos(); // Save cursor pos

  // Info size 30 * 15

  int infoSensorX = 30;
  int infoSensorY = 15;

  // Sensor size used 65 * 35
  // Graphic size 60 * 30

  int sensorX = 65;
  int sensorY = 35;

  // Calculate number of sensors per menu horizontal
  int availableSizeX = getTerminalWidth();

  int paddingX = availableSizeX - sensorX - infoSensorX;
  paddingX  = (paddingX < 25 ? paddingX : 25); // Max padding 25
  int paddingXRight =  paddingX / 2;
  int paddingXSensor = paddingX + sensorX;

  // Calculate number of sensors per menu vertical
  int terminalSizeY = 11;
  int menuBarSizeY = 2;
  int availableSizeY = getTerminalHeight() - terminalSizeY - menuBarSizeY;

  int paddingY = availableSizeY - sensorY ;
  int paddingYTop = menuBarSizeY + paddingY / 2;
  int paddingYSensor = (menuBarSizeY + (availableSizeY - infoSensorY))/2;

  clearMenu();
  if ( sensorToDisplay->getType().compare("camera") == 0 ){
    moveCursor(paddingXRight + 25 , paddingYTop + 15);
    printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/noImage.txt", *config.getFontColor(),*config.getBackgroundColor());
  }
  else { 
    printGraphic(sensorToDisplay->requestData(),*config.getFontColor(),*config.getBackgroundColor(),*config.getGraphicColor(),sensorToDisplay->getValPerMin(),paddingXRight,paddingYTop,1);
  }
  // Prin id below
  moveCursor(paddingXRight + 30 , paddingYTop + 33);
  printColor(sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  // Print side information
  moveCursor(paddingXSensor , paddingYSensor + 0);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/idTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getId(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(paddingXSensor , paddingYSensor + 2);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/typeTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getType(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(paddingXSensor , paddingYSensor + 4);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/areaTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getArea(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(paddingXSensor , paddingYSensor + 6);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/magnitudeTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(sensorToDisplay->getMagnitude(),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(paddingXSensor , paddingYSensor + 8);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/valPerMinTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  printColor(std::to_string(sensorToDisplay->getValPerMin()),*config.getFontColor(),*config.getBackgroundColor());

  moveCursor(paddingXSensor , paddingYSensor + 10);
  printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/stateTag.txt", *config.getFontColor(),*config.getBackgroundColor());
  if (sensorToDisplay->isActive()) printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/onTag.txt", {0,255,0},*config.getBackgroundColor());
  else printColorFromFile("config/LANG/" + config.getLanguage() + "/sensor/offTag.txt", {255,0,0},*config.getBackgroundColor());
  
  reloadCursorPos(); // Reload cursor pos
}

void CLMenu::show(User &user){
  saveCursorPos(); // Save cursor pos

  // Info size 30 * 25

  int infoX = 30;
  int infoY = 25;

  // Calculate number of sensors per menu horizontal
  int availableSizeX = getTerminalWidth();

  int paddingX = (availableSizeX - infoX) / 2;
  paddingX  = (paddingX < 15 ? paddingX : 15); // Max padding 15

  // Calculate number of sensors per menu vertical
  int terminalSizeY = 11;
  int menuBarSizeY = 2;
  int availableSizeY = getTerminalHeight() - terminalSizeY - menuBarSizeY;

  int paddingY = ((availableSizeY - infoY)/2) + menuBarSizeY;
  paddingY  = (paddingY < 10 ? paddingY : 10); // Max padding 10

  clearMenu();
  UserConfig *config = user.getConfiguration();
  std::string lang = config->getLanguage();
  std::array<int, 3> font = *config->getFontColor();
  std::array<int, 3> background = *config->getBackgroundColor();
  std::array<int, 3> graphic = *config->getGraphicColor();
  // Print side information
  moveCursor(paddingX , paddingY - 2);
  printColorFromFile("config/LANG/" + lang + "/user/userHeader.txt", font,background);

  moveCursor(paddingX + 2, paddingY + 0);
  printColorFromFile("config/LANG/" + lang + "/user/nameTag.txt", font,background);
  printColor(user.getName(),font,background);
  
  moveCursor(paddingX + 2, paddingY + 2);
  printColorFromFile("config/LANG/" + lang + "/user/numberTag.txt", font,background);
  printColor(user.getEmployeeNumber(),font,background);

  moveCursor(paddingX + 2, paddingY + 4);
  printColorFromFile("config/LANG/" + lang + "/user/nifTag.txt", font,background);
  printColor(user.getNIF(),font,background);

  moveCursor(paddingX + 2, paddingY + 6);
  printColorFromFile("config/LANG/" + lang + "/user/logTag.txt", font,background);
  printColor(user.getTimestamp(),font,background);

  moveCursor(paddingX + 2, paddingY + 8);
  printColorFromFile("config/LANG/" + lang + "/user/permissionTag.txt", font,background);
  if (user.hasAdminPermission()) printColorFromFile("config/LANG/" + lang + "/user/hasPermissTag.txt", font,background);
  else printColorFromFile("config/LANG/" + lang + "/user/notPermissTag.txt", font,background);
  
  moveCursor(paddingX + 2, paddingY + 10);
  printColorFromFile("config/LANG/" + lang + "/user/langTag.txt", font,background);
  printColor((*user.getConfiguration()).getLanguage(),font,background);

  moveCursor(paddingX + 2 , paddingY + 14);
  printColorFromFile("config/LANG/" + lang + "/user/themesHeader.txt", font,background);

  moveCursor(paddingX + 4 , paddingY + 16);
  printColorFromFile("config/LANG/" + lang + "/user/fontTag.txt", font,background);
  printColor(std::to_string(font[0]) + "," + std::to_string(font[1]) + "," + std::to_string(font[2]),font,background);

  moveCursor(paddingX + 4, paddingY + 18);
  printColorFromFile("config/LANG/" + lang + "/user/backgroundTag.txt", font,background);
  printColor(std::to_string(background[0]) + "," + std::to_string(background[1]) + "," + std::to_string(background[2]),font,background);

  moveCursor(paddingX  + 4, paddingY + 20);
  printColorFromFile("config/LANG/" + lang + "/user/graphTag.txt", font,background);
  printColor(std::to_string(graphic[0]) + "," + std::to_string(graphic[1]) + "," + std::to_string(graphic[2]),font,background);

  reloadCursorPos(); // Reload cursor pos
}


void CLMenu::clearMenu(){
  moveCursor(getTerminalWidth(),getTerminalHeight() - 12);
  std::cout << "\u001b[1J";
}