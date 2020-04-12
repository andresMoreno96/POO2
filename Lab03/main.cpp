/*
 * File:   main.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <limits>

#include "Person.h"
#include "Controller.h"
#include "Constraint.h"

using namespace std;

int main() {
    
    // Persons
    Policeman policeman("policier", Sex::MALE);
    Thief thief("voleur", Sex::MALE);
    Parent father("pere", Sex::MALE);
    Parent mother("mere", Sex::FEMALE);
    Child paul("paul", Sex::MALE, &father, &mother);
    Child pierre("pierre", Sex::MALE, &father, &mother);
    Child julie("julie", Sex::FEMALE, &father, &mother);
    Child jeanne("jeanne", Sex::FEMALE, &father, &mother);
    
    // Constraints
    ThiefConstraint thiefConstraint;
    SonConstraint sonConstraint;
    DaughterConstraint daughterConstraint;

    // Controller
    Controller controller({
        &policeman, &thief, &father, &mother,
        &paul, &pierre, &julie, &jeanne
    }, {
        &thiefConstraint, &sonConstraint, &daughterConstraint
    });
    
    
    controller.play();
    
    return EXIT_SUCCESS;
}

