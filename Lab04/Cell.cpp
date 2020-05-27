#include "Cell.hpp"
#include <iostream>

using namespace std;

Cell::Cell(int x, int y) : x(x), y(y) {

}

void Cell::addHumanoid(const Humanoid& humanoid) {
    humanoids.push_back(&humanoid);
}

void Cell::removeHumanoid(Humanoid& humanoid) {
    humanoids.remove(&humanoid);
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
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
