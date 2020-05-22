#ifndef BUFFY_BUFFYATTACKACTION_HPP
#define BUFFY_BUFFYATTACKACTION_HPP

#include "Action.hpp"

class BuffyAttackAction : public Action {

public:
    BuffyAttackAction(Humanoid& humanoid);
    void execute(Field& f);
};

#endif //BUFFY_BUFFYATTACKACTION_HPP
