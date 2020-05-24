#include <iostream>
#include "Vampire.hpp"
#include "VampireAttackAction.hpp"
#include "MoveAction.hpp"
#include "VampireChaseAction.hpp"
#include "RandomMoveAction.hpp"

Vampire::Vampire(const HumanoidType &type) : Humanoid(type) {}

void Vampire::setAction(const Field &field)  {

    if (field.hasHumanLeft()) {
        Humanoid *hum = field.nearestFrom(this, &Field::HUMAN);

        if (field.getDistance(this, hum) < 2) {
            action = std::make_unique<VampireAttackAction>(this, hum);
        } else{
            action=std::make_unique<VampireChaseAction>(this);
        }
    } else{
        //FIXME: THIS SHOULD BE SLEEP
        action= std::make_unique<RandomMoveAction>(this);
    }

}

Vampire::~Vampire() {
    std::cout<<"kill vamp "<<std::endl;
}
