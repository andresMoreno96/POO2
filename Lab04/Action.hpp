/*
 * File:   Action.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 8, 2020
 */

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "Field.hpp"
#include "Humanoid.hpp"

class Field;
class Humanoid;

/**
 * Represents action taken by humanoids
 */
class Action {

protected:
    Humanoid* humanoid;
public:
    /**
     * Constructor
     * @param humanoid the humanoid taking the action
     */
    Action(Humanoid* humanoid);

    /**
     * Destructor
     */
    virtual ~Action();

    /**
     * Execute the action
     * @param f the field on which the action is taken
     */
    virtual void execute(Field& f) = 0;
};

#endif //BUFFY_ACTION_HPP
