#include "Buffy.hpp"
#include "AttackAction.hpp"
#include "RandomMoveAction.hpp"

Buffy::Buffy(const HumanoidType &type) : Humanoid(type) {}

void Buffy::setAction(const Field& field) {
    // Attaque le vampire le plus proche s'il en reste
    // autrement, se déplace aléatoirement
    if(field.hasVampireLeft()) {
        setAction(std::make_unique<AttackAction>(*this));
    } else {
        setAction(std::make_unique<RandomMoveAction>(*this));
    }
}

void Buffy::setNewPosition() {

}

Buffy::~Buffy() {

}
