#include "Cell.hpp"
#include <iostream>

using namespace std;

Cell::Cell(size_t x, size_t y) : X(x), Y(y) {

}

void Cell::addHumanoid(const Humanoid& humanoid) {
    humanoids.push_back(&humanoid);
}

void Cell::removeHumanoid(const Humanoid& humanoid) {
    humanoids.remove(&humanoid);
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

void Cell::display() const {
    if(humanoids.size() > 0) {
        // print first humanoid of list
        humanoids.front()->display();
    } else {
        cout << ' ';
    }
}
