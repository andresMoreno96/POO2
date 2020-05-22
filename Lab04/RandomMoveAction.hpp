#ifndef BUFFY_RANDOMMOVEACTION_HPP
#define BUFFY_RANDOMMOVEACTION_HPP

#include "Action.hpp"

class RandomMoveAction : public Action {

public:
    RandomMoveAction(Humanoid& humanoid);
    void execute(Field& f);
};

#endif //BUFFY_RANDOMMOVEACTION_HPP
