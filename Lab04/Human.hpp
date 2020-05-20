//
// Created by simon on 08.05.20.
//

#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP


#include "Humanoid.hpp"

class Human: public Humanoid {

public:
    Human(const Field &field, const HumanoidType &type);

    void setAction(const Field &field) override;

    void executeAction(Field &field) override;

    virtual ~Human();

    void setNewPosition() override;

};


#endif //BUFFY_HUMAN_HPP
