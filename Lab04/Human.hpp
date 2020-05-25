#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human: public Humanoid {

public:
    Human(const HumanoidType &type);
    using Humanoid::setAction;
    void setAction(const Field &field) override;
    virtual ~Human();

    void die(Field& field) override;

};


#endif //BUFFY_HUMAN_HPP
