#ifndef RANDOMEVENTHANDLER_H
#define RANDOMEVENTHANDLER_H

#include <iostream>

#include "RandomEvent.h"
#include "Global.h"


class RandomEventHandler
{
private:
    RandomEvent* p_RandomEvents[RANDOM_EVENTS_MAX];
public:
    RandomEventHandler();
    ~RandomEventHandler();

    RandomEvent* getRandomEvent(int);
};

#endif // RANDOMEVENTHANDLER_H
