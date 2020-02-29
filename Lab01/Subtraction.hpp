/* 
 * File:   Subtraction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on February 21, 2020, 3:46 PM
 * 
 * class capable of making a subtraction.
 */

#ifndef SUBTRACTION_H
#define	SUBTRACTION_H

#include "Operation.hpp"

class Subtraction : public Operation {
    int apply(int a, int b) const;


};

#endif	/* SUBTRACTION_H */

