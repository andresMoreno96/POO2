/*
 * File:   Human.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 20, 2020
 */

#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Represents a human
 */
class Human: public Humanoid {

public:
    /**
     * Constructor
     */
    Human();

    /**
     * Makes this human die
     * @param field the field where the human dies
     */
    void die(Field& field) override;

    /**
     * Set the next action that the human will take on a field
     * @param field the field where the action takes place
     */
    void setAction(const Field &field) override;
};

#endif //BUFFY_HUMAN_HPP
