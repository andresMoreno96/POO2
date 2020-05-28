/*
 * File:   VampireAttackAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_VAMPIREATTACKACTION_HPP
#define BUFFY_VAMPIREATTACKACTION_HPP

#include "Action.hpp"

/**
 * Represents a vampire attack action
 */
class VampireAttackAction : public Action {
    Humanoid *target;
public:
    /**
     * Constructor
     * @param humanoid the humanoid making the attack
     * @param target the target of the attack
     */
    VampireAttackAction(Humanoid* humanoid, Humanoid * target);

    /**
     * Execute the attack
     * @param f the field on which the attack is made
     */
    void execute(Field& f);
};

#endif //BUFFY_VAMPIREATTACKACTION_HPP
