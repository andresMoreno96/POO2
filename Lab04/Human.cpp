//
// Created by simon on 08.05.20.
//

#include <random>
#include <iostream>
#include <memory>
#include "Human.hpp"
#include "RandomMoveAction.hpp"

Human::Human(const HumanoidType &type) : Humanoid(type) {}

void Human::setAction(const Field &field) {
    setAction(std::make_unique<RandomMoveAction>(*this));
}

void Human::setNewPosition() {

}

Human::~Human() {

}
