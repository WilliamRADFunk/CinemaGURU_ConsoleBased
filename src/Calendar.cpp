#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Calendar::Calendar()
{
    cout << "Creating a calendar >> Calendar::Calendar()" << endl;
    cout << "The Week is " << Week << ", and the year is " << Year << "." << endl;
    cout << "Leaving Calendar creation" << endl;
    Divider();
}

Calendar::~Calendar()
{
    cout << "Destroying Calendar" << endl;
    Divider();
}

int Calendar::getWeek()
{
    cout << "Utilyzing Calendar::getWeek()" << endl;
    return Week;
}

int Calendar::getYear()
{
    cout << "Utilyzing Calendar::getYear()" << endl;
    return Year;
}

Season Calendar::getCurrentSeasonInt()
{
    cout << "Entering Calendar::getCurrentSeasonInt()" << endl;
    cout << "Looking to see which season Week " << Week << " falls into..." << endl;
    if (Week >= 1 && Week <= 13)
    {
        cout << "Winter" << endl;
        return Winter;
    }
    else if (Week >= 14 && Week <= 26)
    {
        cout << "Spring" << endl;
        return Spring;
    }
    else if (Week >= 27 && Week <= 40)
    {
        cout << "Summer" << endl;
        return Summer;
    }
    else if (Week >=41 && Week <= 52)
    {
        cout << "Fall" << endl;
        return Fall;
    }
    else
        {
            cout << "Error in getCurrentSeason/Week out of bounds." << endl;
            return Error;
        }
    cout << "Leaving Calendar::getCurrentSeasonInt()" << endl;
    Divider();
}

string Calendar::getCurrentSeasonString()
{
    cout << "Entering Calendar::getCurrentSeasonString()" << endl;
    cout << "Looking to see which season Week " << Week << " falls into..." << endl;
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
    cout << "Leaving Calendar::getCurrentSeasonString()" << endl;
    Divider();
}

void Calendar::nextWeek()
{
    cout << "Utilyzing Calendar::nextWeek()" << endl;
    cout << "Increasing Week from " << Week << " to " << (Week + 1) << "." << endl;
    Week += 1;
    cout << "Week is now " << Week << "." << endl;

    cout << "Checking to see if it's the end of the year." << endl;
    if (Week % 53 == 0)
    {
        cout << "It is a new year!" << endl;
        Year += 1;
        Week = 1;
    }
    else cout << "It's not a new year." << endl;
    cout << "The Week is " << Week << ", and the year is " << Year << "." << endl;

    Divider();

    cout << "Calculating CurrentSeason" << endl;
    cout << "Previous Season was " << CurrentSeason << "." << endl;
    CurrentSeason = getCurrentSeasonInt();
    cout << "New season is " << CurrentSeason << "." << endl;

    cout << "Leaving Calendar::nextWeek()" << endl;

    Divider();
}
