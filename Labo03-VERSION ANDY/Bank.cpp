/*
 * File:   Bank.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 16, 2019
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
