/* 
 * File:   Multiplication.h
 * Author: Andres Moreno, Nohan Budry
 *
 * Created on February 21, 2019, 3:46 PM
 * 
 * class capable of making a multiplication.
 */

#ifndef MULTIPLICATION_H
#define	MULTIPLICATION_H

#include "Operation.h"

class Multiplication : public Operation {
    int apply(int a, int b) const;


};


#endif	/* MULTIPLICATION_H */

