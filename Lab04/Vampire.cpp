//
// Created by simon on 08.05.20.
//

#include "Vampire.hpp"
#include "AttackAction.hpp"
#include "RandomMoveAction.hpp"

Vampire::Vampire(const HumanoidType &type) : Humanoid(type) {}

void Vampire::setAction(const Field &field)  {
    // S'il reste des humains, il attaque l'humain le plus proche,
    // autrement, il s'endort
    if(field.hasHumanLeft()) {
        setAction(std::make_unique<AttackAction>(*this));
    } else {
        setAction(std::make_unique<RandomMoveAction>(*this));
    }
}

void Vampire::setNewPosition() {

}

Vampire::~Vampire() {

}
