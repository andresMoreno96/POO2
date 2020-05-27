#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire: public Humanoid {

public:
    Vampire();
    void die(Field& field) override;
    void setAction(const Field &field) override;
};


#endif //BUFFY_VAMPIRE_HPP
