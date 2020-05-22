//
// Created by simon on 08.05.20.
//

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP


#include "Humanoid.hpp"

class Buffy: public Humanoid {

public:
    Buffy(const HumanoidType &type);
    using Humanoid::setAction;
    void setAction(const Field &field) override;
    virtual ~Buffy();

    void setNewPosition() override;
};


#endif //BUFFY_BUFFY_HPP
