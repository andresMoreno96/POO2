#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "Field.hpp"
#include "Humanoid.hpp"

class Field;
class Humanoid;

class Action {
    Humanoid& humanoid;
public:
    Action(Humanoid& humanoid);
    virtual void execute(Field& f) = 0;
    virtual ~Action();
};

#endif //BUFFY_ACTION_HPP
