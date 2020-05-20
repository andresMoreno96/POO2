#ifndef BUFFY_CELL_HPP
#define BUFFY_CELL_HPP

#include <cstddef>
#include <list>
#include <memory>
#include "Humanoid.hpp"

class Humanoid;

class Cell {
    const size_t X;
    const size_t Y;
    std::list<const Humanoid*> humanoids;

public:
    Cell(size_t x, size_t y);
    void addHumanoid(const Humanoid& humanoid);
    void removeHumanoid(const Humanoid& humanoid);
    const std::list<const Humanoid*>& getHumanoids() const;
    size_t getX() const;
    size_t getY() const;
    void display() const;

};

#endif //BUFFY_CELL_HPP
