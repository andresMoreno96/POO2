/*
 * File:   VampireAttackAction.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#include "VampireAttackAction.hpp"

VampireAttackAction::VampireAttackAction(Humanoid* humanoid,  Humanoid * target) : Action(humanoid), target(target) {

}

void VampireAttackAction::execute(Field& f) {
    target->die(f);
}
