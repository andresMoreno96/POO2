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

/**
 * Represents a cell of the field
 * It contains the humanoids
 */
class Cell {
    const int x;
    const int y;
    std::list<const Humanoid *> humanoids;

public:
    /**
     * Constructor
     * @param x the x coordinate inside the field
     * @param y the y coordinate inside the field
     */
    Cell(int x, int y);

    /**
     * Destructor
     */
    virtual ~Cell();

    /**
     * Add a humanoid on this cell
     * @param humanoid the humanoid to add
     */
    void addHumanoid(const Humanoid &humanoid);

    /**
     * Removes the humanoid from this cell
     * @param humanoid the humanoid to remove
     */
    void removeHumanoid(Humanoid &humanoid);

    /**
     * Get the x coordinate
     * @return the x coordinate
     */
    int getX() const;

    /**
     * Get the y coordinate
     * @return the y coordinate
     */
    int getY() const;

    /**
     * Display the field
     */
    void display() const;
};

#endif //BUFFY_CELL_HPP
