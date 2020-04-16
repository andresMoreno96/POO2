/*
 * File:   Person.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 16, 2019
 */

#include "Person.hpp"

#include <string>
#include <vector>

using namespace std;

Person::Person(const string &name,
               Sex sex, const vector<const Role *> &roles)
        : _name(name), _sex(sex), roles(roles) {}

const string &Person::name() const {
    return _name;
}

Sex Person::sex() const {
    return _sex;
}

Person::~Person() {

}


bool Person::hasRole(const std::string &role) const {

    for (auto it = roles.begin(); it != roles.end(); it++) {

        if (((*it)->getRole().compare(role)) == 0)
            return true;
    }

    return false;
}


Policeman::Policeman(std::string name, Sex sex, const vector<const Role *> &roles)
        : Person(name, sex, roles) {}


Thief::Thief(std::string name, Sex sex, const vector<const Role *> &roles
) : Person(name, sex, roles) {}


Parent::Parent(std::string name, Sex sex, const vector<const Role *> &roles
) : Person(name, sex, roles) {}


Child::Child(std::string name, Sex sex,
             const Parent *father, const Parent *mother, const vector<const Role *> &roles)
        : Person(name, sex, roles), _father(father), _mother(mother) {}

const Parent *Child::father() const {
    return _father;
}

const Parent *Child::mother() const {
    return _mother;
}
