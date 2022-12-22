/**
 * @file CLIUtils.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLIUtils.h"

int terminalWidth;
int terminalHeight;

void setTerminalSize(){
  system("tput cols > terminalSize.txt"); /* For height it is tput lines*/
  std::ifstream terminalSize;
  terminalSize.open("terminalSize.txt");
  std::string line;
  int columns = 0;
  
  if ( terminalSize.is_open() ) {
    while ( terminalSize ) {
      std::getline (terminalSize, line);
      columns = stoi(line);
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  terminalSize.close();
  terminalWidth = columns;

  system("tput lines > terminalSize.txt");
  terminalSize.open("terminalSize.txt");
  int lines = 0;
  
  if ( terminalSize.is_open() ) {
    while ( terminalSize ) { // equivalent to myfile.good()
      std::getline (terminalSize, line);
      lines = stoi(line);
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  terminalHeight = lines;
};

int getTerminalWidth(){
  return terminalWidth;
}

int getTerminalHeight(){
  return terminalHeight;
}

void printCenterFromFile(std::string fileName, std::string color){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    std::cout << std::setw((terminalWidth-line.size())/2);
    printColor(line,color);
    std::cout << "\n";
    }
  }
  else {
  std::cout << "Couldn't open file\n";
  }
};

void printCenter(const std::string toPrint, const int padding){
  std::cout << "\u001b[" <<terminalWidth <<"D";
  std::cout << "\u001b[" << (terminalWidth-toPrint.size()-padding)/2 << "C";
  std::cout << toPrint;
}

void printCenter(const std::string toPrint, const std::string color, const int padding){
  std::cout << "\u001b[" <<terminalWidth <<"D";
  std::cout << "\u001b[" << (terminalWidth-toPrint.size()-padding)/2 << "C";
  printColor(toPrint,color);
}

void printRight(const std::string toPrint, const int padding){
  std::cout << "\u001b[" << terminalWidth <<"D";
  std::cout << "\u001b[" << terminalWidth - toPrint.size() - padding <<"C";
  std::cout << toPrint;
}

void printRight(const std::string toPrint, const std::string color, const int padding){
  std::cout << "\u001b[" << terminalWidth <<"D";
  std::cout << "\u001b[" << terminalWidth - toPrint.size() - padding <<"C";
  printColor(toPrint,color);
}

void printLeft(const std::string toPrint, const int padding){
  std::cout << "\u001b[" << terminalWidth << "D";
  std::cout << "\u001b[" << padding <<"C";
  std::cout << toPrint;
}

void printLeft(const std::string toPrint, const std::string color, const int padding){
  std::cout << "\u001b[" << terminalWidth << "D";
  std::cout << "\u001b[" << padding <<"C";
  printColor(toPrint,color);
}

void printColor(std::string toPrint, std::string color){
  std::string colorCode = setColor(color);
  std::string noColor = "\u001b[0m";
  std::cout << colorCode << toPrint << noColor;
}

std::string setColor(std::string color){
  if (color.compare("grey") == 0) return "\u001b[1;30m";
  if (color.compare("red") == 0) return "\u001b[1;31m";
  if (color.compare("green") == 0) return "\u001b[1;32m";
  if (color.compare("yellow") == 0) return "\u001b[1;33m";
  if (color.compare("blue") == 0) return "\u001b[1;34m";
  if (color.compare("purple") == 0) return "\u001b[1;35m";
  if (color.compare("cyan") == 0) return "\u001b[1;36m";
  if (color.compare("white") == 0) return "\u001b[1;37m";
  return "\u001b[0m";
}

void startCustomTerminal(int terminalSize){
  std::cout << "\u001b[" << terminalHeight - 1 - terminalSize << ";0H";
  std::cout << std::setfill('-')<<std::setw(terminalWidth) << "" << std::setfill(' ');
  std::cout << "\u001b[" << terminalHeight - 1 - terminalSize << ";" << (terminalWidth-11)/2 << "H" << " Terminal ";
  std::cout << "\u001b[" << terminalHeight - terminalSize << ";0H";
}

void clearCustomTerminal(int terminalSize){
  std::cout << "\u001b[" << terminalHeight - terminalSize << ";0H" << "\u001b[0J";
}

void moveCursor(int posX, int posY){
  std::cout << "\u001b[" << posY << ";" << posX << "H";
}

std::vector<std::string> newCommand(User & user, std::string currentSensor){
  std::cout << user.getName() << "@jveh"<< ":~";
  if (currentSensor.compare("..") != 0) std::cout << "/" << currentSensor;
  std::cout << "> ";

  char input[100] = {0};
  std::cin.getline(input,100);
  std::string inputString = input;

  std::string tmp;
  std::stringstream ss(inputString);
  std::vector<std::string> separatedInput;

  while(getline(ss, tmp, ' ')){
      separatedInput.push_back(tmp);
  }

  return separatedInput;
}

void printGraphic(const std::vector <int> &data, int valPerY, int posX, int posY, int scale){
  const int spacing = 3;
  // Graphic standard size 60 * 30
  const int maxRangeX = 60;
  const int maxRangeY = 30;

  const int stepX = 5;
  const int stepY = 3;

  const int maxX = maxRangeX;

  const int rangeX = maxRangeX / scale;
  const int rangeY = maxRangeY / scale;

  int maxY = * max_element(data.begin(), data.end());
  if (maxY != 0) maxY = ((maxY / 10) + 1) * 10;

  int minY = * min_element(data.begin(), data.end());
  if (minY != 0) minY = ((minY / 10) - 1) * 10;
  
  if ((maxY - minY) / (rangeY / stepY) % stepY == 2) maxY += 10; 
  else if ((maxY - minY) / (rangeY / stepY) % stepY == 1){
    maxY += 10; 
    minY -= 10;
  }

  const int axisYvalue = (maxY - minY) / (rangeY / stepY);

  for (int lineY = 0; lineY <= rangeY; lineY++) {
    moveCursor(posX, posY + lineY);
    if (lineY % stepY == 0) {
      std::cout << maxY - (axisYvalue * (lineY / stepY) );
      moveCursor(posX + spacing, posY + lineY);
      std::cout << "+";
    }
    else {
      std::cout << "   |";
    }
  }

  // Bottom line
  moveCursor(posX - 2 + spacing + 1, posY + rangeY + 1);
  std::cout << - maxX;
  moveCursor(posX + spacing + 1, posY + rangeY);

  for ( int lineX = 1; lineX <= rangeX; lineX++) {
    if (lineX % stepX == 0){
      std::cout << "+";
      moveCursor(posX + lineX - 2 + spacing + 1, posY + rangeY + 1);
      std::cout << (lineX * scale) - maxX;
      moveCursor(posX + lineX + spacing + 1, posY + rangeY);
    }
    else {
      std::cout << "-";
    }
  }

  // Set points on the plot with red color
  std::cout << "\u001b[1;31m";
  int endX = posX + 1 + spacing + rangeX;
  int pointY = 0;

  for (int point = 0; point < data.size(); point+=scale * valPerY){
    pointY = 0;
    for (int value = 0; value < scale * valPerY; value++) {
      pointY += posY + (maxY - data[point + value]) / (axisYvalue / stepY);
    }
    moveCursor(endX - point / (scale * valPerY), pointY / (scale * valPerY));
    std::cout << "·" ;
  }
  
  std::cout << "\u001b[0m"; // Turn of color
}