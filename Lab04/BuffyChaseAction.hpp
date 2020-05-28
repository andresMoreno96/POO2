/*
 * File:   BuffyChaseAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

#ifndef BUFFY_BUFFYCHASEACTION_HPP
#define BUFFY_BUFFYCHASEACTION_HPP

#include "MoveAction.hpp"

class BuffyChaseAction : public MoveAction {
    const Humanoid* target;
public:
    BuffyChaseAction(Humanoid* humanoid, const Humanoid* target);
    void execute(Field &f) override;
};


#endif //BUFFY_BUFFYCHASEACTION_HPP
