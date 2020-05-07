#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include <vector>
#include "Person.hpp"
#include "Vampire.hpp"

class Buffy : public Person {

public:
    Buffy(const Manager& manager, const Cell& cell);
    void move();

private:
    const Vampire& nearestEnemy() const;
};

#endif //BUFFY_BUFFY_HPP
