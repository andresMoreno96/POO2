/*
 * File:   Humanoid.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "Cell.hpp"
#include "Field.hpp"
#include "Action.hpp"
#include "HumanoidType.hpp"
#include <memory>

class Cell;
class Field;
class Action;

class Humanoid {
    static size_t counter;
    const HumanoidType *type;
    Cell *cell;
    bool alive;
    const size_t id;

protected:
    std::unique_ptr<Action> action;
public:
    /**
     * Constructor
     * @param type the humanoid type
     */
    Humanoid(const HumanoidType &type);

    /**
     * Destructor
     */
    virtual ~Humanoid();

    /**
     * Makes the humanoid die
     * @param field field on which the humanoid died
     */
    virtual void die(Field &field);

    /**
     * Set the next action that the humanoid will take
     * @param field the field where the action will take place
     */
    virtual void setAction(const Field &field) = 0;

    /**
     * Execute this humanoid action
     * @param field the field where the action takes place
     */
    void executeAction(Field &field);

    /**
     * Get if the humanoid is alive
     * @return if the humanoid is alive
     */
    bool isAlive() const;

    /**
     * Get the cell where the humanoid is
     * @return the cell
     */
    Cell *getCell() const;

    /**
     * Set the cell where the humanoid is
     * @param cell the cell
     */
    void setCell(Cell *cell);

    /**
     * Get this humanoid type
     */
    const HumanoidType &getType() const;

    /**
     * Display the humanoid
     */
    void display() const;

    /**
     * Get the x coordinate where the humanoid is
     * @return the x coordinate
     */
    int getX() const;

    /**
     * Get the y coordinate where the humanoid is
     * @return the y coordinate
     */
    int getY() const;

    /**
     * Get the humanoid id
     */
    const size_t getId() const;
};

bool operator==(const Humanoid &lhs, const Humanoid &rhs);

bool operator!=(const Humanoid &lhs, const Humanoid &rhs);

#endif //BUFFY_HUMANOID_HPP
