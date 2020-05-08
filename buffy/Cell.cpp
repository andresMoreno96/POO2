#include "Cell.hpp"

Cell::Cell(size_t x, size_t y) : X(x), Y(y) {

}

void Cell::addCharacter(const Humanoid& character) {
    // TODO: implement this
}

void Cell::removeCharacter(const Humanoid& character) {
    // TODO: implement this
}

const std::vector<const Humanoid *>& Cell::getHumanoids() const {
    return humanoids;
}

size_t Cell::getX() const {
    return X;
}

size_t Cell::getY() const {
    return Y;
}