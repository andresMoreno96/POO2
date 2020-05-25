#include <memory>
#include <iostream>
#include "Human.hpp"
#include "MoveAction.hpp"
#include "RandomMoveAction.hpp"
#include "Vampire.hpp"

Human::Human(const HumanoidType &type) : Humanoid(type) {}

void Human::setAction(const Field &field) {
    std::cout<<"run human"<<std::endl;
    action = std::make_unique<RandomMoveAction>(this);
}

void Human::die(Field& field) {
    if(isAlive()) {
        field.setNbHumans(field.getNbHumans() - 1);

    }

    Humanoid::die(field);

}

Human::~Human() {

}
