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
  // Minimum terminal size 100 x 50
  int minWidth = 100;
  int minHeight = 50;

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

  if (columns < minWidth) throw MinTerminalSize();

  system("tput lines > terminalSize.txt");
  terminalSize.open("terminalSize.txt");
  int lines = 0;
  
  if ( terminalSize.is_open() ) {
    while ( terminalSize ) {
      std::getline (terminalSize, line);
      lines = stoi(line);
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  terminalSize.close();
  terminalHeight = lines;

  if (lines < minHeight) throw MinTerminalSize();
};

int getTerminalWidth(){
  return terminalWidth;
}

int getTerminalHeight(){
  return terminalHeight;
}

void printColorFromFile(std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    printColor(line,frontColor,backColor);
    break; // Read only first line
    }
  }
  else {
    cleanScreen();
    std::cout << "Couldn't open " << fileName << "\n";
    exit(1);
  }
};

void printRightFromFile(std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    printRight(line,frontColor,backColor,padding);
    break; // Read only first line
    }
  }
  else {
    cleanScreen();
    std::cout << "Couldn't open " << fileName << "\n";
    exit(1);
  }
};

void printLeftFromFile(std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    printLeft(line,frontColor,backColor,padding);
    break; // Read only first line
    }
  }
  else {
    cleanScreen();
    std::cout << "Couldn't open " << fileName << "\n";
    exit(1);
  }
};

void printCenterFromFile(std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    printCenter(line,frontColor,backColor,padding);
    break; // Read only first line
    }
  }
  else {
    cleanScreen();
    std::cout << "Couldn't open " << fileName << "\n";
    exit(1);
  }
};

void printLogo(std::string fileName, std::array<int,3> frontColor, std::array<int,3> backColor){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    printCenter(line,frontColor,backColor);
    newLine();
    }
  }
  else {
    std::cout << "Couldn't open file\n";
    cleanScreen();
    exit(1);
  }
};


void printCenter(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::cout << "\u001b[" <<terminalWidth <<"D";
  std::cout << "\u001b[" << (terminalWidth-toPrint.size()-padding)/2 << "C";
  printColor(toPrint,frontColor,backColor);
}


void printRight(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::cout << "\u001b[" << terminalWidth <<"D";
  std::cout << "\u001b[" << terminalWidth - toPrint.size() - padding <<"C";
  printColor(toPrint,frontColor,backColor);
}


void printLeft(const std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor, const int padding){
  std::cout << "\u001b[" << terminalWidth << "D";
  std::cout << "\u001b[" << padding <<"C";
  printColor(toPrint,frontColor,backColor);
}

void printColor(std::string toPrint, std::array<int,3> frontColor, std::array<int,3> backColor){
  //std::cout << '\u001b[38;2;'<< color[0] <<';'<< color[1] <<';'<< color[2] <<'m' << toPrint << "\u001b[0m";
  std::cout << "\u001b[38;2;"<< frontColor[0] <<';'<< frontColor[1] <<';'<< frontColor[2] <<"m\u001b[48;2;"<< backColor[0] <<';'<< backColor[1] <<';'<< backColor[2] <<'m' << toPrint;
}

void startCustomTerminal(User &user, int terminalSize){
  moveCursor(0,terminalHeight - 1 - terminalSize);
  for (int i = 0; i < terminalWidth; i++) printColor("-",*user.getConfiguration()->getFontColor(),*user.getConfiguration()->getBackgroundColor());
  moveCursor((terminalWidth-11)/2,terminalHeight - 1 - terminalSize);
  printColorFromFile("config/LANG/" + user.getConfiguration()->getLanguage() + "/commands/terminalHeader.txt", *user.getConfiguration()->getFontColor(),*user.getConfiguration()->getBackgroundColor());
  moveCursor(0,terminalHeight - terminalSize);
}

void clearCustomTerminal(User &user, int terminalSize){
  std::cout << "\u001b[" << terminalHeight - terminalSize - 1 << ";0H" << "\u001b[0J";
  startCustomTerminal(user,10);
}

void cleanScreen(std::array<int,3> backColor){
  system("clear");
  printColor("\u001b[2J",{0,0,0},backColor);
  moveCursor(0,0);
}
void cleanScreen(){
  system("clear");
  std::cout << "\u001b[0m\u001b[2J";
  moveCursor(0,0);
}

void moveCursor(int posX, int posY){
  std::cout << "\u001b[" << posY << ";" << posX << "H";
}

void newLine(int lines){
  for(int i = 0; i < lines; i++) std::cout << "\n";
}

void reloadCursorPos(){
  std::cout << "\u001b[u";
}

void saveCursorPos(){
  std::cout << "\u001b[s";
}

std::vector<std::string> newCommand(User & user, std::string currentSensor){
  printColor(user.getName() + "@jveh" + ":~",*user.getConfiguration()->getFontColor(),*user.getConfiguration()->getBackgroundColor());
  if (currentSensor.compare("..") != 0) std::cout << "/" << currentSensor;
  printColor("> ",*user.getConfiguration()->getFontColor(),*user.getConfiguration()->getBackgroundColor());

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

void printGraphic(const std::vector<int> data, std::array<int,3> frontColor, std::array<int,3> backColor, std::array<int,3> pointColor, int valPerY, int posX, int posY, int scale){
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
      printColor(std::to_string(maxY - (axisYvalue * (lineY / stepY) )),frontColor,backColor);
      moveCursor(posX + spacing, posY + lineY);
      printColor("+",frontColor,backColor);
    }
    else {
      printColor("   |",frontColor,backColor);
    }
  }

  // Bottom line
  moveCursor(posX - 2 + spacing + 1, posY + rangeY + 1);
  printColor(std::to_string(- maxX ),frontColor,backColor);
  moveCursor(posX + spacing + 1, posY + rangeY);

  for ( int lineX = 1; lineX <= rangeX; lineX++) {
    if (lineX % stepX == 0){
      printColor("+",frontColor,backColor);
      moveCursor(posX + lineX - 2 + spacing + 1, posY + rangeY + 1);
      printColor(std::to_string((lineX * scale) - maxX),frontColor,backColor);
      moveCursor(posX + lineX + spacing + 1, posY + rangeY);
    }
    else {
      printColor("-",frontColor,backColor);
    }
  }

  // Set points on the plot with user color
  int startX = posX + 1 + spacing;
  int pointY = 0;

  for (int point = 0; point < data.size(); point+=scale * valPerY){
    pointY = 0;
    for (int value = 0; value < scale * valPerY; value++) {
      pointY += posY + (maxY - data[point + value]) / (axisYvalue / stepY);
    }
    moveCursor(startX + (rangeX - (data.size()/(scale * valPerY))) + point / (scale * valPerY), pointY / (scale * valPerY));
    printColor("·",pointColor,backColor) ;
  }
  
  printColor("",frontColor,backColor); // Turn of color
}