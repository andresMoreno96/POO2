#include <memory>
#include "Human.hpp"
#include "MoveAction.hpp"

Human::Human(const HumanoidType &type) : Humanoid(type) {}

void Human::setAction(const Field &field) {
    action = std::make_unique<MoveAction>(*this);
}

void Human::setNewPosition() {

}

Human::~Human() {

}
