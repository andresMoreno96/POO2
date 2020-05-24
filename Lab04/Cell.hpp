#ifndef BUFFY_CELL_HPP
#define BUFFY_CELL_HPP

#include <cstddef>
#include <list>
#include <memory>
#include "Humanoid.hpp"

class Humanoid;

class Cell {
    const int X;
    const int Y;
    std::list<const Humanoid*> humanoids;

public:
    Cell(int x, int y);
    void addHumanoid(const Humanoid& humanoid);
    void removeHumanoid(Humanoid& humanoid);
    const std::list<const Humanoid*>& getHumanoids() const;
    int getX() const;
    int getY() const;
    void display() const;

    virtual ~Cell();

};

#endif //BUFFY_CELL_HPP
