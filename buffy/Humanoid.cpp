#include "Humanoid.hpp"

Humanoid::Humanoid(const Field& field, const Cell& cell) : field(field), cell(cell), action(nullptr), alive(true) {

}

Humanoid::~Humanoid() {

}

const Cell& Humanoid::getCell() const {
    return cell;
}

const Field& Humanoid::getField() const {
    return field;
}

size_t Humanoid::getX() const {
    return cell.getX();
}

size_t Humanoid::getY() const {
    return cell.getY();
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
