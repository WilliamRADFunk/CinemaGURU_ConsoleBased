#include <iostream>
#include <iomanip>
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
    Bank = 10000.00;
    TPrice = 10.00;
    NumOfTheaters = 10;
    NumOfEmployees = 1;
    EmployeesMax = 5;
    NumOfSnacks = 1; // Never set less than one, or more than 6. Formatting will break if you do.
    NumOfMovieLicenses = 1;
    PromotionSelected = 0;
    TotalNumOfSeats = 1;
    Expenses = 0.0;
    TicketSales = 0.0;
    SnackSales = 0.0;
    StaffPerformance = "Dismal";
    PromotionInUse = "No Promotion";

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
    string CurrentSeason = p_Calendar->getCurrentSeasonString();
    int CurrentWeek = p_Calendar->getWeek();
    int CurrentYear = p_Calendar->getYear();
    int CurrentNumOfSeats = getTotalNumOfSeats();
    int MostEmployeesPossible = (NumOfTheaters * 5);
    int MostSeatsPossible = (NumOfTheaters * SEATS_MAX);
    int CurrentBank = fabs((int)Bank);

    // Displays the Week, Season, and Year at the top of the HUD with an "X" border.
    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    if (CurrentWeek < 10 && CurrentYear < 10)
    {
        BlankSpaces(15);
        cout << "--- Week: " << CurrentWeek << "/52 -- Season: " << CurrentSeason << " -- Year: " << CurrentYear << " ---";
        BlankSpaces(15);
    }
    else if ((CurrentWeek < 10 && CurrentYear >= 10) || (CurrentWeek >= 10 && CurrentYear < 10))
    {
        BlankSpaces(20);
        cout << "Week: " << CurrentWeek << "/52  Season: " << CurrentSeason << "  Year: " << CurrentYear;
        BlankSpaces(21);
    }
    else if (CurrentWeek >= 10 && CurrentYear >= 10)
    {
        BlankSpaces(20);
        cout << "Week: " << CurrentWeek << "/52  Season: " << CurrentSeason << "  Year: " << CurrentYear;
        BlankSpaces(20);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedDivider();
    XBorderedBlankSpace();
    // Displays the Bank balance in the HUD with an "X" border.
    cout << "X";
    BlankSpaces(2);
    cout << "Bank: ";
    if (Bank < 0)
    {
        cout << "-$" << CurrentBank;
        if (CurrentBank < 10)
        {
            BlankSpaces(22);
        }
        else if (CurrentBank >= 10 && CurrentBank < 100)
        {
            BlankSpaces(21);
        }
        else if (CurrentBank >= 100 && CurrentBank < 1000)
        {
            BlankSpaces(20);
        }
        else if (CurrentBank >= 1000 && CurrentBank < 10000)
        {
            BlankSpaces(19);
        }
        else if (CurrentBank >= 10000 && CurrentBank < 100000)
        {
            BlankSpaces(18);
        }
        else BlankSpaces(17);
    }
    else
    {
        cout << "$" << CurrentBank;
        if (CurrentBank < 10)
        {
            BlankSpaces(22);
        }
        else if (CurrentBank >= 10 && CurrentBank < 100)
        {
            BlankSpaces(22);
        }
        else if (CurrentBank >= 100 && CurrentBank < 1000)
        {
            BlankSpaces(21);
        }
        else if (CurrentBank >= 1000 && CurrentBank < 10000)
        {
            BlankSpaces(20);
        }
        else if (CurrentBank >= 10000 && CurrentBank < 100000)
        {
            BlankSpaces(19);
        }
        else BlankSpaces(18);
    }
    // Displays the Total income from Ticket Sales in the HUD with an "X" border.
    cout << "Total $ From Ticket Sales Last Week: $" << (int)TicketSales;
    if ((int)TicketSales < 10)
    {
        BlankSpaces(5);
    }
    else if ((int)TicketSales >= 10 && (int)TicketSales < 100)
    {
        BlankSpaces(4);
    }
    else if ((int)TicketSales >= 100 && (int)TicketSales < 1000)
    {
        BlankSpaces(3);
    }
    else if ((int)TicketSales >= 1000 && (int)TicketSales < 10000)
    {
        BlankSpaces(2);
    }
    else
    {
        BlankSpaces(1);
    }
    // Displays the number of Theaters owned, and Max number possible to own, in the HUD with an "X" border.
    cout << "X" << endl << "X";
    BlankSpaces(2);
    cout << "Theaters: " << NumOfTheaters << "/" << THEATERS_MAX;
    if (NumOfTheaters < 10 && THEATERS_MAX < 10)
    {
        BlankSpaces(18);
    }
    else if ((NumOfTheaters < 10 && THEATERS_MAX >= 10 && THEATERS_MAX < 100))
    {
        BlankSpaces(17);
    }
    else if ((NumOfTheaters < 10 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000) ||
             (NumOfTheaters >= 10 && NumOfTheaters < 100 && THEATERS_MAX >= 10 && THEATERS_MAX < 100))
    {
        BlankSpaces(16);
    }
    else if ((NumOfTheaters < 10 && THEATERS_MAX >= 1000 && THEATERS_MAX < 10000) ||
             (NumOfTheaters >= 10 && NumOfTheaters < 100 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000))
    {
        BlankSpaces(15);
    }
    else if ((NumOfTheaters >= 10 && NumOfTheaters < 100 && THEATERS_MAX >= 1000 && THEATERS_MAX < 10000) ||
             (NumOfTheaters >= 100 && NumOfTheaters < 1000 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000))
    {
        BlankSpaces(14);
    }
    else
    {
        BlankSpaces(13);
    }
    // Displays the Total income from Snack Sales in the HUD with an "X" border.
    cout << "Total $ From Food Sales Last Week: $" << (int)SnackSales;
    if ((int)SnackSales < 10)
    {
        BlankSpaces(7);
    }
    else if ((int)SnackSales >= 10 && (int)SnackSales < 100)
    {
        BlankSpaces(6);
    }
    else if ((int)SnackSales >= 100 && (int)SnackSales < 1000)
    {
        BlankSpaces(5);
    }
    else if ((int)SnackSales >= 1000 && (int)SnackSales < 10000)
    {
        BlankSpaces(4);
    }
    else
    {
        BlankSpaces(3);
    }
    // Displays the number of Seats owned, and Max number possible to own, in the HUD with an "X" border.
    cout << "X" << endl << "X";
    BlankSpaces(2);
    cout << "Total Seats: " << CurrentNumOfSeats << "/" << MostSeatsPossible;
    if (MostSeatsPossible < 10 && CurrentNumOfSeats < 10)
    {
        BlankSpaces(15);
    }
    else if (MostSeatsPossible >= 10 && MostSeatsPossible < 100 && CurrentNumOfSeats < 10)
    {
        BlankSpaces(14);
    }
    else if ((MostSeatsPossible >= 10 && MostSeatsPossible < 100 && CurrentNumOfSeats >= 10 && CurrentNumOfSeats < 100) ||
             (MostSeatsPossible >= 100 && MostSeatsPossible < 1000 && CurrentNumOfSeats < 10))
    {
        BlankSpaces(13);
    }
    else if ((MostSeatsPossible >= 100 && MostSeatsPossible < 1000 && CurrentNumOfSeats >= 10 && CurrentNumOfSeats < 100) ||
             (MostSeatsPossible >= 1000 && MostSeatsPossible < 10000 && CurrentNumOfSeats < 10))
    {
        BlankSpaces(12);
    }
    else if ((MostSeatsPossible >= 100 && MostSeatsPossible < 1000 && CurrentNumOfSeats >= 100 && CurrentNumOfSeats < 1000) ||
             (MostSeatsPossible >= 1000 && MostSeatsPossible < 10000 && CurrentNumOfSeats >= 10 && CurrentNumOfSeats < 100))
    {
        BlankSpaces(11);
    }
    else if ((MostSeatsPossible >= 1000 && MostSeatsPossible < 10000 && CurrentNumOfSeats >= 100 && CurrentNumOfSeats < 1000) ||
             (MostSeatsPossible >= 10000 && MostSeatsPossible < 100000 && CurrentNumOfSeats >= 10 && CurrentNumOfSeats < 100))
    {
        BlankSpaces(10);
    }
    else if ((MostSeatsPossible >= 1000 && MostSeatsPossible < 10000 && CurrentNumOfSeats >= 1000 && CurrentNumOfSeats < 10000) ||
             (MostSeatsPossible >= 10000 && MostSeatsPossible < 100000 && CurrentNumOfSeats >= 100 && CurrentNumOfSeats < 1000))
    {
        BlankSpaces(9);
    }
    else if (MostSeatsPossible >= 10000 && MostSeatsPossible < 100000 && CurrentNumOfSeats >= 1000 && CurrentNumOfSeats < 10000)
    {
        BlankSpaces(8);
    }
    else if (MostSeatsPossible >= 10000 && MostSeatsPossible < 100000 && CurrentNumOfSeats >= 10000 && CurrentNumOfSeats < 100000)
    {
        BlankSpaces(7);
    }
    else
    {
        BlankSpaces(6);
    }
    // Displays the Total expenses incurred for last turn in the HUD with an "X" border.
    cout << "Total $ For Expenses Last Week: $" << (int)Expenses;
    if ((int)Expenses < 10)
    {
        BlankSpaces(10);
    }
    else if ((int)Expenses >= 10 && (int)Expenses < 100)
    {
        BlankSpaces(9);
    }
    else if ((int)Expenses >= 100 && (int)Expenses < 1000)
    {
        BlankSpaces(8);
    }
    else if ((int)Expenses >= 1000 && (int)Expenses < 10000)
    {
        BlankSpaces(7);
    }
    else
    {
        BlankSpaces(6);
    }
    // Displays the number of Movie Licenses owned in the HUD with an "X" border.
    cout << "X" << endl << "X";
    BlankSpaces(2);
    cout << "Total Licenses: " << NumOfMovieLicenses;
    if (NumOfMovieLicenses < 10)
    {
        BlankSpaces(14);
    }
    else if (NumOfMovieLicenses >= 10 && NumOfMovieLicenses < 100)
    {
        BlankSpaces(13);
    }
    else if (NumOfMovieLicenses >= 100 && NumOfMovieLicenses < 1000)
    {
        BlankSpaces(12);
    }
    // Displays the Total income/(loss) for last turn in the HUD with an "X" border.
    cout << "Total $ in Profit/(Loss): $";
    if (((TicketSales + SnackSales) - (Expenses)) < 0)
    {
        float Loss = fabs((TicketSales + SnackSales) - (Expenses));
        cout << "(" << (int)Loss << ")";
        if ((int)Loss < 10)
        {
            BlankSpaces(14);
        }
        else if ((int)Loss >= 10 && (int)Loss < 100)
        {
            BlankSpaces(13);
        }
        else if ((int)Loss >= 100 && (int)Loss < 1000)
        {
            BlankSpaces(12);
        }
        else if ((int)Loss >= 1000 && (int)Loss < 10000)
        {
            BlankSpaces(11);
        }
        else
        {
            BlankSpaces(10);
        }
    }
    else
    {
        float Profit = ((TicketSales + SnackSales) - (Expenses));
        cout << (int)Profit;
        if ((int)Profit < 10)
        {
            BlankSpaces(16);
        }
        else if ((int)Profit >= 10 && (int)Profit < 100)
        {
            BlankSpaces(15);
        }
        else if ((int)Profit >= 100 && (int)Profit < 1000)
        {
            BlankSpaces(14);
        }
        else if ((int)Profit >= 1000 && (int)Profit < 10000)
        {
            BlankSpaces(13);
        }
        else
        {
            BlankSpaces(12);
        }
    }
    // Displays the number of Snack types owned, and Max number possible to own, in the HUD with an "X" border.
    cout << "X" << endl << "X";
    BlankSpaces(2);
    cout << "Total Snack Types: " << NumOfSnacks << "/" << SNACK_MAX;
    if (SNACK_MAX < 10 && NumOfSnacks < 10)
    {
        BlankSpaces(9);
    }
    else if ((SNACK_MAX < 10 && NumOfSnacks >= 10 && NumOfSnacks < 100) ||
             (SNACK_MAX >= 10 && SNACK_MAX < 100 && NumOfSnacks < 10))
    {
        BlankSpaces(8);
    }
        else if (SNACK_MAX >= 10 && SNACK_MAX < 100 && NumOfSnacks >= 10 && NumOfSnacks < 100)
    {
        BlankSpaces(7);
    }
    // Displays the number of employees employed, and Max number possible to employ, in the HUD with an "X" border.
    cout << "Total Employees: " << NumOfEmployees << "/" << MostEmployeesPossible << " (" << StaffPerformance << ")";
    if (MostEmployeesPossible < 10 && NumOfEmployees < 10)
    {
        BlankSpaces(15);
    }
    else if (MostEmployeesPossible >= 10 && MostEmployeesPossible < 100 && NumOfEmployees < 10)
    {
        BlankSpaces(14);
    }
    else if ((MostEmployeesPossible >= 10 && MostEmployeesPossible < 100 && NumOfEmployees >= 10 && NumOfEmployees < 100) ||
             (MostEmployeesPossible >= 100 && MostEmployeesPossible < 1000 && NumOfEmployees < 10))
    {
        BlankSpaces(13);
    }
    else if (MostEmployeesPossible >= 100 && MostEmployeesPossible < 1000 && NumOfEmployees >= 10 && NumOfEmployees < 100)
    {
        BlankSpaces(12);
    }
    else
    {
        BlankSpaces(11);
    }
    // Displays the Current Ticket Price in the HUD with an "X" border.
    cout << "X" << endl << "X";
    BlankSpaces(2);
    cout << std::setprecision(2) << std::fixed;
    cout << "Current Ticket Price: $" << TPrice;
    if (TPrice < 10)
    {
        BlankSpaces(4);
    }
    else if (TPrice >= 10)
    {
        BlankSpaces(3);
    }
    // Displays the Current Promotion Used in the HUD with an "X" border.
    cout << "Current Promotion in use: " << PromotionInUse;
    BlankSpaces(6);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    cout << endl;
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
