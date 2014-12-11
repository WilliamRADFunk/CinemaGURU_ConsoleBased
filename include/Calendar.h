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
