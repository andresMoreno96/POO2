#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human: public Humanoid {

public:
    Human();
    void die(Field& field) override;
    void setAction(const Field &field) override;
};

#endif //BUFFY_HUMAN_HPP
