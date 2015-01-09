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

Theater::Theater()
{
    Movie* BlankScreen = new Movie;

    BlankScreen->setTitle("No Movie Playing");
    BlankScreen->setSynopsis("None");

    SelectedMovie = BlankScreen;
}

Theater::~Theater()
{

}

void Theater::addScreenLevel()
{
    ScreenLevel += 0.1;
}

void Theater::addProjectorLevel()
{
    ProjectorLevel += 0.1;
}

void Theater::addSoundLevel()
{
    SoundLevel += 0.1;
}

void Theater::addSeats(int Seats)
{
    NumOfSeats += Seats;
}

void Theater::changeMovie(Movie* NewMovie)
{
    if (NewMovie == NULL)
    {
        Movie* BlankScreen = new Movie;

        BlankScreen->setTitle("No Movie Playing");
        BlankScreen->setSynopsis("None");

        SelectedMovie = BlankScreen;
    }
    else SelectedMovie = NewMovie;
}

Movie* Theater::getSelectedMovie()
{
    return SelectedMovie;
}

float Theater::getScreenLevel()
{
    return ScreenLevel;
}

float Theater::getProjectorLevel()
{
    return ProjectorLevel;
}

float Theater::getSoundLevel()
{
    return SoundLevel;
}

int Theater::getNumOfSeats()
{
    return NumOfSeats;
}

int Theater::getNumTicketsPurchased(float RandomAttendanceQuotient, float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)
{
    int TotalTicketsPurchased;

    if (SelectedMovie->getTitle() == "No Movie Playing")
    {
        return TotalTicketsPurchased = 0;
    }

    TotalTicketsPurchased = (int)(RandomAttendanceQuotient * TPriceFactor * SeasonFactor * ScreenLevel * ProjectorLevel *
                                  SoundLevel * PromoFactor * StaffFactor * NumOfSeats);

    if (TotalTicketsPurchased <= 1)
    {
        return TotalTicketsPurchased = 1 * 7;
    }
    else if (TotalTicketsPurchased >= NumOfSeats)
    {
        return TotalTicketsPurchased = NumOfSeats * 7;
    }
    else
    {
        return TotalTicketsPurchased * 7;
    }
}
