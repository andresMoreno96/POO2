/*
 * File:   BuffyChaseAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_BUFFYCHASEACTION_HPP
#define BUFFY_BUFFYCHASEACTION_HPP

#include "MoveAction.hpp"

/**
 * Represents the chase action of Buffy
 */
class BuffyChaseAction : public MoveAction {
    const Humanoid *target;
public:
    /**
     * Constructor
     * @param humanoid the humanoid chasing
     * @param target the humanoid that is being chased
     */
    BuffyChaseAction(Humanoid *humanoid, const Humanoid *target);

    /**
     * Execute the buffy chase action
     * @param f the field on which the chase is made
     */
    void execute(Field &f) override;
};


#endif //BUFFY_BUFFYCHASEACTION_HPP
