#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human : public Humanoid {

public:
    Human(const Field& field, const Cell& cell);
    void move();
};

#endif //BUFFY_HUMAN_HPP
