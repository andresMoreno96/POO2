#include "Buffy.hpp"
#include "MoveAction.hpp"
#include "BuffyAttackAction.hpp"

Buffy::Buffy(const HumanoidType &type) : Humanoid(type) {}

void Buffy::setAction(const Field& field) {
    // Attaque le vampire le plus proche s'il en reste
    // autrement, se déplace aléatoirement
    if(field.hasVampireLeft()) {
        action = std::make_unique<BuffyAttackAction>(*this);
    } else {
        action = std::make_unique<MoveAction>(*this);
    }
}

void Buffy::setNewPosition() {

}

Buffy::~Buffy() {

}
