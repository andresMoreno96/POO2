#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

class Buffy: public Humanoid {

public:
    Buffy();
    using Humanoid::setAction;
    void setAction(const Field &field) override;
    virtual ~Buffy();


};


#endif //BUFFY_BUFFY_HPP
