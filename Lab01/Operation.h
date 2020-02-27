/* 
 * File:   Operation.h
 * Author: Andres Moreno, Nohan Budry
 *
 * Created on February 21, 2019, 3:46 PM
 * 
 * "abstract" class representing an operation.
 * 
 */

#ifndef Operation_h
#define Operation_h

class Operation {
public:

    /**
     * @brief calculate the operation
     * 
     * @param a first operand
     * @param b second operand 2
     */
    virtual int apply(int a, int b) const = 0; 
};

#endif /* Operation_h */
