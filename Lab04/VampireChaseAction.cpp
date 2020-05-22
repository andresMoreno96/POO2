//
// Created by simon on 22.05.20.
//

#include "VampireChaseAction.hpp"

VampireChaseAction::VampireChaseAction(Humanoid* humanoid) : MoveAction(humanoid) {}

void VampireChaseAction::execute(Field &f) {

    const Humanoid *hum = f.nearestFrom(humanoid, &Field::HUMAN);
    if (hum != nullptr) {

        int tmpx = (hum->getX() - humanoid->getX());
        tmpx = tmpx==0 ? 0 : tmpx / abs(tmpx);

        int tmpy = (hum->getY() - humanoid->getY());
        tmpy = tmpy==0 ? 0 : tmpy / abs(tmpy);

        f.moveHumanoid(*humanoid, humanoid->getX() + tmpx, humanoid->getY() + tmpy);

    }
}
