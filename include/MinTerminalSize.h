/**
 * @file MinTerminalSize.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MINTERMINALSIZE_H 
#define	MINTERMINALSIZE_H

#include <stdexcept> // contains runtime_error

class MinTerminalSize : public std::runtime_error {
  public:
    MinTerminalSize(): std::runtime_error ("The size of the terminal is to small. Minimum size 100 x 50 ") {}
};

#endif