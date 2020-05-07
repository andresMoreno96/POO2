#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Person.hpp"

class Vampire : public Person {

public:
    Vampire(const Manager& manager, const Cell& cell);
    void move();
};

#endif //BUFFY_VAMPIRE_HPP
