/**
 * @file NotFoundUserException.h
 * @author Javier Izquierdo Hernandez (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Exception thrown when user not found in database.
 * @version 0.1
 * @date 2022-12-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NOTFOUNDUSEREXCEPTION_H 
#define	NOTFOUNDUSEREXCEPTION_H

#include <stdexcept> // contains runtime_error

class NotFoundUserException : public std::runtime_error {
  public:
    NotFoundUserException(): std::runtime_error ("User not found in database") {}
};

#endif