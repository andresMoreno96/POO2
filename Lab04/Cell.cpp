#include "Cell.hpp"
#include <iostream>

using namespace std;

Cell::Cell(int x, int y) : X(x), Y(y) {

}

void Cell::addHumanoid(const Humanoid& humanoid) {
    humanoids.push_back(&humanoid);
}

void Cell::removeHumanoid(Humanoid& humanoid) {
    humanoids.remove(&humanoid);
}

int Cell::getX() const {
    return X;
}

int Cell::getY() const {
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

Cell::~Cell() {

}
