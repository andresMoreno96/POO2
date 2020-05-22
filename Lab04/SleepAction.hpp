#ifndef BUFFY_SLEEPACTION_HPP
#define BUFFY_SLEEPACTION_HPP

#include "Action.hpp"

class SleepAction : public Action {

public:
    SleepAction(Humanoid& humanoid);
    void execute(Field& f);
};

#endif //BUFFY_SLEEPACTION_HPP
