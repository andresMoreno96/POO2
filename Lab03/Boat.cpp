/*
 * File:   Boat.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 16, 2019
 */

#include "Container.h"
#include "Boat.h"

#include <string>

using namespace std;

ostream& operator<<(ostream& stream, const Boat& boat) {
    
    stream << boat.name() << ": < " << (const Container&) boat << " >";
    
    return stream;
}

Boat::Boat(std::string name, size_t capacity, const Bank* bank)
: Container(name), CAPACITY(capacity), _bank(bank) {}

void Boat::addPerson(const Person* p) {
    if (hasSpace()) {
        Container::addPerson(p);
    }
}

const Bank* Boat::bank() const {
    return _bank;
}

bool Boat::isInBank(const Bank* bank) const {
    return _bank == bank;
}

bool Boat::canChangeBank() const {
    
    for (const Person* p : persons()) {
        if (p->canDrive()) {
            return true;
        }
    }
    return false;
}

void Boat::changeBank(const Bank* bank) {
    _bank = bank;
}

bool Boat::hasSpace() const {
    return personsCount() < 2;
}
