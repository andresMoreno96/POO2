#ifndef BUFFY_BUFFYATTACKACTION_HPP
#define BUFFY_BUFFYATTACKACTION_HPP

#include "Action.hpp"

class BuffyAttackAction : public Action {
private:
    Humanoid *target;

public:
    BuffyAttackAction(Humanoid* humanoid, Humanoid* target);
    void execute(Field& f);
};

#endif //BUFFY_BUFFYATTACKACTION_HPP
