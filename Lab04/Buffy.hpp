/*
 * File:   Buffy.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 20, 2020
 */

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * Represents Buffy, a humanoid chasing and attacking vampires
 */
class Buffy: public Humanoid {

public:
    /**
     * Constructor
     */
    Buffy();

    /**
     * Set the next action that buffy will take on a field
     * @param field the field where the action takes place
     */
    void setAction(const Field &field) override;
};


#endif //BUFFY_BUFFY_HPP
