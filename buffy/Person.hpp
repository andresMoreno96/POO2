#ifndef BUFFY_PERSON_HPP
#define BUFFY_PERSON_HPP

#include "Cell.hpp"
#include "Manager.hpp"

class Cell;

class Person {
    const Manager& manager;
    const Cell& cell;

public:
    Person(const Manager& manager, const Cell& cell);
    virtual ~Person();
    void virtual move() = 0;
    const Cell& getCell() const;
    const Manager& getManager() const;
    size_t getX() const;
    size_t getY() const;
};

#endif //BUFFY_PERSON_HPP
