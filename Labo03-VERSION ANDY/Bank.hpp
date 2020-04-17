/*
 * File:   Bank.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#ifndef BANK_H
#define	BANK_H

#include <iostream>
#include <string>

#include "Container.hpp"

class Bank;

/**
 * Writes informations of the bank to a stream
 * @param stream the stream to write to
 * @param bank the bank
 */
std::ostream& operator<<(std::ostream& stream, const Bank& bank);

/**
 * Represent a bank of a river.
 */
class Bank : public Container {
    
public:

    /**
     * Create a new bank
     * @param name the bank name
     */
    Bank(std::string name);
};

#endif	/* BANK_H */

