/*
 * File:   VampireAttackAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_VAMPIREATTACKACTION_HPP
#define BUFFY_VAMPIREATTACKACTION_HPP

#include "Action.hpp"

class VampireAttackAction : public Action {
    Humanoid *target;
public:
    VampireAttackAction(Humanoid* humanoid, Humanoid * target);
    void execute(Field& f);
};

#endif //BUFFY_VAMPIREATTACKACTION_HPP
