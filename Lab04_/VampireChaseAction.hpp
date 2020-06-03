/*
 * File:   VampireChaseAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_VAMPIRECHASEACTION_HPP
#define BUFFY_VAMPIRECHASEACTION_HPP

#include "MoveAction.hpp"

/**
 * Represents the vampire chase action
 */
class VampireChaseAction : public MoveAction {
    const Humanoid* target;
public:
    /**
     * Constructor
     * @param humanoid the humanoid chasing
     * @param target the humanoid that is being chased
     */
    VampireChaseAction(Humanoid* humanoid,const Humanoid* target);

    /**
     * Execute the vampire chase action
     * @param f the field on which the chase is made
     */
    void execute(Field &f) override;
};

#endif //BUFFY_VAMPIRECHASEACTION_HPP
