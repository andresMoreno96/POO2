#include "BuffyAttackAction.hpp"

BuffyAttackAction::BuffyAttackAction(Humanoid *humanoid, Humanoid * target) : Action(humanoid), target(target) {}

void BuffyAttackAction::execute(Field& f) {
    target->die(f);
}

