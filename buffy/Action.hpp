#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "Field.hpp"

class Field;

class Action {

public:
    Action();
    virtual ~Action();
    void execute(Field& f);
};


#endif //BUFFY_ACTION_HPP
