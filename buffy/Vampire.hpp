#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : public Humanoid {

public:
    Vampire(const Field& field, const Cell& cell);
    void move();
};

#endif //BUFFY_VAMPIRE_HPP
