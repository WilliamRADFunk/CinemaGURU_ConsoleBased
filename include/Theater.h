#ifndef THEATER_H
#define THEATER_H

#include <iostream>

#include "Cinema.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

class Theater
{
private:
    Movie* SelectedMovie;

    float ScreenLevel = 1.0;
    float ProjectorLevel = 1.0;
    float SoundLevel = 1.0;

    int NumOfSeats = SEATS_MIN;

public:
    Theater();
    ~Theater();

    void addScreenLevel();
    void addProjectorLevel();
    void addSoundLevel();
    void addSeats(int Seats);
    void changeMovie(Movie*);

    Movie* getSelectedMovie();
    float getScreenLevel();
    float getProjectorLevel();
    float getSoundLevel();
    int getNumOfSeats();
    int getNumTicketsPurchased(float, float, float, float, float);
};

#endif // THEATER_H
