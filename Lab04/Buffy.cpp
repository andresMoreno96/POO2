#include <iostream>
#include "Buffy.hpp"
#include "MoveAction.hpp"
#include "BuffyAttackAction.hpp"
#include "RandomMoveAction.hpp"
#include "BuffyChaseAction.hpp"

Buffy::Buffy() : Humanoid(Field::BUFFY) {}

void Buffy::setAction(const Field &field) {

    if (field.hasVampireLeft()) {
        Humanoid *vam = field.nearestFrom(this, &Field::VAMPIRE);

        if (field.getDistance(this, vam) < 2) {
            action = std::make_unique<BuffyAttackAction>(this, vam);
        } else {
            action = std::make_unique<BuffyChaseAction>(this, vam);
        }

    } else {
        action = std::make_unique<RandomMoveAction>(this);
    }
}