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
    // Ensures the incoming value does not go above or below acceptable values.
    // This is a "soft" error handling method in case player edits the movieData txt file incorrectly.
    if (Pop >= 5)
        ExpectedPopularityRating = 5;
    else if (Pop <= 1)
        ExpectedPopularityRating = 1;
    else ExpectedPopularityRating = Pop;
}

void Movie::setRealPopularityRating(int Pop)
{
    // Ensures the incoming value does not go above or below acceptable values.
    // This is a "soft" error handling method in case player edits the movieData txt file incorrectly.
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
    // Displaying the title. The varying length of the title requires an adjustable format.
    locale loc1;
    char c;

    string OriginalTitle = "Title: ";
    OriginalTitle.append(Title);

    string StringTitle1;

    for (unsigned int i = 0, j = 0, k = 0; i < OriginalTitle.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of characters in each string.
        c = OriginalTitle[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 57)
        {
            j = 0;
            i++;
        }
        // Fills StringTitle1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 57)
        {
            if (j >= 50 && !isspace(c,loc1))
            {
                StringTitle1 += OriginalTitle[i];
                i++;
                if ( i >= OriginalTitle.length() )
                {
                    for (; j < 71; j++)
                    {
                        StringTitle1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc1))
            {
                StringTitle1 += " ";
            }
            else
            {
                StringTitle1 += OriginalTitle[i];
                i++;
                if ( i >= OriginalTitle.length() )
                {
                    for (; j < 71; j++)
                    {
                        StringTitle1 += " ";
                    }
                }
            }
        }
        j++;
        k++;
    }
    cout << "X";
    BlankSpaces(5);
    cout << StringTitle1;
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Synopsis: ";
    // Displaying the Synopsis. The varying length of the title requires an adjustable format.
    locale loc2;
    char d;

    string StringSynopsis1 = "";
    string StringSynopsis2 = "";
    string StringSynopsis3 = "";
    string StringSynopsis4 = "";
    string StringSynopsis5 = "";

    for (unsigned int i = 0, j = 0, k = 0; i < Synopsis.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of characters in each string.
        d = Synopsis[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 62)
        {
            j = 0;
            i++;
        }
        // Fills StringSynopsis1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 62)
        {
            if (j >= 44 && !isspace(d,loc2))
            {
                StringSynopsis1 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis1 += " ";
                    }
                }
            }
            else if (j >= 44 && isspace(d,loc2))
            {
                StringSynopsis1 += " ";
            }
            else
            {
                StringSynopsis1 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis1 += " ";
                    }
                }
            }
        }
        // Fills StringSynopsis2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 62 && k < 124)
        {
            if (j >= 44 && !isspace(d,loc2))
            {
                StringSynopsis2 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis2 += " ";
                    }
                }
            }
            else if (j >= 44 && isspace(d,loc2))
            {
                StringSynopsis2 += " ";
            }
            else
            {
                StringSynopsis2 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis2 += " ";
                    }
                }
            }
        }
        // Fills StringSynopsis3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 124 && k < 186)
        {
            if (j >= 44 && !isspace(d,loc2))
            {
                StringSynopsis3 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis3 += " ";
                    }
                }
            }
            else if (j >= 44 && isspace(d,loc2))
            {
                StringSynopsis3 += " ";
            }
            else
            {
                StringSynopsis3 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis3 += " ";
                    }
                }
            }
        }
        // Fills StringSynopsis4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 186 && k < 248)
        {
            if (j >= 44 && !isspace(d,loc2))
            {
                StringSynopsis4 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis4 += " ";
                    }
                }
            }
            else if (j >= 44 && isspace(d,loc2))
            {
                StringSynopsis4 += " ";
            }
            else
            {
                StringSynopsis4 += Synopsis[i];
                i++;
                if ( i >= Synopsis.length() )
                {
                    for (; j < 61; j++)
                    {
                        StringSynopsis4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The Synopsis string is too long." << endl;
            StringSynopsis5 += Synopsis[i];
        }
        j++;
        k++;
    }
    cout << StringSynopsis1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (StringSynopsis2 != "")
    {
        cout << "X";
        BlankSpaces(15);
        cout << StringSynopsis2 << "X" << endl;
    }
    if (StringSynopsis3 != "")
    {
        cout << "X";
        BlankSpaces(15);
        cout << StringSynopsis3 << "X" << endl;
    }
    if (StringSynopsis4 != "")
    {
        cout << "X";
        BlankSpaces(15);
        cout << StringSynopsis4 << "X" << endl;
    }
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    // Displaying the Expected Popularity. The varying length of the title requires an adjustable format.
    cout << "Expected Popularity: " << ExpectedPopularityRating << "/5 (May turn out higher or lower)";
    BlankSpaces(17);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    // Displaying the Optimal Season. The varying length of the title requires an adjustable format.
    cout << "Optimal Season: " << convertSeasonToString(BestSeason);
    BlankSpaces(50);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    // Displaying the Worst Season. The varying length of the title requires an adjustable format.
    cout << "Worst Season: " << convertSeasonToString(WorstSeason);
    BlankSpaces(52);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    // Displaying the Cost of License. The varying length of the title requires an adjustable format.
    cout << "Cost of License: $" << CostOfLicensePerWeek;
    if (CostOfLicensePerWeek < 10)
    {
        BlankSpaces(50);
    }
    else if (CostOfLicensePerWeek >= 10 && CostOfLicensePerWeek < 100)
    {
        BlankSpaces(49);
    }
    else if (CostOfLicensePerWeek >= 100 && CostOfLicensePerWeek < 1000)
    {
        BlankSpaces(48);
    }
    else if (CostOfLicensePerWeek >= 1000 && CostOfLicensePerWeek < 10000)
    {
        BlankSpaces(47);
    }
    else if (CostOfLicensePerWeek >= 10000 && CostOfLicensePerWeek < 100000)
    {
        BlankSpaces(46);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    // Displaying the Length of License. The varying length of the title requires an adjustable format.
    cout << "Length of License: " << UseOfLicenseRemainingInWeeks << " Weeks";
    if (UseOfLicenseRemainingInWeeks < 10)
    {
        BlankSpaces(46);
    }
    else if (UseOfLicenseRemainingInWeeks >= 10 && UseOfLicenseRemainingInWeeks < 100)
    {
        BlankSpaces(45);
    }
    else if (UseOfLicenseRemainingInWeeks >= 100 && UseOfLicenseRemainingInWeeks < 1000)
    {
        BlankSpaces(44);
    }
    cout << "X" << endl;
}
