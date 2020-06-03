/*
 * File:   BuffyAttackAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_BUFFYATTACKACTION_HPP
#define BUFFY_BUFFYATTACKACTION_HPP

#include "Action.hpp"

/**
 * Represents the attack action of buffy
 */
class BuffyAttackAction : public Action {
private:
    Humanoid *target;

public:
    /**
     * Constructor
     * @param humanoid the humanoid making the attack
     * @param target the target of the attack
     */
    BuffyAttackAction(Humanoid *humanoid, Humanoid *target);

    /**
     * Execute the attack
     * @param f the field on which the attack is made
     */
    void execute(Field &f);
};

#endif //BUFFY_BUFFYATTACKACTION_HPP