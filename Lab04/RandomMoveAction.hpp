#ifndef BUFFY_RANDOMMOVEACTION_HPP
#define BUFFY_RANDOMMOVEACTION_HPP

#include "MoveAction.hpp"

class RandomMoveAction : public MoveAction {

public:
    RandomMoveAction(Humanoid* humanoid);
    void execute(Field &f) override;
};

#endif //BUFFY_RANDOMMOVEACTION_HPP
