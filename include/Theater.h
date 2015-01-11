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

    // These are the three upgradeable pieces of equipment that each directly
    // affect factors used to calculate ticket sales each turn.
    float ScreenLevel = 1.0;
    float ProjectorLevel = 1.0;
    float SoundLevel = 1.0;
    // Each theater starts with a minimum number of seats.
    int NumOfSeats = SEATS_MIN;

public:
    Theater();
    ~Theater();
    // These three functions upgrade their respective pieces of equipment by 0.1.
    void addScreenLevel();
    void addProjectorLevel();
    void addSoundLevel();
    // Increases the theater's number of seats by the amount entered.
    void addSeats(int Seats);
    // Switches which movie is currently playing in the given theater.
    void changeMovie(Movie*);
    // Pulls the movie object playing in the given theater in order to access it's data.
    Movie* getSelectedMovie();
    // These four functions do exactly what their names imply.
    float getScreenLevel();
    float getProjectorLevel();
    float getSoundLevel();
    int getNumOfSeats();
    // Takes in all the relevant factors to calculate the total number of tickets purchased that turn.
    int getNumTicketsPurchased(float, float, float, float, float);
};

#endif // THEATER_H
