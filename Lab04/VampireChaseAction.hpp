#ifndef BUFFY_VAMPIRECHASEACTION_HPP
#define BUFFY_VAMPIRECHASEACTION_HPP

#include "MoveAction.hpp"

class VampireChaseAction : public MoveAction {
    const Humanoid* target;
public:
    VampireChaseAction(Humanoid* humanoid,const Humanoid* target);
    void execute(Field &f) override;
};

#endif //BUFFY_VAMPIRECHASEACTION_HPP
