/*
 * File:   MoveAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"

/**
 * Represents a move action
 */
class MoveAction : public Action {

public:
    /**
     * Constructor
     * @param humanoid the humanoid to move
     */
    MoveAction(Humanoid *humanoid);

    /**
     * Execute the action
     * @param f the field where the action takes place
     */
    void execute(Field &f) = 0;
};

#endif //BUFFY_MOVEACTION_HPP
