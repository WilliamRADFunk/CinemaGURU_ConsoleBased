#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <math.h>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

using namespace std;

Cinema::Cinema()
{
    Bank = 200200.00;
    TPrice = 10.00;
    NumOfTheaters = 1;
    NumOfEmployees = 1;
    EmployeesMax = 5;
    NumOfSnacks = 2;
    NumOfMovieLicenses = 1;
    PromotionSelected = 0;
    TotalNumOfSeats = 10;
    Expenses = 0.0;
    TicketSales = 0.0;
    SnackSales = 0.0;
    StaffPerformance = "Dismal";
    PromotionInUse = "None";

    Calendar* TheCalendar = new Calendar();
    p_Calendar = TheCalendar;

    // Filling the theater array with new theaters.
    for (int i = 0; i < THEATERS_MAX; i++)
    {
        p_Theaters[i] = new Theater;
    }

    // Filling the movie array with new movies.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        p_Movies[i] = new Movie;
    }

    // Takes info about all movies from file, and creates all the movies, placing them in the movie array.
	ifstream infile;
	infile.open ("MovieData.txt");
        for (int i = 0; i < MOVIES_MAX; i++)
        {
            string STRING;
            int INTEGER, SEASON, FLOAT;

            if (infile.eof())
            {
                break;
            }

            for (int j = 0; j < 8; j++)
            {
                // Leaves for-loop if end-of-file is reached.
                if (infile.eof())
                {
                    break;
                }
                //Each movie has 8 lines of ordered info. The following assigns each piece of data to it's correct variable.
                if (j == 0)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    p_Movies[i]->setTitle(STRING);
                }
                else if (j == 1)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    p_Movies[i]->setSynopsis(STRING);
                }
                else if (j == 2)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setExpectedPopularityRating(INTEGER);
                }
                else if (j == 3)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setRealPopularityRating(INTEGER);
                }
                else if (j == 4)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to SEASON.
                    if ( !(convert >> SEASON) )
                    SEASON = 0;
                    p_Movies[i]->setBestSeason((Season)SEASON);
                }
                else if (j == 5)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to SEASON.
                    if ( !(convert >> SEASON) )
                    SEASON = 0;
                    p_Movies[i]->setWorstSeason((Season)SEASON);
                }
                else if (j == 6)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to FLOAT.
                    if ( !(convert >> FLOAT) )
                    FLOAT = 0;
                    p_Movies[i]->setCostOfLicensePerWeek((float)FLOAT);
                }
                else if (j == 7)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setUseOfLicenseRemainingInWeeks(INTEGER);
                }
                else cout << "ERROR: reading data from file and conversion failure." << endl;
            }
        }
	infile.close();

	// Filling the movie licenses array with new movies.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        p_MovieLicenses[i] = new Movie;
    }

    // Filling the movie licenses offered array with new movies.
    for (int i = 0; i < 3; i++)
    {
        p_MovieLicensesOffered[i] = new Movie;
    }

    // Assign free movie to the p_MovieLicenses[0].
    p_MovieLicenses[0] = p_Movies[0];

    int LicenseOffered = 0;
    for (int i = 0; i < OFFERED_LICENSES_MAX; i++)
    {
        // Ensures number picked doesn't include a number already on the list.
        do
        {
            // Random number between 1-19.
            LicenseOffered = (rand()% (MOVIES_MAX - 1)) + 1;
        } while ( !(checkPreviousLicenseMatch(LicenseOffered)) );

        // Assigns the chosen movie to the offered movie array,
        // and records number in Displayed index for matching purposes.
        p_MovieLicensesOffered[i] = p_Movies[LicenseOffered];
        DisplayedMovieLicenses[i] = LicenseOffered;
    }
}

Cinema::~Cinema()
{
    for (int i = 0; i < THEATERS_MAX; i++)
    {
        p_Theaters[i]->~Theater();
        p_Theaters[i] = 0;
    }

    for (int i = 0; i < MOVIES_MAX; i++)
    {
        p_Movies[i]->~Movie();
        p_Movies[i] = 0;
    }

    for (int i = 0; i < MOVIES_MAX; i++)
    {
        p_MovieLicenses[i] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        p_MovieLicensesOffered[i] = 0;
    }
}


float Cinema::getBank()
{
    return Bank;
}

float Cinema::getExpenses()
{
    return Expenses;
}

float Cinema::getTicketSales()
{
    return TicketSales;
}

float Cinema::getSnackSales()
{
    return SnackSales;
}

float Cinema::getTicketPrice()
{
    return TPrice;
}

int Cinema::getNumOfTheaters()
{
    return NumOfTheaters;
}

int Cinema::getTotalNumOfSeats()
{
    int TotalSeats = 0;
    for (int i = 0; i < NumOfTheaters; i++)
    {
        TotalSeats += p_Theaters[i]->getNumOfSeats();
    }
    return TotalSeats;
}

int Cinema::getNumOfMovieLicenses()
{
    return NumOfMovieLicenses;
}

int Cinema::getNumOfEmployees()
{
    return NumOfEmployees;
}

int Cinema::getNumOfSnacks()
{
    return NumOfSnacks;
}

int Cinema::getPromotionSelected()
{
    return PromotionSelected;
}

int Cinema::getDisplayedMovieLicenses(int index)
{
    return DisplayedMovieLicenses[index];
}

string Cinema::getStaffPerformance()
{
    return StaffPerformance;
}

string Cinema::getPromotionInUse()
{
    return PromotionInUse;
}

void Cinema::hud()
{
    cout << "Week: " << p_Calendar->getWeek() << "/52  Season: " << p_Calendar->getCurrentSeasonString() << "  Year: ";
    cout << p_Calendar->getYear() << endl << endl;
    cout << "You have:" << endl << "Bank: $" << Bank << endl;
    cout << "Theaters: " << NumOfTheaters << "/" << THEATERS_MAX << endl;
    cout << "Total Seats: " << getTotalNumOfSeats() << "/" << (NumOfTheaters * 100) << endl;
    cout << "Total Licenses: " << NumOfMovieLicenses << endl;
    cout << "Total Employees: " << NumOfEmployees << "/" << (NumOfTheaters * 5) << " (" << StaffPerformance << ")" << endl;
    cout << "Total Snack Types: " << NumOfSnacks << "/" << SNACK_MAX << endl;
    cout << "Current Promotion in use: " << PromotionInUse << endl;
    cout << "Current Ticket Price: $" << TPrice << endl;
    cout << "Total $ From Ticket Sales Last Week: $" << TicketSales << endl;
    cout << "Total $ From Food Sales Last Week: $" << SnackSales << endl;
    cout << "Total $ For Expenses Last Week: $" << Expenses << endl;
    cout << "Total $ in Profit/(Loss): $";
    if (((TicketSales + SnackSales) - (Expenses)) < 0)
    {
        cout << "(" << fabs((TicketSales + SnackSales) - (Expenses)) << ")" << endl;
    }
    else
    {
        cout << ((TicketSales + SnackSales) - (Expenses)) << endl;
    }
}

void Cinema::addTheater()
{
    NumOfTheaters += 1;
}

void Cinema::changePromotionSelected(int NewPromotion)
{
    PromotionSelected = NewPromotion;
}

void Cinema::changeTicketPrice(float newPrice)
{
    TPrice = newPrice;
}

void Cinema::adjustBank(int Transaction)
{
    Bank += Transaction;
}

void Cinema::adjustExpenses(int Rent, int Wages)
{
    Expenses = Rent + Wages + (PROMOTION_MULTIPLY_COST * PromotionSelected);
    // Round to the nearest penny.
    Expenses = float(int(Expenses * 100 + 0.5)) / 100;
    Bank -= Expenses;
}

void Cinema::adjustTicketSales(int TicketsSold)
{
    TicketSales = TicketsSold * TPrice;
    // Round to the nearest penny.
    TicketSales = float(int(TicketSales * 100 + 0.5)) / 100;
    Bank += TicketSales;
}

void Cinema::adjustSnackSales(float SnacksSold)
{
    SnackSales = SnacksSold;
    // Round to the nearest penny.
    SnackSales = float(int(SnackSales * 100 + 0.5)) / 100;
    Bank += SnackSales;
}

void Cinema::addSnacks()
{
    NumOfSnacks += 1;
}

void Cinema::addNumOfMovieLicenses()
{
    NumOfMovieLicenses += 1;
}

void Cinema::subtractNumOfMovieLicenses()
{
    NumOfMovieLicenses -= 1;
}

void Cinema::changeNumOfEmployees(int NewStaffNumber)
{
    NumOfEmployees += NewStaffNumber;
}

void Cinema::changeDisplayedMovieLicense(int DisplayedLicense, int NewLicense)
{
    for (int i = 0; i < OFFERED_LICENSES_MAX; i++)
    {
        if (i == DisplayedLicense)
        {
            DisplayedMovieLicenses[i] = NewLicense;
            p_MovieLicensesOffered[i] = p_Movies[NewLicense];
            break;
        }
    }
}

void Cinema::setStaffPerformance(string Performance)
{
    StaffPerformance = Performance;
}

void Cinema::setPromotionInUse(string Promotion)
{
    PromotionInUse = Promotion;
}

bool Cinema::checkPreviousLicenseMatch(int NewLicenseOffered)
{
    for (int i = 0; i < OFFERED_LICENSES_MAX; i++)
    {
        if (NewLicenseOffered == getDisplayedMovieLicenses(i))
        {
            return false;
        }
    }

    for (int i = 0; i < NumOfMovieLicenses; i++)
    {
        if (getMovie(NewLicenseOffered)->getTitle() == accessMovieLicense(i)->getTitle())
        {
            return false;
        }
    }
    return true;
}

Theater* Cinema::accessTheaters(int room)
{
    if (p_Theaters[room] != 0)
    {
        return p_Theaters[room];
    }
    else
    {
        return 0;
    }
}

Movie* Cinema::getMovie(int movie)
{
    return p_Movies[movie];
}

Movie* Cinema::accessMovieLicense(int license)
{
    return p_MovieLicenses[license];
}

void Cinema::addMovieLicense(Movie* NewMovie, int index)
{
    p_MovieLicenses[index] = NewMovie;
}

Movie* Cinema::accessMovieLicensesOffered(int license)
{
    return p_MovieLicensesOffered[license];
}
