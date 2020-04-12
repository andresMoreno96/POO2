/*
 * File:   Constraint.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 18, 2019
 */

#include "Constraint.h"
#include "Container.h"
#include "Person.h"

Constraint::Constraint(const std::string& message): MESSAGE(message) {}

ThiefConstraint::ThiefConstraint()
: Constraint("voleur avec un membre de la famille sans le policier") {}

bool ThiefConstraint::check(const Container& container) const {
    
    return !(container.contains([](const Person* p) {
        return p->type() == THIEF;
    }) && container.contains([](const Person* p) {
        return p->type() == PARENT || p->type() == CHILD;
    }) && !(container.contains([](const Person* p){
        return p->type() == POLICEMAN;
    })));
}

SonConstraint::SonConstraint() : Constraint("fils avec sa mere sans son pere") {}

bool SonConstraint::check(const Container& container) const {
    
    for (const Person* person : container.persons()) {
        if (person->type() == CHILD && person->sex() == MALE) {
            
            const Child* son = (const Child*) person;
            if (container.contains(son->mother())
                && !container.contains(son->father())) {
                
                return false;
            }
        }
    }
    return true;
}

DaughterConstraint::DaughterConstraint()
: Constraint("fille avec son pere sans sa mere") {}

bool DaughterConstraint::check(const Container& container) const {
    
    for (const Person* person : container.persons()) {
        if (person->type() == CHILD && person->sex() == FEMALE) {
            
            const Child* daughter = (const Child*) person;
            if (container.contains(daughter->father())
                && !container.contains(daughter->mother())) {
                
                return false;
            }
        }
    }
    return true;
}
