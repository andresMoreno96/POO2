#include "Person.hpp"

Person::Person(const Manager& manager, const Cell& cell) : manager(manager), cell(cell) {

}

Person::~Person() {

}

const Cell& Person::getCell() const {
    return cell;
}

const Manager& Person::getManager() const {
    return manager;
}

size_t Person::getX() const {
    return cell.getX();
}

size_t Person::getY() const {
    return cell.getY();
}
