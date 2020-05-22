#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"

class MoveAction : public Action {

public:
    MoveAction(Humanoid& humanoid);
    void execute(Field& f);
};

#endif //BUFFY_MOVEACTION_HPP
