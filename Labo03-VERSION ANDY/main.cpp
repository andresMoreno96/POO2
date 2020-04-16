/*
 * File:   main.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#include <cstdlib>

#include "Person.hpp"
#include "Controller.hpp"
#include "Constraint.hpp"

using namespace std;

int main() {

    //Roles
    PolicemanRole policemanRole;
    ThieveRole thieveRole;
    ParentRole parentRole;
    ChildRole childRole;
    DriveRole driveRole;

    //Actions
    const vector<const Role*> policeActions={&policemanRole,&driveRole};
    const vector<const Role*> thieveActions={&thieveRole};
    const vector<const Role*> parentActions={&parentRole,&driveRole};
    const vector<const Role*> childActions={&childRole};


    // Persons
    Policeman policeman("policier", Sex::MALE, policeActions);
    Thief thief("voleur", Sex::MALE, thieveActions);
    Parent father("pere", Sex::MALE, parentActions);
    Parent mother("mere", Sex::FEMALE, parentActions);
    Child paul("paul", Sex::MALE, &father, &mother, childActions);
    Child pierre("pierre", Sex::MALE, &father, &mother, childActions);
    Child julie("julie", Sex::FEMALE, &father, &mother, childActions);
    Child jeanne("jeanne", Sex::FEMALE, &father, &mother, childActions);
    
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

