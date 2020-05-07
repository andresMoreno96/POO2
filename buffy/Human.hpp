#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Person.hpp"

class Human : public Person {

public:
    Human(const Manager& manager, const Cell& cell);
    void move();
};

#endif //BUFFY_HUMAN_HPP
