/**
 * @file CLIUtils.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLIUtils.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <array>

void setTerminalSize();
int getTerminalWidth();
int getTerminalHeight();

/**
 * @brief Print the contents of the file in the center
 * 
 * @param fileName 
 * @param frontColor 
 * @param backColor 
 */
void printCenterFromFile(const std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor);
/**
 * @brief Print the string in the center
 * 
 * @param toPrint 
 * @param frontColor 
 * @param backColor 
 * @param padding 
 */
void printCenter(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding = 0 );

void printRight(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding = 0 );

void printLeft(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding = 0);

/**
 * @brief Print the string to the terminal in the given color
 * 
 * @param toPrint 
 * @param frontColor 
 * @param backColor 
 */
void printColor(std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor);

void startCustomTerminal(int);
std::vector<std::string> newCommand(User & user,std::string = "");
void clearCustomTerminal(int);

void moveCursor(int posX, int posY);
void printGraphic(const std::vector<int> data, std::array<int,3> frontColor, std::array<int,3> backColor, std::array<int,3> pointColor
  , int valPerY = 1, int posX = 10, int posY = 10, int scale = 1);