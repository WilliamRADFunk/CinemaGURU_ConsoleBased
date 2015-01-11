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

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Calendar.h"
#include "Global.h"

class Movie
{
private:
    std::string Title = "Untitled";
    std::string Synopsis = "Not Available";

    int ExpectedPopularityRating = 1;
    int RealPopularityRating = 1;
    int UseOfLicenseRemainingInWeeks = 0;

    float CostOfLicensePerWeek = 0.0;

    Season BestSeason = Error;
    Season WorstSeason = Error;

public:
    Movie();
    ~Movie();

    // The following cluster of functions do exactly what their names imply.
    std::string getTitle();
    std::string getSynopsis();
    int getExpectedPopularityRating();
    int getRealPopularityRating();
    int getUseOfLicenseRemainingInWeeks();
    float getCostOfLicensePerWeek();
    Season getBestSeason();
    Season getWorstSeason();

    // The following cluster of functions do exactly what their names imply.
    void setTitle(std::string);
    void setSynopsis(std::string);
    void setExpectedPopularityRating(int);
    void setRealPopularityRating(int);
    void setUseOfLicenseRemainingInWeeks(int);
    void setCostOfLicensePerWeek(float);
    void setBestSeason(Season);
    void setWorstSeason(Season);

    // At the end of a turn, a movie's weeks until expiration is reduced by one.
    void reduceUseOfLicenseRemainingInWeeks();

    // Takes the enum value and converts it from type name to string name.
    std::string convertSeasonToString(Season);

    // Shows all the movies details in a formatted screen with the exception of "RealPopularityRating."
    void displayMovieDetails();
};

#endif // MOVIE_H
