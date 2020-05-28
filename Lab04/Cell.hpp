/*
 * File:   Cell.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#ifndef BUFFY_CELL_HPP
#define BUFFY_CELL_HPP

#include <cstddef>
#include <list>
#include <memory>
#include "Humanoid.hpp"

class Humanoid;

class Cell {
    const int x;
    const int y;
    std::list<const Humanoid*> humanoids;

public:
    Cell(int x, int y);
    void addHumanoid(const Humanoid& humanoid);
    void removeHumanoid(Humanoid& humanoid);
    int getX() const;
    int getY() const;
    void display() const;

    virtual ~Cell();

};

#endif //BUFFY_CELL_HPP
