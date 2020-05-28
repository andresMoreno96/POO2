/*
 * File:   VampireChaseAction.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 22, 2020
 */

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
