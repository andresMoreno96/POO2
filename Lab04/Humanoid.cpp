/*
 * File:   Humanoid.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#include <iostream>
#include "Humanoid.hpp"

using namespace std;

size_t Humanoid::counter = 0;

Humanoid::Humanoid(const HumanoidType& type)
: action(nullptr), type(&type), alive(true), cell(nullptr), id(counter++) {

}

Humanoid::~Humanoid() {

}

void Humanoid::die(Field &field) {
    if(alive) {
        // Signal that the humanoid died
        alive = false;

        // Enlever l'humanoid de la cellule
        if (cell != nullptr) {
            cell->removeHumanoid(*this);
            cell = nullptr;
        }
    }
}


Cell* Humanoid::getCell() const {
    return cell;
}

int Humanoid::getX() const {
    return cell->getX();
}

int Humanoid::getY() const {
    return cell->getY();
}

bool Humanoid::isAlive() const {
    return alive;
}

const HumanoidType& Humanoid::getType() const {
    return *type;
}

void Humanoid::setCell(Cell* cell) {
    this->cell = cell;
}

void Humanoid::display() const {
    cout << type->getRepresentation();
}

void Humanoid::executeAction(Field& field) {
    if (alive) {
        if (action != nullptr) {
            action->execute(field);
        }
    }
    action= nullptr;
}

const size_t Humanoid::getId() const {
    return id;
}

bool operator==(const Humanoid& lhs, const Humanoid& rhs) {
    return lhs.getType() == rhs.getType() &&
           lhs.getId() == rhs.getId();
}

bool operator!=(const Humanoid& lhs, const Humanoid& rhs) {
    return !(rhs == lhs);
}
