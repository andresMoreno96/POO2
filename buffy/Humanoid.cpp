#include "Humanoid.hpp"

Humanoid::Humanoid(const Field& field, const Cell& cell, const HumanoidType& type)
: field(&field), cell(&cell), action(nullptr), type(&type), alive(true) {

}

Humanoid::~Humanoid() {

}

const Cell& Humanoid::getCell() const {
    return *cell;
}

const Field& Humanoid::getField() const {
    return *field;
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
