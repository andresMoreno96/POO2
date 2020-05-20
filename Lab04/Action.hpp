#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "Field.hpp"

class Field;

class Action {

public:
    Action();
    void execute(Field& f);
    virtual ~Action();
};


#endif //BUFFY_ACTION_HPP
