//
// Created by simon on 08.05.20.
//

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP


#include "Humanoid.hpp"

class Vampire: public Humanoid {

public:
    Vampire(const HumanoidType &type);
    using Humanoid::setAction;
    void setAction(const Field &field) override;
    virtual ~Vampire();

    void setNewPosition() override;
};


#endif //BUFFY_VAMPIRE_HPP
