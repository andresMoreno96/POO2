#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "Field.hpp"
#include "Humanoid.hpp"

class Field;
class Humanoid;

class Action {

protected:
    Humanoid* humanoid;
public:
    Action(Humanoid* humanoid);
    virtual ~Action();
    virtual void execute(Field& f) = 0;
};

#endif //BUFFY_ACTION_HPP
