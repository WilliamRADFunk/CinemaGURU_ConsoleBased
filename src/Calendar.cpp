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
        return Fall;
    }
    else
        {
            cout << "Error in getCurrentSeason/Week out of bounds." << endl;
            return Error;
        }
}

string Calendar::getCurrentSeasonString()
{
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
        return "Fall";
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

    if (Week % 53 == 0)
    {
        Year += 1;
        Week = 1;
    }

    CurrentSeason = getCurrentSeasonInt();
}
