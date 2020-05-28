/*
 * File:   Buffy.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 20, 2020
 */

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

class Buffy: public Humanoid {

public:
    Buffy();
    void setAction(const Field &field) override;
};


#endif //BUFFY_BUFFY_HPP
