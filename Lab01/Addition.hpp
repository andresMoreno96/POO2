/* 
 * File:   Addition.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on February 21, 2020, 3:46 PM
 * 
 * class capable of making a sum.
 * 
 */

#ifndef Addition_h
#define Addition_h

#include "Operation.hpp"

class Addition : public Operation {
public:
    
    int apply(int a, int b) const;
};

#endif /* Addition_h */
