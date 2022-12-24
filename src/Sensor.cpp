/**
 * @file Sensor.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"
#include "Thermometer.h"
#include "Humidity.h"
#include "Moisture.h"
#include "AirQuality.h"
#include "CameraBW.h"
#include "CameraRGB.h"

std::array<std::string,6> Sensor::availableTypesId = {"therm","hum","airqual","bwcam","rgbcam","moist"};
std::array<std::string,6> Sensor::availableTypes = {"thermometer","humidity","airquality","bwcamera","rgbcamera","moisture"};

/**
 * @brief Creates an instance of the sensor type
 * 
 * @param type 
 * @return Sensor* 
 */
Sensor *Sensor::Create(std::string type){
  if (type == "thermometer"){
    return new Thermometer;
  }
  else if (type == "humidity"){
    return new Humidity;
  }
  else if (type == "moisture"){
    return new Moisture;
  }
  else if (type == "airquality"){
    return new AirQuality;
  }
  else if (type == "bwcamera"){
    return new CameraBW;
  }
  else if (type == "rgbcamera"){
    return new CameraRGB;
  }
  else {
    throw std::runtime_error(type + " is not a defined sensor type");
    std::exit(1);
  }
};

Sensor::Sensor(std::string id, std::string type, std::string magnitude, bool active, int valPerMin){
  setId(id);
  setType(type);
  setArea("none");
  setMagnitude(magnitude);
  setActive(active);
  setValPerMin(valPerMin);
  // Create the sensor data server folder for each sensor
  if (!std::filesystem::is_directory("server/sensor/"+getId()) || !std::filesystem::exists("server/sensor/"+getId())) { // Check if folder exists
    std::filesystem::create_directory("server/sensor/"+getId()); // create folder
  } 
}

void Sensor::setId(std::string newId){
  int length = newId.size();
  length = (length < 11 ? length : 10);
  newId.copy (id, length);
  id [length] = '\0';
};

void Sensor::setType(std::string newType){
  int length = newType.size();
  length = (length < 21 ? length : 20);
  newType.copy (type, length);
  type [length] = '\0';
};

void Sensor::setArea(std::string newArea){
  int length = newArea.size();
  length = (length < 21 ? length : 20);
  newArea.copy (area, length);
  area [length] = '\0';
}

void Sensor::setMagnitude(std::string newMagnitude){
  int length = newMagnitude.size();
  length = (length < 11 ? length : 10);
  newMagnitude.copy (magnitude, length);
  magnitude [length] = '\0';
}

void Sensor::setActive(bool active){
  this->active = active;
}

void Sensor::setValPerMin(int valPerMin){
  valPerMin = (valPerMin > 0 ? valPerMin : 1); 
  this->valPerMin = valPerMin;
}

std::vector<int> Sensor::requestData(){

  // 1º load data from server file
  std::ifstream dataFile;
  dataFile.open("server/sensor/"+getId()+"/data.csv");

  if (!dataFile){
    // 0º Create file if it doesn't exist
    std::ofstream {"server/sensor/"+getId()+"/data.csv" };
    dataFile.open("server/sensor/"+getId()+"/data.csv");
  }

  std::vector<int> data;
  std::string line;
  
  if ( dataFile.is_open() ) {
    while ( dataFile ) {
      std::getline (dataFile, line);
      std::stringstream ss(line);
      std::string val;
      while(getline(ss, val, ',')){
        // 2º store data in temporary vector
        data.push_back(std::stoi(val));
      }
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  dataFile.close();
  // 3º remove old excess data and add new data
  // 3.1 Create new data
  int valueRange;
  if (data.size() > 0){
    int maxVal = * max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 10;
    int minVal = * min_element(data.begin(), data.end());
    if (minVal == 0) minVal = -10;
    valueRange = maxVal - minVal;
    if (valueRange == 0) valueRange = maxVal;
  } else {
    valueRange = 100;
  }
  int newVal = rand() % valueRange;
  data.push_back(newVal);
  // 3.2 Remove excess data
  int length = data.size();
  int dataToRemove = length - 60 * valPerMin;
  if (dataToRemove > 0){
    data.erase (data.begin(),data.begin()+dataToRemove);
  } 
  // 4º store data again in server file
  std::ofstream outDataFile ("server/sensor/"+getId()+"/data.csv", std::ios::out); // open file

  if (!outDataFile) { // file couldn't be opened
    std::cerr << "File could not be opened" << std::endl;
    exit (1);
  }

  for (int &value : data){
    outDataFile << value << ",";
  }
  
  return data;
}

Sensor::~Sensor(){};