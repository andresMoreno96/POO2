#include <iostream>
#include "Humanoid.hpp"

using namespace std;

Humanoid::Humanoid(const HumanoidType& type)
: action(nullptr), type(&type), alive(true),cell(nullptr) {

}

Humanoid::~Humanoid() {

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
    if(action != nullptr) {
        action->execute(field);
    }
}

void Humanoid::setAlive(bool alive) {
    Humanoid::alive = alive;
}

