#include <iostream>
#include "Humanoid.hpp"

using namespace std;

size_t Humanoid::humanoidCounter = 0;

Humanoid::Humanoid(const Field& field, const HumanoidType& type)
: field(&field), action(nullptr), type(&type), alive(true),
  id(humanoidCounter++) {

}

Humanoid::~Humanoid() {

}

Cell* Humanoid::getCell() const {
    return cell;
}

const Field* Humanoid::getField() const {
    return field;
}

size_t Humanoid::getX() const {
    return cell->getX();
}

size_t Humanoid::getY() const {
    return cell->getY();
}

bool Humanoid::isAlive() const {
    return alive;
}

void Humanoid::setAction(const Field& field) const {
    // TODO: implement this
}

void Humanoid::executeAction(Field& field) {
    // TODO: implement this
}

const HumanoidType& Humanoid::getType() const {
    return *type;
}

void Humanoid::setCell(Cell* cell) {
    this->cell = cell;
}

size_t Humanoid::getId() const {
    return id;
}

void Humanoid::display() const {
    cout << type->getRepresentation();
}

bool operator==(const Humanoid& lhs, const Humanoid& rhs) {
    return lhs.getId() == rhs.getId();
}

bool operator!=(const Humanoid& lhs, const Humanoid& rhs) {
    return !(lhs == rhs);
}