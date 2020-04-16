/*
 * File:   Container.h
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#include "Container.hpp"

#include <string>
#include <list>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& stream, const Container& container) {
    
    if (container.personsCount() > 0) {
    
        auto it = container.persons().begin();
        auto end = container.persons().end();
        
        stream << (*it)->name();
        ++it;
        
        for (; it != end; ++it) {
            stream << " " << (*it)->name();
        }
    }
    
    return stream;
}

Container::Container(string name): _name(name) {}

void Container::addPerson(const Person* p){
    _persons.push_back(p);
}

void Container::removePerson(const Person* p) {
    _persons.remove(p);
}

size_t Container::personsCount() const {
    return _persons.size();
}

string Container::name() const {
    return _name;
}

const list<const Person*>& Container::persons() const {
    return _persons;
}

bool Container::contains(std::function<bool(const Person*)> f) const {
    for (const Person* p : _persons) {
        if (f(p)) {
            return true;
        }
    }
    return false;
}

bool Container::contains(list<const Person* >persons,std::function<bool(const Person*)> f) const {

    for(auto it=persons.begin(); it!=persons.end(); it++) {

        if (f(*it)) {
            return true;
        }
    }

    return false;
}



bool Container::contains(const Person* person) const {
    return contains([&](const Person* p){
        return person == p;
    });
}

void Container::empty() {
    _persons.clear();
}


