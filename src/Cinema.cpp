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
    cout << "Creating a new game >> Cinema::Cinema()" << endl;
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
        cout << "Assigning new Theater to p_Theaters[" << i << "]" << endl;
        p_Theaters[i] = new Theater;
    }

    // Checks to make sure theater creation performed correctly. Note: remove once game is completed.
    for (int i = 0; i < THEATERS_MAX; i++)
    {
        cout << "Checking p_Theaters[" << i << "] to see if it was assigned a Theater" << endl;
        cout << "p_Theaters[" << i << "] has " << p_Theaters[i]->getNumOfSeats() << " seats." << endl;
        cout << "p_Theaters[" << i << "] has a " << p_Theaters[i]->getScreenLevel() << " screen level." << endl;
        Divider();
    }

    Pause();
    ClearScreen();

    // Filling the movie array with new movies.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "Assigning new Movie to p_Movies[" << i << "]" << endl;
        p_Movies[i] = new Movie;
    }

    Pause();
    ClearScreen();

    // Checks to make sure movie creation performed correctly. Note: remove once game is completed.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "Checking p_Movies[" << i << "] to see if it was assigned a Movie" << endl;
        cout << "p_Movies[" << i << "]'s title is " << p_Movies[i]->getTitle() << endl << endl;
        cout << "p_Movies[" << i << "]'s synopsis is " << p_Movies[i]->getSynopsis() << endl << endl;
        Divider();
    }

    Pause();
    ClearScreen();

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
                    cout << STRING << endl; // Prints our STRING.
                    p_Movies[i]->setTitle(STRING);
                }
                else if (j == 1)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_Movies[i]->setSynopsis(STRING);
                }
                else if (j == 2)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setExpectedPopularityRating(INTEGER);
                }
                else if (j == 3)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setRealPopularityRating(INTEGER);
                }
                else if (j == 4)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to SEASON.
                    if ( !(convert >> SEASON) )
                    SEASON = 0;
                    p_Movies[i]->setBestSeason((Season)SEASON);
                }
                else if (j == 5)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to SEASON.
                    if ( !(convert >> SEASON) )
                    SEASON = 0;
                    p_Movies[i]->setWorstSeason((Season)SEASON);
                }
                else if (j == 6)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to FLOAT.
                    if ( !(convert >> FLOAT) )
                    FLOAT = 0;
                    p_Movies[i]->setCostOfLicensePerWeek((float)FLOAT);
                }
                else if (j == 7)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_Movies[i]->setUseOfLicenseRemainingInWeeks(INTEGER);
                }
                else cout << "ERROR: reading data from file and conversion failure." << endl;
            }
            cout << endl;
        }
	infile.close();

	Pause();
	ClearScreen();

	// Filling the movie licenses array with new movies.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "Assigning new Movie to p_MovieLicenses[" << i << "]" << endl;
        p_MovieLicenses[i] = new Movie;
    }

    Pause();
    ClearScreen();

    // Checks to make sure movie creation performed correctly. Note: remove once game is completed.
    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "Checking p_MovieLicenses[" << i << "] to see if it was assigned a Movie" << endl;
        cout << "p_MovieLicenses[" << i << "]'s title is " << p_MovieLicenses[i]->getTitle() << endl << endl;
        cout << "p_MovieLicenses[" << i << "]'s synopsis is " << p_MovieLicenses[i]->getSynopsis() << endl << endl;
        Divider();
    }

    Pause();
    ClearScreen();

    // Filling the movie licenses offered array with new movies.
    for (int i = 0; i < 3; i++)
    {
        cout << "Assigning new Movie to p_MovieLicensesOffered[" << i << "]" << endl;
        p_MovieLicensesOffered[i] = new Movie;
    }

    Pause();
    ClearScreen();

    // Checks to make sure movie creation performed correctly. Note: remove once game is completed.
    for (int i = 0; i < 3; i++)
    {
        cout << "Checking p_MovieLicensesOffered[" << i << "] to see if it was assigned a Movie" << endl;
        cout << "p_MovieLicensesOffered[" << i << "]'s title is " << p_MovieLicensesOffered[i]->getTitle() << endl << endl;
        cout << "p_MovieLicensesOffered[" << i << "]'s synopsis is " << p_MovieLicensesOffered[i]->getSynopsis() << endl << endl;
        Divider();
    }

    Pause();
    ClearScreen();

    // Assign free movie to the p_MovieLicenses[0].
    p_MovieLicenses[0] = p_Movies[0];
    // Remove after game's completion.
    cout << "p_MovieLicenses[0]'s title is " << p_MovieLicenses[0]->getTitle() << endl << endl;

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

    /* Problem Point!!! */
    Pause();

    // Remove once game is created. From here--
    for (int i = 0; i <= OFFERED_LICENSES_MAX; i++)
    {
        cout << DisplayedMovieLicenses[i] << "   ";
    }
    cout << endl;
    // --To here

    Pause();
    ClearScreen();

	cout << "Leaving Cinema creation" << endl;
}

Cinema::~Cinema()
{
    cout << "Destroying TheCinema" << endl;
    for (int i = 0; i < THEATERS_MAX; i++)
    {
        cout << "deleting p_Theaters[" << i << "]..." << endl;
        p_Theaters[i]->~Theater();
        cout << "p_Theaters[" << i << "] deleted. Assigning it to 0..." << endl;
        p_Theaters[i] = 0;
    }

    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "deleting p_Movies[" << i << "]..." << endl;
        p_Movies[i]->~Movie();
        cout << "p_Movies[" << i << "] deleted. Assigning it to 0..." << endl;
        p_Movies[i] = 0;
    }

    for (int i = 0; i < MOVIES_MAX; i++)
    {
        cout << "Assigning p_MovieLicenses[" << i << "] to 0..." << endl;
        p_MovieLicenses[i] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Assigning p_MovieLicensesOffered[" << i << "] to 0..." << endl;
        p_MovieLicensesOffered[i] = 0;
    }
}


float Cinema::getBank()
{
    cout << "Utilyzing Cinema::getBank()" << endl;
    return Bank;
}

float Cinema::getExpenses()
{
    cout << "Utilyzing Cinema::getExpenses()" << endl;
    return Expenses;
}

float Cinema::getTicketSales()
{
    cout << "Utilyzing Cinema::TicketSales()" << endl;
    return TicketSales;
}

float Cinema::getSnackSales()
{
    cout << "Utilyzing Cinema::SnackSales()" << endl;
    return SnackSales;
}

float Cinema::getTicketPrice()
{
    cout << "Utilyzing Cinema::getTicketPrice()" << endl;
    return TPrice;
}

int Cinema::getNumOfTheaters()
{
    cout << "Utilyzing Cinema::getNumOfTheaters()" << endl;
    return NumOfTheaters;
}

int Cinema::getTotalNumOfSeats()
{
    cout << "Utilyzing Cinema::getTotalNumOfSeats()" << endl;
    int TotalSeats = 0;
    for (int i = 0; i < NumOfTheaters; i++)
    {
        cout << "Point reached1" << endl;
        TotalSeats += p_Theaters[i]->getNumOfSeats();
        cout << "Point reached2" << endl;
        cout << "Counting p_Theaters[" << i << "]'s " << p_Theaters[i]->getNumOfSeats() << " seats." << endl;
    }
    cout << "Leaving Cinema::getTotalNumOfSeats()" << endl;
    return TotalSeats;
}

int Cinema::getNumOfMovieLicenses()
{
    cout << "Utilyzing Cinema::getNumOfMovieLicenses()" << endl;
    return NumOfMovieLicenses;
}

int Cinema::getNumOfEmployees()
{
    cout << "Utilyzing Cinema::getNumOfEmployees()" << endl;
    return NumOfEmployees;
}

int Cinema::getNumOfSnacks()
{
    cout << "Utilyzing Cinema::getNumOfSnack()" << endl;
    return NumOfSnacks;
}

int Cinema::getPromotionSelected()
{
    cout << "Utilyzing Cinema::getPromotionSelected()" << endl;
    return PromotionSelected;
}

int Cinema::getDisplayedMovieLicenses(int index)
{
    cout << "Utilyzing Cinema::getDisplayedMovieLicenses(int)" << endl;
    return DisplayedMovieLicenses[index];
}

string Cinema::getStaffPerformance()
{
    cout << "Utilyzing Cinema::getStaffPerformance()" << endl;
    return StaffPerformance;
}

string Cinema::getPromotionInUse()
{
    cout << "Utilyzing Cinema::getPromotionInUse()" << endl;
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
    cout << "Utilyzing Cinema::addTheater()" << endl;
    cout << "Adding 1 to NumOfTheaters" << endl;
    NumOfTheaters += 1;
    cout << "Leaving Cinema::addTheater()" << endl;
}

void Cinema::changePromotionSelected(int NewPromotion)
{
    cout << "Utilyzing Cinema::changePromotionSelected(int NewPromotion)" << endl;
    cout << "Old PromotionSelected was " << PromotionSelected << endl;
    PromotionSelected = NewPromotion;
    cout << "New PromotionSelected is " << PromotionSelected << endl;
    cout << "Leaving Cinema::changePromotionSelected(int NewPromotion)" << endl;
}

void Cinema::changeTicketPrice(float newPrice)
{
    cout << "Utilyzing Cinema::getNumOfSnack()" << endl;
    cout << "Old price was " << TPrice << endl;
    TPrice = newPrice;
    cout << "New price is " << TPrice << endl;
    cout << endl << endl << "You've changed the Ticket Price to $" << TPrice << endl;
}

void Cinema::adjustBank(int Transaction)
{
    cout << "Utilyzing Cinema::adjustBank(int Transaction)" << endl;
    cout << "Bank before transaction was " << Bank << "." << endl;
    Bank += Transaction;
    cout << "Bank after transaction is " << Bank << "." << endl;
    cout << "Leaving Cinema::adjustBank(int Transaction)" << endl;
}

void Cinema::adjustExpenses(int Rent, int Wages)
{
    cout << "Utilyzing Cinema::adjustExpenses(int Rent, int Wages)" << endl;
    cout << "Expenses before transaction was " << Expenses << "." << endl;
    Expenses = Rent + Wages + (PROMOTION_MULTIPLY_COST * PromotionSelected);
    // Round to the nearest penny.
    Expenses = float(int(Expenses * 100 + 0.5)) / 100;
    Bank -= Expenses;
    cout << "Expenses after transaction is " << Expenses << "." << endl;
    cout << "Leaving Cinema::adjustExpenses(int Rent, int Wages)" << endl;
}

void Cinema::adjustTicketSales(int TicketsSold)
{
    cout << "Utilyzing Cinema::adjustTicketSales(int TicketsSold)" << endl;
    cout << "TicketSales before transaction was " << TicketSales << "." << endl;
    TicketSales = TicketsSold * TPrice;
    // Round to the nearest penny.
    TicketSales = float(int(TicketSales * 100 + 0.5)) / 100;
    Bank += TicketSales;
    cout << "TicketSales after transaction is " << TicketSales << "." << endl;
    cout << "Leaving Cinema::adjustTicketSales(int TicketsSold)" << endl;
}

void Cinema::adjustSnackSales(float SnacksSold)
{
    cout << "Utilyzing Cinema::adjustSnackSales(float SnacksSold)" << endl;
    cout << "SnackSales before transaction was " << SnackSales << "." << endl;
    SnackSales = SnacksSold;
    // Round to the nearest penny.
    SnackSales = float(int(SnackSales * 100 + 0.5)) / 100;
    Bank += SnackSales;
    cout << "SnackSales after transaction is " << SnackSales << "." << endl;
    cout << "Leaving Cinema::adjustSnackSales(float SnacksSold)" << endl;
}

void Cinema::addSnacks()
{
    cout << "Utilyzing Cinema::addSnacks()" << endl;
    cout << "Number of snacks before was " << NumOfSnacks << "." << endl;
    NumOfSnacks += 1;
    cout << "Number of snacks now is " << NumOfSnacks << "." << endl;
    cout << "Leaving Cinema::addSnacks()" << endl;
}

void Cinema::addNumOfMovieLicenses()
{
    cout << "Utilyzing Cinema::addNumOfMovieLicenses()" << endl;
    cout << "Number of owned licenses before was " << NumOfMovieLicenses << "." << endl;
    NumOfMovieLicenses += 1;
    cout << "Number of owned licenses now is " << NumOfMovieLicenses << "." << endl;
    cout << "Leaving Cinema::addNumOfMovieLicenses()" << endl;
}

void Cinema::subtractNumOfMovieLicenses()
{
    cout << "Utilyzing Cinema::subtractNumOfMovieLicenses()" << endl;
    cout << "Number of owned licenses before was " << NumOfMovieLicenses << "." << endl;
    NumOfMovieLicenses -= 1;
    cout << "Number of owned licenses now is " << NumOfMovieLicenses << "." << endl;
    cout << "Leaving Cinema::subtractNumOfMovieLicenses()" << endl;
}

void Cinema::changeNumOfEmployees(int NewStaffNumber)
{
    cout << "Utilyzing Cinema::changeNumOfEmployees(int NewStaffNumber)" << endl;
    cout << "Number of employees before was " << NumOfEmployees << "." << endl;
    NumOfEmployees += NewStaffNumber;
    cout << "Number of employees now is " << NumOfEmployees << "." << endl;
    cout << "Leaving Cinema::changeNumOfEmployees(int NewStaffNumber)" << endl;
}

void Cinema::changeDisplayedMovieLicense(int DisplayedLicense, int NewLicense)
{
    cout << "Utilyzing Cinema::changeDisplayedMovieLicense(int)" << endl;
    cout << "The list of Displayed Licenses before was " << 0 << ", ";
    for (int i = 1; i < OFFERED_LICENSES_MAX; i++)
    {
        if (DisplayedMovieLicenses[i] != 0)
        {
            cout << DisplayedMovieLicenses[i];
        }
        if (DisplayedMovieLicenses[i] != (OFFERED_LICENSES_MAX -1 ))
        {
            cout << ", ";
        }
        else cout << "." << endl;

    }

    for (int i = 1; i < OFFERED_LICENSES_MAX; i++)
    {
        if (DisplayedMovieLicenses[i] == DisplayedLicense)
        {
            DisplayedMovieLicenses[i] = NewLicense;
            break;
        }
    }

    cout << "The list of Displayed Licenses after is " << 0 << ", ";
    for (int i = 1; i < OFFERED_LICENSES_MAX; i++)
    {
        if (DisplayedMovieLicenses[i] != 0)
        {
            cout << DisplayedMovieLicenses[i];
        }
        if (DisplayedMovieLicenses[i] != (OFFERED_LICENSES_MAX -1 ))
        {
            cout << ", ";
        }
        else cout << "." << endl;

    }
    cout << "Leaving Cinema::changeDisplayedMovieLicense(int)" << endl;
}

void Cinema::setStaffPerformance(string Performance)
{
    cout << "Utilyzing Cinema::setStaffPerformance(string Performance)" << endl;
    cout << "The Staff's Performance before was " << StaffPerformance << "." << endl;
    StaffPerformance = Performance;
    cout << "The Staff's Performance now is " << StaffPerformance << "." << endl;
    cout << "Leaving Cinema::setStaffPerformance(string Performance)" << endl;
}

void Cinema::setPromotionInUse(string Promotion)
{
    cout << "Utilyzing Cinema::setPromotionInUse(string Promotion)" << endl;
    cout << "The Staff's Performance before was " << PromotionInUse << "." << endl;
    PromotionInUse = Promotion;
    cout << "The Staff's Performance now is " << PromotionInUse << "." << endl;
    cout << "Leaving Cinema::setPromotionInUse(string Promotion)" << endl;
}

bool Cinema::checkPreviousLicenseMatch(int NewLicenseOffered)
{
    cout << "Utilyzing Cinema::checkPreviousLicenseMatch(int NewLicenseOffered)" << endl;
    for (int i = 0; i < OFFERED_LICENSES_MAX; i++)
    {
        cout << "Checking to see if random choice #" << NewLicenseOffered;
        cout << "matches offered license #" << getDisplayedMovieLicenses(i) << endl;
        if (NewLicenseOffered == getDisplayedMovieLicenses(i))
        {
            cout << "That choice is currently on the offered list." << endl;
            return false;
        }
    }

    for (int i = 0; i < NumOfMovieLicenses; i++)
    {
        cout << "Checking to see if random movie choice: " << getMovie(NewLicenseOffered)->getTitle();
        cout << "matches owned license #" << accessMovieLicense(i)->getTitle() << endl;
        if (getMovie(NewLicenseOffered)->getTitle() == accessMovieLicense(i)->getTitle())
        {
            cout << "That choice is currently owned." << endl;
            return false;
        }
    }

    cout << "The choice is good." << endl;
    return true;
}

Theater* Cinema::accessTheaters(int room)
{
    Theater* ptr_Theater = p_Theaters[room];
    cout << "Utilyzing Cinema::accessTheater(int room)" << endl;
    cout << "Checking if p_Theaters[" << room << "] exists." << endl;
    if (ptr_Theater != 0)
    {
        cout << "p_Theaters[" << room << "] does exist." << endl;
        return ptr_Theater;
    }
    else
    {
        cout << "p_Theaters[" << room << "] does NOT exist." << endl;
        return 0;
    }
}

Movie* Cinema::getMovie(int movie)
{
    cout << "Utilyzing Cinema::getMovie(int movie)" << endl;
    return p_Movies[movie];
}

Movie* Cinema::accessMovieLicense(int license)
{
    cout << "Utilyzing Cinema::accessMovieLicense(int license)" << endl;
    return p_MovieLicenses[license];
}

void Cinema::addMovieLicense(Movie* NewMovie, int index)
{
    cout << "Utilyzing Cinema::addMovieLicense(Movie* NewMovie, int index)" << endl;
    p_MovieLicenses[index] = NewMovie;
}

Movie* Cinema::accessMovieLicensesOffered(int license)
{
    cout << "Utilyzing Cinema::accessMovieLicensesOffered(int license)" << endl;
    return p_MovieLicensesOffered[license];
}
