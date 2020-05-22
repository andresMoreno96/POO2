#ifndef BUFFY_VAMPIREATTACKACTION_HPP
#define BUFFY_VAMPIREATTACKACTION_HPP

#include "Action.hpp"

class VampireAttackAction : public Action {

public:
    VampireAttackAction(Humanoid* humanoid);
    void execute(Field& f);
};

#endif //BUFFY_VAMPIREATTACKACTION_HPP
