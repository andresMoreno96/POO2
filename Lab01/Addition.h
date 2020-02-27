/* 
 * File:   Addition.h
 * Author: Andres Moreno, Nohan Budry
 *
 * Created on February 21, 2019, 3:46 PM
 * 
 * class capable of making a sum.
 * 
 */

#ifndef Addition_h
#define Addition_h

#include "Operation.h"

class Addition : public Operation {
public:
    
    int apply(int a, int b) const;
};

#endif /* Addition_h */
