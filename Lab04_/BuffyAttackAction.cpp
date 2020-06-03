/*
 * File:   BuffyAttackAction.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#include "BuffyAttackAction.hpp"

BuffyAttackAction::BuffyAttackAction(Humanoid *humanoid, Humanoid * target) : Action(humanoid), target(target) {}

void BuffyAttackAction::execute(Field& f) {
    target->die(f);
}

