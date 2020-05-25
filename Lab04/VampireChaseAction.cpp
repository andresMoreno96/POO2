//
// Created by simon on 22.05.20.
//

#include "VampireChaseAction.hpp"

VampireChaseAction::VampireChaseAction(Humanoid* humanoid, const Humanoid* target) : MoveAction(humanoid),target(target) {}

void VampireChaseAction::execute(Field &f) {

    if (target!= nullptr && target->isAlive()) {

            int tmpx = (target->getX() - humanoid->getX());
            tmpx = tmpx == 0 ? 0 : tmpx / abs(tmpx);

            int tmpy = (target->getY() - humanoid->getY());
            tmpy = tmpy == 0 ? 0 : tmpy / abs(tmpy);

            f.moveHumanoid(*humanoid, humanoid->getX() + tmpx, humanoid->getY() + tmpy);


    }

}
