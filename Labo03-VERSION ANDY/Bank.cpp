/*
 * File:   Bank.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#include "Container.hpp"
#include "Bank.hpp"

#include <string>

using namespace std;

ostream& operator<<(ostream& stream, const Bank& bank) {
    
    stream << bank.name() << ": " << (const Container&) bank;
    
    return stream;
}

Bank::Bank(string name): Container(name) {}
