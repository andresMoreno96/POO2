#ifndef BUFFY_VAMPIRECHASEACTION_HPP
#define BUFFY_VAMPIRECHASEACTION_HPP

#include "MoveAction.hpp"

class VampireChaseAction : public MoveAction {

public:
    VampireChaseAction(Humanoid* humanoid);

    void execute(Field &f) override;
};

#endif //BUFFY_VAMPIRECHASEACTION_HPP
