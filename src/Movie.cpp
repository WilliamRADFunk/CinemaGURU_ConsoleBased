#include <iostream>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Movie::Movie()
{

}

Movie::~Movie()
{

}

string Movie::getTitle()
{
    return Title;
}

string Movie::getSynopsis()
{
    return Synopsis;
}

int Movie::getExpectedPopularityRating()
{
    return ExpectedPopularityRating;
}

int Movie::getRealPopularityRating()
{
    return RealPopularityRating;
}

int Movie::getUseOfLicenseRemainingInWeeks()
{
    return UseOfLicenseRemainingInWeeks;
}

float Movie::getCostOfLicensePerWeek()
{
    return CostOfLicensePerWeek;
}

Season Movie::getBestSeason()
{
    return BestSeason;
}

Season Movie::getWorstSeason()
{
    return WorstSeason;
}

void Movie::setTitle(string Name)
{
    Title = Name;
}

void Movie::setSynopsis(string Descrip)
{
    Synopsis = Descrip;
}

void Movie::setExpectedPopularityRating(int Pop)
{
    if (Pop >= 5)
        ExpectedPopularityRating = 5;
    else if (Pop <= 1)
        ExpectedPopularityRating = 1;
    else ExpectedPopularityRating = Pop;
}

void Movie::setRealPopularityRating(int Pop)
{
    if (Pop >= 5)
        RealPopularityRating = 5;
    else if (Pop <= 1)
        RealPopularityRating = 1;
    else RealPopularityRating = Pop;
}

void Movie::setUseOfLicenseRemainingInWeeks(int LicPeriod)
{
    UseOfLicenseRemainingInWeeks = LicPeriod;
}

void Movie::adjustUseOfLicenseRemainingInWeeks()
{
    UseOfLicenseRemainingInWeeks--;
}

void Movie::setCostOfLicensePerWeek(float Cost)
{
    CostOfLicensePerWeek = Cost;
}

void Movie::setBestSeason(Season Best)
{
    BestSeason = Best;
}

void Movie::setWorstSeason(Season Worst)
{
    WorstSeason = Worst;
}

void Movie::reduceUseOfLicenseRemainingInWeeks()
{
    UseOfLicenseRemainingInWeeks--;
}

string Movie::convertSeasonToString(Season Season)
{
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
        return "Autumn";
    }
    else
        {
            cout << "Error in getCurrentSeason/Week out of bounds." << endl;
            return "Error";
        }
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
