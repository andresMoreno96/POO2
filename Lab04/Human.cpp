#include <memory>
#include <iostream>
#include "Human.hpp"
#include "MoveAction.hpp"
#include "RandomMoveAction.hpp"
#include "Vampire.hpp"

Human::Human() : Humanoid(Field::HUMAN) {}

void Human::setAction(const Field &field) {
    action = std::make_unique<RandomMoveAction>(this);
}

void Human::die(Field& field) {
    if(!isAlive()) {
        return;
    }

    field.setNbHumans(field.getNbHumans() - 1);

    // Probability to spawn a vampire
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 1);

    if(distribution(rd)) {
        field.createHumanoid(Field::VAMPIRE, this->getCell());
    }

    Humanoid::die(field);
}