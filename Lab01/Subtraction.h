/* 
 * File:   Substraction.h
 * Author: Andres Moreno, Nohan Budry
 *
 * Created on February 21, 2019, 3:46 PM
 * 
 * class capable of making a subtraction.
 */

#ifndef SUBTRACTION_H
#define	SUBTRACTION_H

#include "Operation.h"

class Subtraction : public Operation {
    int apply(int a, int b) const;


};

#endif	/* SUBTRACTION_H */

