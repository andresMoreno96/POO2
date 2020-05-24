#include <iostream>
#include "Buffy.hpp"
#include "MoveAction.hpp"
#include "BuffyAttackAction.hpp"
#include "RandomMoveAction.hpp"
#include "BuffyChaseAction.hpp"

Buffy::Buffy(const HumanoidType &type) : Humanoid(type) {}

void Buffy::setAction(const Field &field) {
    // Attaque le vampire le plus proche s'il en reste
    // autrement, se déplace aléatoirement
    if (field.hasVampireLeft()) {
        Humanoid *vam = field.nearestFrom(this, &Field::VAMPIRE);

        if (field.getDistance(this, vam) < 2) {
            std::cout<<"buffy attack"<<std::endl;
            action = std::make_unique<BuffyAttackAction>(this, vam);
        } else {
            std::cout<<"buffy chase"<<std::endl;
            action = std::make_unique<BuffyChaseAction>(this, vam);
        }

    } else {
        std::cout<<"there are no more vampires"<<std::endl;
        action = std::make_unique<RandomMoveAction>(this);
    }
}


Buffy::~Buffy() {

}
