/*
Created by William R.A.D. Funk
Game content written by William R.A.D. Funk
Design and code by William R.A.D. Funk
Documentation by William R.A.D. Funk

This game is the sole intellectual property of William R.A.D. Funk.
It is free-to-play, and distribution of the game is acceptable as long
as it remains free and that this multi-line comment is not altered in
any way.

Enjoy!
*/

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
