//
// Created by simon on 22.05.20.
//

#include "BuffyChaseAction.hpp"
#include "Vampire.hpp"

BuffyChaseAction::BuffyChaseAction(Humanoid* humanoid) : MoveAction(humanoid) {}

void BuffyChaseAction::execute(Field &f) {

    const Humanoid *vam = f.nearestFrom(humanoid, &Field::VAMPIRE);
    if (vam != nullptr) {

        for (size_t i = 0; i < 2; ++i) {
            int tmpx = (vam->getX() - humanoid->getX());
            tmpx = tmpx==0 ? 0 : tmpx / abs(tmpx);

            int tmpy = (vam->getY() - humanoid->getY());
            tmpy = tmpy==0 ? 0 : tmpy / abs(tmpy);

            f.moveHumanoid(*humanoid, humanoid->getX() + tmpx, humanoid->getY() + tmpy);
        }
    }

}
