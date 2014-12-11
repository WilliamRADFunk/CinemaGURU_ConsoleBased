#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Theater::Theater()
{
    cout << "Creating a theater >> Theater::Theater()" << endl;
    Movie* BlankScreen = new Movie;

    BlankScreen->setTitle("No Movie Playing");
    BlankScreen->setSynopsis("None");

    SelectedMovie = BlankScreen;

    cout << "Leaving theater creation" << endl;
    Divider();
}

Theater::~Theater()
{
    cout << "deleting theater" << endl;
    Divider();
}

void Theater::addScreenLevel()
{
    cout << "Utilyzing Theater::addScreenLevel()" << endl;
    cout << "The Screen Level was " << ScreenLevel << "." << endl;
    ScreenLevel += 0.1;
    cout << "The Screen Level is " << ScreenLevel << "." << endl;
    cout << "Leaving Theater::addScreenLevel()" << endl;
    Divider();
}

void Theater::addProjectorLevel()
{
    cout << "Utilyzing Theater::addProjectorLevel()" << endl;
    cout << "The Projector Level was " << ProjectorLevel << "." << endl;
    ProjectorLevel += 0.1;
    cout << "The Projector Level is " << ProjectorLevel << "." << endl;
    cout << "Leaving Theater::addProjectorLevel()" << endl;
    Divider();
}

void Theater::addSoundLevel()
{
    cout << "Utilyzing Theater::addSoundLevel()" << endl;
    cout << "The Sound Level was " << SoundLevel << "." << endl;
    SoundLevel += 0.1;
    cout << "The Sound Level is " << SoundLevel << "." << endl;
    cout << "Leaving Theater::addSoundLevel()" << endl;
    Divider();
}

void Theater::addSeats(int Seats)
{
    cout << "Utilyzing Theater::addSeats(int Seats)" << endl;
    cout << "The number of seats was " << NumOfSeats << "." << endl;
    NumOfSeats += Seats;
    cout << "The number of seats is " << NumOfSeats << "." << endl;
    cout << "Leaving Theater::addSeats(int Seats)" << endl;
    Divider();
}

void Theater::changeMovie(Movie* NewMovie)
{
    cout << "Utilyzing Theater::changeMovie(Movie* NewMovie)" << endl;
    cout << "The Selected Movie was " << SelectedMovie->getTitle() << "." << endl;
    if (NewMovie == NULL)
    {
        Movie* BlankScreen = new Movie;

        BlankScreen->setTitle("No Movie Playing");
        BlankScreen->setSynopsis("None");

        SelectedMovie = BlankScreen;
    }
    else SelectedMovie = NewMovie;
    cout << "The Selected Movie is " << SelectedMovie->getTitle() << "." << endl;
    cout << "Leaving Theater::changeMovie(Movie* NewMovie)" << endl;
    Divider();
}

Movie* Theater::getSelectedMovie()
{
    cout << "Utilyzing Theater::getSelectedMovie()" << endl;
    Divider();
    return SelectedMovie;
}

float Theater::getScreenLevel()
{
    cout << "Utilyzing Theater::ScreenLevel()" << endl;
    return ScreenLevel;
}

float Theater::getProjectorLevel()
{
    cout << "Utilyzing Theater::getProjectorLevel()" << endl;
    Divider();
    return ProjectorLevel;
}

float Theater::getSoundLevel()
{
    cout << "Utilyzing Theater::getSoundLevel()" << endl;
    Divider();
    return SoundLevel;
}

int Theater::getNumOfSeats()
{
    cout << "Utilyzing Theater::getNumOfSeats()" << endl;
    return NumOfSeats;
}

int Theater::getNumTicketsPurchased(float RandomAttendanceQuotient, float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)
{
    cout << "Utilyzing Theater::getNumTicketsPurchased(float RandomAttendanceQuotient, float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)" << endl;
    int TotalTicketsPurchased;

    if (SelectedMovie->getTitle() == "No Movie Playing")
    {
        return TotalTicketsPurchased = 0;
    }

    TotalTicketsPurchased = (int)(RandomAttendanceQuotient * TPriceFactor * SeasonFactor * ScreenLevel * ProjectorLevel *
                                  SoundLevel * PromoFactor * StaffFactor * NumOfSeats);

    cout << "Calculating total number of tickets purchased for the week in this theater." << endl;
    cout << RandomAttendanceQuotient << " * " << TPriceFactor << " * " << SeasonFactor << " * " << ScreenLevel << " * ";
    cout << ProjectorLevel << " * " << SoundLevel << " * " << PromoFactor << " * " << StaffFactor << " * " << NumOfSeats << " = ";
    cout << TotalTicketsPurchased;

    Divider();

    cout << "Determining if TotalTicketsPurchased is lower or higher than the MIN and MAX number of seats." << endl;

    if (TotalTicketsPurchased <= 1)
    {
        cout << "It was <= to 1 and therefore set to 1 and multiplied by seven days." << endl;
        cout << "Exiting Theater::getNumTicketsPurchased(float RandomAttendanceQuotient," << endl;
        cout << "float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)" << endl;
        Divider();
        return TotalTicketsPurchased = 1 * 7;
    }
    else if (TotalTicketsPurchased >= NumOfSeats)
    {
        cout << "It was >= NumOfSeats and therefore set to NumOfSeats and multiplied by seven days." << endl;
        cout << "Exiting Theater::getNumTicketsPurchased(float RandomAttendanceQuotient," << endl;
        cout << "float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)" << endl;
        Divider();
        return TotalTicketsPurchased = NumOfSeats * 7;
    }
    else
    {
        cout << "It was > 1 and < NumOfSeats, therefore TotalTicketsPurchased set to itself and multiplied by seven days." << endl;
        cout << "Exiting Theater::getNumTicketsPurchased(float RandomAttendanceQuotient," << endl;
        cout << "float TPriceFactor, float SeasonFactor, float PromoFactor, float StaffFactor)" << endl;
        Divider();
        return TotalTicketsPurchased * 7;
    }
}
