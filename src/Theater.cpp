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
    // Default movie details that will be inert for ticket purchase purposes.

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
    // If player chooses "None of these" when deciding on the movie to play in a theater,
    // NULL is entered and the inert details are placed into the variables.
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

    // If there's no movie playing, people are not going to buy tickets for that theater.
    if (SelectedMovie->getTitle() == "No Movie Playing")
    {
        return TotalTicketsPurchased = 0;
    }

    // Ticket price, Best or Worst Season, Screen size, Projector quality, Sound intensity, the promotion in effect,
    // the ratio of staff employed to total possible, and the number of seats are factored into values that range
    // anywhere from 0.1 to 2.0. These are multiplied against a random number between 0 and 1 to determine total tickets sold.
    TotalTicketsPurchased = (int)(RandomAttendanceQuotient * TPriceFactor * SeasonFactor * ScreenLevel * ProjectorLevel *
                                  SoundLevel * PromoFactor * StaffFactor * NumOfSeats);

    // At least one ticket is purchased each day for each theater playing a movie. Multiplied by seven days.
    // A theater can't sell more than the number of seats in the theater.
    // This also safeguards against improperly entered unreal numbers (ie -5, -2, -1000) or fractions.
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
