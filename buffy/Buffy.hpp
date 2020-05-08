#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include <vector>
#include "Humanoid.hpp"
#include "Vampire.hpp"

class Buffy : public Humanoid {

public:
    Buffy(const Field& field, const Cell& cell);
    void move();

private:
    const Vampire& nearestEnemy() const;
};

#endif //BUFFY_BUFFY_HPP
