/**
 * @file Sensor.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Sensor.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <array>
#include <stdexcept>

#ifndef SENSOR_H 
#define	SENSOR_H
class Sensor{
public:
  static std::array<std::string,6> availableTypesId;
  static std::array<std::string,6> availableTypes;
  /**
  * @brief Creates an instance of the sensor type
  * 
  * @param type 
  * @return Sensor* 
  */
  static Sensor *Create(const std::string type);

  /**
  * @brief Construct a new Sensor:: Sensor object
  * 
  * @param id Identification of type and number
  * @param type Type of sensor
  * @param magnitude Data values magnitude
  * @param active Sensor is On/Off
  * @param valPerMin Number of values per min
  */
  Sensor( std::string id = "", std::string type = "none", std::string magnitude = "-", bool active = true, int valPerMin = 1); /* default constructor */

  void setId(std::string newId);
  std::string getId(){return id; };

  void setType(std::string newType);
  std::string getType(){return type;};

  void setArea(std::string);
  std::string getArea(){return area;};

  void setMagnitude(std::string magnitude);
  std::string getMagnitude(){return magnitude;};

  void setActive(bool);
  bool isActive(){return active;};

  void setValPerMin(int valPerMin);
  int getValPerMin(){return valPerMin;};

  /**
   * @brief Request data from sensor
   * 
   * @return std::vector<int> 
   */
  virtual std::array<int,60> requestData() = 0;
  virtual ~Sensor();

protected:
  char id [11];
  char type [21];
  char area [21];
  char magnitude [11];
  bool active;
  int valPerMin;
  //std::array<int,60> data = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10}; // TODO: placeholder
  // TODO: placeholder
  void addNewData(int);
  void removeOldData(int);
};

#endif