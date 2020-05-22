#include <memory>
#include "Human.hpp"
#include "MoveAction.hpp"
#include "RandomMoveAction.hpp"

Human::Human(const HumanoidType &type) : Humanoid(type) {}

void Human::setAction(const Field &field) {
    action = std::make_unique<RandomMoveAction>(this);
}

void Human::setNewPosition() {

}

Human::~Human() {

}
