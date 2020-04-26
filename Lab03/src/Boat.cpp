/*
 * File:   Boat.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#include "Container.hpp"
#include "Boat.hpp"
#include "Controller.hpp"

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
    } else {
        cout << "### il n'y a plus de place dans le bateau" << endl;
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
        if (p->hasRole("DRIVE")) {
            return true;
        }
    }

    cout << "### les personnes sur le bateau ne peuvent pas conduire" << endl;

    return false;
}

void Boat::changeBank(const Bank* bank) {
    _bank = bank;
}

bool Boat::hasSpace() const {
    return personsCount() < Controller::getBoatCapacity();
}
