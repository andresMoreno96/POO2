#include "Buffy.hpp"
#include "MoveAction.hpp"
#include "BuffyAttackAction.hpp"
#include "RandomMoveAction.hpp"
#include "BuffyChaseAction.hpp"

Buffy::Buffy(const HumanoidType &type) : Humanoid(type) {}

void Buffy::setAction(const Field& field) {
    // Attaque le vampire le plus proche s'il en reste
    // autrement, se déplace aléatoirement
    if(field.hasVampireLeft()) {
        action = std::make_unique<BuffyChaseAction>(this);
    } else {
        action = std::make_unique<RandomMoveAction>(this);
    }
}

void Buffy::setNewPosition() {

}

Buffy::~Buffy() {

}
