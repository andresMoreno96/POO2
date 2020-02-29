/* 
 * File:   Multiplication.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on February 21, 2020, 3:46 PM
 * 
 * class capable of making a multiplication.
 */

#ifndef MULTIPLICATION_H
#define	MULTIPLICATION_H

#include "Operation.hpp"

class Multiplication : public Operation {
    int apply(int a, int b) const;


};


#endif	/* MULTIPLICATION_H */

