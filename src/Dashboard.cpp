/**
 * @file Dashboard.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Dashboard.h"
#include "CLDashboard.h"


Dashboard::Dashboard(const User &user){
  this->user = user;
  this->allowedToExit = true;
  this->currentSensor = nullptr;
  Sensor *sensor1 = Sensor::Create("thermometer");
  Sensor *sensor2 = Sensor::Create("humidity");
  Sensor *sensor3 = Sensor::Create("humidity");
  Sensor *sensor4 = Sensor::Create("airquality");
  Sensor *sensor5 = Sensor::Create("moisture");
  Sensor *sensor6 = Sensor::Create("rgbcamera");
  Sensor *sensor7 = Sensor::Create("bwcamera");
  this->sensor.push_back(sensor1);
  this->sensor.push_back(sensor2);
  this->sensor.push_back(sensor3);
  this->sensor.push_back(sensor4);
  this->sensor.push_back(sensor5);
  this->sensor.push_back(sensor6);
  this->sensor.push_back(sensor7);
  addToMainMenu(); 
}


Dashboard *Dashboard::Create(const User &user, const std::string type){
  if (type == "CLI"){
    return new CLDashboard(user);
  }
  else {
    throw std::runtime_error(type + " is not a defined Dashboard type");
    std::exit(1);
  }
};

bool Dashboard::changeInterface(std::string newInterface){
  
  if (newInterface.compare("..") == 0){
    if (this->mainMenuIndex + 1 > this->mainMenu.size()) moveWindowMainMenu(-1) ;
    this->currentSensor = nullptr;
    this->menu->show(this->mainMenu[this->mainMenuIndex]);
    std::string menuName = std::to_string(this->mainMenuIndex + 1)  + "/" + std::to_string(this->mainMenu.size());
    this->menuBar->setCurrentMenu(menuName);
    this->menuBar->show();
    this->lastInterface = this->currentInterface;
    this->currentInterface = newInterface;
    return true;
  }
  else if (this->currentInterface.compare(newInterface) == 0){
        this->menu->show(this->currentSensor);
        this->menuBar->setCurrentMenu(this->currentInterface);
        return true;
  }
  else {
    for (Sensor *sensor: this->sensor){
      if (newInterface.compare(sensor->getId())== 0){
        this->currentSensor = sensor;
        this->menu->show(this->currentSensor);
        this->menuBar->setCurrentMenu(newInterface);
        this->menuBar->show();
        this->lastInterface = this->currentInterface;
        this->currentInterface = newInterface;
        return true;
      }
    }
    return false;
  }
}

void Dashboard::addToMainMenu(Sensor *sensor){
  std::vector<Sensor *> tmp;
  if (this->mainMenu.back().size() < 6) {
    tmp = this->mainMenu.back();
    this->mainMenu.pop_back();
  }
  tmp.push_back(sensor);

  //Readding the new sensor
  this->sensor.push_back(sensor);
  this->mainMenu.push_back(tmp);
}

void Dashboard::addToMainMenu(){
  std::vector<Sensor *> tmp;
  int nSensorWindow = 6;
  int sensorsToAdd = this->sensor.size();
  for (int windows = 0; windows < ((sensorsToAdd - 1)/ 6) + 1; windows++){
    tmp.clear();
    if ( sensorsToAdd / (6*(windows+1)) == 0) nSensorWindow = sensorsToAdd - (6 * windows) ;
    for (int nSensor = 0; nSensor < nSensorWindow; nSensor++) {
      tmp.push_back(this->sensor[nSensor + (windows * 6)]);
    }
    this->mainMenu.push_back(tmp);
  }
}

void Dashboard::addNewSensor(std::string type){
  Sensor *sensor = Sensor::Create(type);;
  addToMainMenu(sensor);
}

void Dashboard::deleteSensor(std::string id){
  // Check if we are going to delete the last sensor
  if (this->sensor.size() == 1) return;
  // Check if we are going to delete the currentSensor
  if (this->currentSensor != nullptr){
    if (id.compare(this->currentSensor->getId())== 0){
      return;
    }
  }
  // Clear main menu
  this->mainMenu.clear();
  // Remove from sensor vector
  for (int index = 0; index < this->sensor.size(); index++){
    if (id.compare(this->sensor[index]->getId())== 0){
      Sensor *sensor = this->sensor[index];
      this->sensor.erase(this->sensor.begin() + index);
      delete sensor;
    }
  }
  // Reset main menu
  addToMainMenu();
}


void Dashboard::moveWindowMainMenu(int n){
  if (this->mainMenuIndex + n < 0) return;
  if (this->mainMenuIndex + n >= this->mainMenu.size()) return;
  this->mainMenuIndex += n;
}

void Dashboard::changeCurrentSensorInfo(std::string toChange, std::string newValue){

  if (this->currentInterface.compare("..") == 0) return;

  if (toChange.compare("area") == 0) this->currentSensor->setArea(newValue);
  else if (toChange.compare("val") == 0){
    try {
      std::stoi(newValue);
      this->currentSensor->setValPerMin(std::stoi(newValue)); // Placeholder
    }
    catch(const std::exception & e)
    {
      return;
    }
    
  }
  else if (toChange.compare("state") == 0){

    if (newValue.compare("on") == 0) this->currentSensor->setActive(true);
    else if (newValue.compare("off") == 0) this->currentSensor->setActive(false);
    else return;
  }
  this->changeInterface(this->currentInterface);
}


void Dashboard::cleanSensor(){
  for (Sensor * sensor : this->sensor){
    delete sensor;
  }
}


void Dashboard::exit(){
  cleanSensor();
  this->allowedToExit = true;
}

void Dashboard::logout(){
  cleanSensor();
  this->allowedToExit = false;
}

bool Dashboard::canExit(){
  return this->allowedToExit;
}

Dashboard::~Dashboard(){}