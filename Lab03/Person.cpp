/*
 * File:   Person.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 16, 2019
 */

#include "Person.hpp"

#include <string>
#include <iostream>

using namespace std;

Person::Person(const string& name, PersonType type, Sex sex)
: _name(name), _type(type), _sex(sex) {}

const string& Person::name() const {
    return _name;
}

PersonType Person::type() const {
    return _type;
}

Sex Person::sex() const {
    return _sex;
}

Person::~Person() {

}

Policeman::Policeman(std::string name, Sex sex): Person(name, POLICEMAN, sex) {}
    
bool Policeman::canDrive() const {
    return true;
}

Thief::Thief(std::string name, Sex sex): Person(name, THIEF, sex) {}
    
bool Thief::canDrive() const {
    return false;
}

Parent::Parent(std::string name, Sex sex): Person(name, PARENT, sex) {}
    
bool Parent::canDrive() const {
    return true;
}

Child::Child(std::string name, Sex sex,
             const Parent* father, const Parent* mother)
: Person(name, CHILD, sex), _father(father), _mother(mother) {}
    
const Parent* Child::father() const {
    return _father;
}
    
const Parent* Child::mother() const {
    return _mother;
}
    
bool Child::canDrive() const {
    return false;
}
