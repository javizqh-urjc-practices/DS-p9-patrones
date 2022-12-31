/**
 * @file NotFoundArgument.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NOTFOUNDARGUMENT_H 
#define	NOTFOUNDARGUMENT_H

#include <stdexcept> // contains runtime_error

class NotFoundArgument : public std::runtime_error {
  public:
    NotFoundArgument(): std::runtime_error ("Not valid option.") {}
};

#endif