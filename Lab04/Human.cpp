//
// Created by simon on 08.05.20.
//

#include <random>
#include <iostream>
#include "Human.hpp"

Human::Human(const Field &field, const HumanoidType &type) : Humanoid(field, type) {}

void Human::setAction(const Field &field) {







}

void Human::executeAction(Field &field) {
    if(isAlive()){
        setNewPosition();


    }
}

void Human::setNewPosition() {








}


Human::~Human() {

}
