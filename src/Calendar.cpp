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

#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Calendar::Calendar()
{

}

Calendar::~Calendar()
{

}

int Calendar::getWeek()
{
    return Week;
}

int Calendar::getYear()
{
    return Year;
}

Season Calendar::getCurrentSeasonInt()
{
    // Each season has 13 weeks out of the year's 52.
    if (Week >= 1 && Week <= 13)
    {
        return Winter;
    }
    else if (Week >= 14 && Week <= 26)
    {
        return Spring;
    }
    else if (Week >= 27 && Week <= 40)
    {
        return Summer;
    }
    else if (Week >=41 && Week <= 52)
    {
        return Autumn;
    }
    else
    {
        cout << "Error in getCurrentSeason/Week out of bounds." << endl;
        return Error;
    }
}

string Calendar::getCurrentSeasonString()
{
    // Each season has 13 weeks out of the year's 52.
    if (Week >= 1 && Week <= 13)
    {
        return "Winter";
    }
    else if (Week >= 14 && Week <= 26)
    {
        return "Spring";
    }
    else if (Week >= 27 && Week <= 40)
    {
        return "Summer";
    }
    else if (Week >=41 && Week <= 52)
    {
        return "Autumn";
    }
    else
    {
        cout << "Error in getCurrentSeason/Week out of bounds." << endl;
        return "Error";
    }
}

void Calendar::nextWeek()
{
    Week += 1;

    // Check if it's a new year and sets variable accordingly.
    if (Week % 53 == 0)
    {
        Year += 1;
        Week = 1;
    }

    CurrentSeason = getCurrentSeasonInt();
}
