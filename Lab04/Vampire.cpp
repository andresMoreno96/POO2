#include "Vampire.hpp"
#include "VampireAttackAction.hpp"
#include "MoveAction.hpp"

Vampire::Vampire(const HumanoidType &type) : Humanoid(type) {}

void Vampire::setAction(const Field &field)  {
    // S'il reste des humains, il attaque l'humain le plus proche,
    // autrement, il s'endort
    if(field.hasHumanLeft()) {
        setAction(std::make_unique<VampireAttackAction>(*this));
    } else {
        setAction(std::make_unique<MoveAction>(*this));
    }
}

void Vampire::setNewPosition() {

}

Vampire::~Vampire() {

}
