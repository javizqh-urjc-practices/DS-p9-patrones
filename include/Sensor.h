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
#include <stdexcept>

#ifndef SENSOR_H 
#define	SENSOR_H
class Sensor{
public:
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
  Sensor( std::string id = "0000", std::string type = "none", std::string magnitude = "-", bool active = true, int valPerMin = 1); /* default constructor */
  /**
  * @brief Returns the sensor id
  * 
  * @return std::string ID
  */
  std::string getId();
  /**
  * @brief Returns the sensor type
  * 
  * @return std::string Sensor type 
  */
  std::string getType();
  /**
  * @brief Turns the sensor On/Off
  * 
  * @param active 
  */
  void setActive(bool);
  /**
  * @brief Returns if the sensor is On/Off
  * 
  * @return true = ON
  * @return false = OFF
  */
  bool isActive();
  /**
  * @brief Set the area of the sensor
  * 
  * @param area 
  */
  void setArea(std::string);
  /**
  * @brief Returns the area of the sensor
  * 
  * @return std::string Area
  */
  std::string getArea();
  /**
  * @brief Set the sensor data values magnitude
  * 
  * @param magnitude 
  */
  void setMagnitude(std::string magnitude);
  /**
  * @brief Returns the sensor magnitude
  * 
  * @return std::string Magnitude
  */
  std::string getMagnitude();
  /**
  * @brief Set the number of values per min
  * 
  * @param valPerMin 
  */
  void setValPerMin(int valPerMin);
  /**
  * @brief Return the number of values per min
  * 
  * @return int Values per minute
  */
  int getValPerMin();
  virtual std::vector<int> requestData() = 0;
  virtual ~Sensor();

protected:
  std::string id;
  bool active;
  std::string type;
  std::string area;
  std::vector <int> data;
  std::string magnitude;
  int valPerMin;

  void addNewData(int);
  void removeOldData(int);
};

#endif