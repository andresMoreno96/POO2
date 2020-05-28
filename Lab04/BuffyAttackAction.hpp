/*
 * File:   BuffyAttackAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_BUFFYATTACKACTION_HPP
#define BUFFY_BUFFYATTACKACTION_HPP

#include "Action.hpp"

class BuffyAttackAction : public Action {
private:
    Humanoid *target;

public:
    BuffyAttackAction(Humanoid* humanoid, Humanoid* target);
    void execute(Field& f);
};

#endif //BUFFY_BUFFYATTACKACTION_HPP