#include "VampireAttackAction.hpp"

VampireAttackAction::VampireAttackAction(Humanoid* humanoid,  Humanoid * target) : Action(humanoid), target(target) {

}

void VampireAttackAction::execute(Field& f) {
    target->die(f);
}
