#include "Cell.hpp"

Cell::Cell(size_t x, size_t y) : X(x), Y(y) {

}

void Cell::addHumanoid(const Humanoid& humanoid) {
    // TODO: implement this
}

void Cell::removeHumanoid(const Humanoid& humanoid) {
    // TODO: implement this
}

const std::list<const Humanoid *>& Cell::getHumanoids() const {
    return humanoids;
}

size_t Cell::getX() const {
    return X;
}

size_t Cell::getY() const {
    return Y;
}