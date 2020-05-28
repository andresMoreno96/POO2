/*
 * File:   RandomMoveAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_RANDOMMOVEACTION_HPP
#define BUFFY_RANDOMMOVEACTION_HPP

#include "MoveAction.hpp"

/**
 * Represents a random move action
 */
class RandomMoveAction : public MoveAction {

public:
    /**
     * Constructor
     * @param humanoid the humanoid to move randomly
     */
    RandomMoveAction(Humanoid* humanoid);

    /**
     * Execute the action
     * @param f the field where the action takes place
     */
    void execute(Field &f) override;
};

#endif //BUFFY_RANDOMMOVEACTION_HPP
