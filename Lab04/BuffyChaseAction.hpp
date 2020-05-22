#ifndef BUFFY_BUFFYCHASEACTION_HPP
#define BUFFY_BUFFYCHASEACTION_HPP

#include "MoveAction.hpp"

class BuffyChaseAction : public MoveAction {

public:


    BuffyChaseAction(Humanoid* humanoid);

    void execute(Field &f) override;

};


#endif //BUFFY_BUFFYCHASEACTION_HPP
