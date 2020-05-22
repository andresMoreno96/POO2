#include "Vampire.hpp"
#include "VampireAttackAction.hpp"
#include "MoveAction.hpp"
#include "VampireChaseAction.hpp"
#include "RandomMoveAction.hpp"

Vampire::Vampire(const HumanoidType &type) : Humanoid(type) {}

void Vampire::setAction(const Field &field)  {
    // S'il reste des humains, il attaque l'humain le plus proche,
    // autrement, il s'endort
    if(field.hasHumanLeft()) {
        action=std::make_unique<VampireChaseAction>(this);
    } else {
        action= std::make_unique<RandomMoveAction>(this);
    }
}

Vampire::~Vampire() {

}
