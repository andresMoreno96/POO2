#include <iostream>
#include "Vampire.hpp"
#include "VampireAttackAction.hpp"
#include "VampireChaseAction.hpp"

Vampire::Vampire() : Humanoid(Field::VAMPIRE) {}

void Vampire::setAction(const Field &field)  {

    if (field.hasHumanLeft()) {

        Humanoid *hum = field.nearestFrom(this, &Field::HUMAN);

        if (field.getDistance(this, hum) < 2) { //FIXME: MAGIC NUMB
            action = std::make_unique<VampireAttackAction>(this, hum);
        } else{
            action=std::make_unique<VampireChaseAction>(this,hum);
        }
    } else {
        // the vampire sleeps
        action = nullptr;
    }

}

void Vampire::die(Field& field) {
    if(isAlive()) {
        field.setNbVampires(field.getNbVampires() - 1);
    }

    Humanoid::die(field);
}
