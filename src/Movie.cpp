#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Movie::Movie()
{
    cout << "Creating a movie" << endl;
    cout << "Leaving Movie creation" << endl;
    Divider();
}

Movie::~Movie()
{
    cout << "deleting movie" << endl;
    Divider();
}

string Movie::getTitle()
{
    cout << "Utilyzing Movie::getTitle()" << endl;
    return Title;
}

string Movie::getSynopsis()
{
    cout << "Utilyzing Movie::getSynopsis()" << endl;
    return Synopsis;
}

int Movie::getExpectedPopularityRating()
{
    cout << "Utilyzing Movie::getExpectedPopularityRating()" << endl;
    return ExpectedPopularityRating;
}

int Movie::getRealPopularityRating()
{
    cout << "Utilyzing Movie::getRealPopularityRating()" << endl;
    return RealPopularityRating;
}

int Movie::getUseOfLicenseRemainingInWeeks()
{
    cout << "Utilyzing Movie::getUseOfLicenseRemainingInWeeks()" << endl;
    return UseOfLicenseRemainingInWeeks;
}

float Movie::getCostOfLicensePerWeek()
{
    cout << "Utilyzing Movie::getCostOfLicensePerWeek()" << endl;
    return CostOfLicensePerWeek;
}

Season Movie::getBestSeason()
{
    cout << "Utilyzing Movie::getBestSeason()" << endl;
    return BestSeason;
}

Season Movie::getWorstSeason()
{
    cout << "Utilyzing Movie::getWorstSeason()" << endl;
    return WorstSeason;
}

void Movie::setTitle(string Name)
{
    cout << "Utilyzing Movie::setTitle(string Name)" << endl;
    Title = Name;
    cout << "The Movie's title is now: " << Title << endl;
    cout << "Leaving Movie::setTitle(string Name)" << endl;
}

void Movie::setSynopsis(string Descrip)
{
    cout << "Utilyzing Movie::setSynopsis(string Descrip)" << endl;
    Synopsis = Descrip;
    cout << "The Movie's synopsis is now: " << endl << Synopsis << endl;
    cout << "Leaving Movie::setSynopsis(string Descrip)" << endl;
}

void Movie::setExpectedPopularityRating(int Pop)
{
    cout << "Utilyzing Movie::setExpectedPopularityRating(int Pop)" << endl;
    cout << "The Movie's expected popularity rating was: " << ExpectedPopularityRating << endl;
    if (Pop >= 5)
        ExpectedPopularityRating = 5;
    else if (Pop <= 1)
        ExpectedPopularityRating = 1;
    else ExpectedPopularityRating = Pop;
    cout << "The Movie's expected popularity rating is now: " << ExpectedPopularityRating << endl;
    cout << "Leaving Movie::setExpectedPopularityRating(int Pop)" << endl;
}

void Movie::setRealPopularityRating(int Pop)
{
    cout << "Utilyzing Movie::setRealPopularityRating(int Pop)" << endl;
    cout << "The Movie's real popularity rating was: " << RealPopularityRating << endl;
    if (Pop >= 5)
        RealPopularityRating = 5;
    else if (Pop <= 1)
        RealPopularityRating = 1;
    else RealPopularityRating = Pop;
    cout << "The Movie's real popularity rating is now: " << RealPopularityRating << endl;
    cout << "Leaving Movie::setRealPopularityRating(int Pop)" << endl;
}

void Movie::setUseOfLicenseRemainingInWeeks(int LicPeriod)
{
    cout << "Utilyzing Movie::setUseOfLicenseRemainingInWeeks(int LicPeriod)" << endl;
    UseOfLicenseRemainingInWeeks = LicPeriod;
    cout << "The Movie's remaining license is now: " << UseOfLicenseRemainingInWeeks << " weeks." << endl;
    cout << "Leaving Movie::setUseOfLicenseRemainingInWeeks(int LicPeriod)" << endl;
}

void Movie::adjustUseOfLicenseRemainingInWeeks()
{
    cout << "Utilyzing Movie::adjustUseOfLicenseRemainingInWeeks()" << endl;
    cout << "The Movie's remaining license was: " << UseOfLicenseRemainingInWeeks << " weeks." << endl;
    UseOfLicenseRemainingInWeeks--;
    cout << "The Movie's remaining license is now: " << UseOfLicenseRemainingInWeeks << " weeks." << endl;
    cout << "Leaving Movie::adjustUseOfLicenseRemainingInWeeks()" << endl;
}

void Movie::setCostOfLicensePerWeek(float Cost)
{
    cout << "Utilyzing Movie::setCostOfLicensePerWeek(float Cost)" << endl;
    CostOfLicensePerWeek = Cost;
    cout << "The Movie's license cost is now: $" << Cost << endl;
    cout << "Leaving Movie::setCostOfLicensePerWeek(float Cost)" << endl;
}

void Movie::setBestSeason(Season Best)
{
    cout << "Utilyzing Movie::setBestSeason(Season Best)" << endl;
    BestSeason = Best;
    cout << "The Movie's optimal season is now: " << BestSeason << endl;
    cout << "Leaving Movie::setBestSeason(Season Best)" << endl;
}

void Movie::setWorstSeason(Season Worst)
{
    cout << "Utilyzing Movie::setWorstSeason(Season Worst)" << endl;
    WorstSeason = Worst;
    cout << "The Movie's least favorable season is now: " << WorstSeason << endl;
    cout << "Leaving Movie::setWorstSeason(Season Worst)" << endl;
}

void Movie::reduceUseOfLicenseRemainingInWeeks()
{
    cout << "Utilyzing Movie::reduceUseOfLicenseRemainingInWeeks()" << endl;
    UseOfLicenseRemainingInWeeks--;
    cout << "The Movie's remaining license is now: " << UseOfLicenseRemainingInWeeks << " weeks." << endl;
    cout << "Leaving Movie::reduceUseOfLicenseRemainingInWeeks()" << endl;
}

string Movie::convertSeasonToString(Season Season)
{
    cout << "Entering Movie::convertSeasonToString(Season Season)" << endl;
    if (Season == 0)
    {
        return "Winter";
    }
    else if (Season == 1)
    {
        return "Spring";
    }
    else if (Season == 2)
    {
        return "Summer";
    }
    else if (Season == 3)
    {
        return "Fall";
    }
    else
        {
            cout << "Error in getCurrentSeason/Week out of bounds." << endl;
            return "Error";
        }
    cout << "Leaving Movie::convertSeasonToString(Season Season)" << endl;
}

void Movie::displayMovieDetails()
{
    cout << "Title: " << Title << endl << endl;
    cout << "Synipsis: " << Synopsis << endl << endl;
    cout << "Expected Popularity: " << ExpectedPopularityRating << "/5 (May turn out higher or lower)" << endl;
    cout << "Optimal Season: " << convertSeasonToString(BestSeason) << endl;
    cout << "Worst Season: " << convertSeasonToString(WorstSeason) << endl;
    cout << "Cost of License: $" << CostOfLicensePerWeek << endl;
    cout << "Length of License: " << UseOfLicenseRemainingInWeeks << " Weeks" << endl;
}
