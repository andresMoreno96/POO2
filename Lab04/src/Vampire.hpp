/*
 * File:   Vampire.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 20, 2020
 */

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Represents a vampire
 */
class Vampire: public Humanoid {

public:
    /**
     * Constructor
     */
    Vampire();

    /**
     * Makes this vampire die
     * @param field the field where the vampire dies
     */
    void die(Field& field) override;

    /**
     * Set the next action that the vampire will take on a field
     * @param field the field where the action takes place
     */
    void setAction(const Field &field) override;
};


#endif //BUFFY_VAMPIRE_HPP
