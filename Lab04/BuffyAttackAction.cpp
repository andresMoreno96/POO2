#include "BuffyAttackAction.hpp"

BuffyAttackAction::BuffyAttackAction(Humanoid *humanoid, Humanoid * target) : Action(humanoid),target(target) {}

void BuffyAttackAction::execute(Field& f) {

    target->setAlive(false);
    f.setNbVampires(f.getNbVampires()-1);

}

