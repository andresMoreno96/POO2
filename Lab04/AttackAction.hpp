#ifndef BUFFY_ATTACKACTION_HPP
#define BUFFY_ATTACKACTION_HPP

#include "Action.hpp"

class AttackAction : public Action {

public:
    AttackAction(Humanoid& humanoid);
    void execute(Field& f);
};

#endif //BUFFY_ATTACKACTION_HPP
