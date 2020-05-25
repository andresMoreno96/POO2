//
// Created by simon on 22.05.20.
//

#include "BuffyChaseAction.hpp"
#include "Vampire.hpp"

BuffyChaseAction::BuffyChaseAction(Humanoid* humanoid, const Humanoid* target) : MoveAction(humanoid),target(target) {}

void BuffyChaseAction::execute(Field &f) {

    if (target!= nullptr) {

        for (size_t i = 0; i < 2; ++i) {
            int tmpx = (target->getX() - humanoid->getX());
            tmpx = tmpx==0 ? 0 : tmpx / abs(tmpx);

            int tmpy = (target->getY() - humanoid->getY());
            tmpy = tmpy==0 ? 0 : tmpy / abs(tmpy);

            f.moveHumanoid(*humanoid, humanoid->getX() + tmpx, humanoid->getY() + tmpy);
        }
    }

}
