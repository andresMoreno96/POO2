#ifndef BUFFY_BUFFYCHASEACTION_HPP
#define BUFFY_BUFFYCHASEACTION_HPP

#include "MoveAction.hpp"

class BuffyChaseAction : public MoveAction {

private:
    const Humanoid* target;

public:


    BuffyChaseAction(Humanoid* humanoid, const Humanoid* target);

    void execute(Field &f) override;

};


#endif //BUFFY_BUFFYCHASEACTION_HPP
