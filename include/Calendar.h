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

#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Global.h"

class Calendar
{
private:
    int Week = 1;
    int Year = 1;

    Season CurrentSeason = Winter;

public:
    Calendar();
    ~Calendar();

    int getWeek();
    int getYear();
    Season getCurrentSeasonInt();
    std::string getCurrentSeasonString();
    void nextWeek();
};

#endif // CALENDAR_H
