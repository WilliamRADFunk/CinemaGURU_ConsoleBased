#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <math.h>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "DecisionMaker.h"
#include "RandomEvent.h"
#include "RandomEventHandler.h"
#include "Global.h"

using namespace std;

DecisionMaker::DecisionMaker(Cinema* MainCinema)
{
    TheCinema = MainCinema;
    TheREHandler = new RandomEventHandler();
}

DecisionMaker::~DecisionMaker()
{
    TheREHandler->~RandomEventHandler();
}

void DecisionMaker::choiceTree_Main()
{
    cout << "1. Make Purchase" << endl;
    cout << "2. Manage Staff" << endl;
    cout << "3. Change Ticket Price" << endl;
    cout << "4. Change Movies" << endl;
    cout << "5. End Turn" << endl << endl;
    cout << "H. Instructions & Game Info" << endl;
    cout << "Q. Quit the Game" << endl << endl;
    cout << "Enter the number corresponding to your choice:";
}

void DecisionMaker::choiceTree_01()
{
    cout << endl << "You've selected to Make a Purchase." << endl << endl;
    cout << "1. Buy More Seats" << endl;
    cout << "2. Buy More Movie Licenses" << endl;
    cout << "3. Buy More Snack Choices" << endl;
    cout << "4. Buy Upgrades" << endl;
    cout << "5. Buy Promotional Event" << endl;
    cout << "6. Buy Additional Theater" << endl << endl;
    cout << "R. Go Back" << endl << endl;
    cout << "Which of these actions do you want to perform?" << endl;
}

void DecisionMaker::choiceTree_01_01(int Theaters)
{
    if (Theaters > 1)
    {
        cout << "You've chosen to purchase more seats for your theater." << endl << endl;
        cout << "You have " << Theaters << " theater(s)." << endl;
        cout << "Select 1 through " << Theaters << " to choose which theater to buy seats for:";
    }
}

void DecisionMaker::choiceTree_01_03(int SnacksOwned)
{
    string SnackToBuy = Snacks[SnacksOwned];
    cout << "You've chosen to increase your selection of snacks offered." << endl << endl;
    cout << "You currently offer: ";
    for (int i = 0; i < SnacksOwned; i++)
    {
        if (i >= SnacksOwned - 1)
            {
                cout << "and ";
            }
        cout << Snacks[i];
        if (i < SnacksOwned - 1)
        {
            if (SnacksOwned > 2)
            {
                cout << ", ";
            }
            else cout << " ";
        }
    }
    cout << "." << endl << endl;
    if (SnacksOwned >= SNACK_MAX)
    {
        cout << "You currently offer all the available snacks available." << endl;
        cout << "Try spending your money on other lucrative purchases." << endl << endl;

        Pause();

        return;
    }
    cout << "The next snack option, " << SnackToBuy << ", will cost you $";
    cout << SNACK_PRICE << endl << "to buy the necessary machinery." << endl << endl;
    cout << "Would you like to add " << SnackToBuy << " to your snacks counter? (Y or N)";
}

void DecisionMaker::choiceTree_01_04(int Theaters)
{
    if (Theaters > 1)
    {
        cout << "You've chosen to purchase upgrades for your cinema." << endl << endl;
        cout << "You have " << Theaters << " theater(s)." << endl;
        cout << "Select 1 through " << Theaters << " to choose which theater to buy upgrades for:";
    }
}

void DecisionMaker::choiceTree_01_05(int PromotionInUseIndex)
{
    string PromotionInUse = Promotions[PromotionInUseIndex];
    cout << "You've chosen to change the promotion you're using." << endl << endl;
    cout << "You're currently using: " << PromotionInUse << " ($" << (PROMOTION_MULTIPLY_COST * PromotionInUseIndex);
    cout << " / Week)" << endl << endl;
    cout << endl << "The available promotions are as follows:" << endl << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i << ". " << Promotions[i] << " ($" << (PROMOTION_MULTIPLY_COST * i) << " / Week)" << endl;
    }

    cout << endl << "Which promotion would like to use?";
}

void DecisionMaker::choiceTree_01_06(int Theaters)
{
    cout << "You've chosen to expand your Cinema by one additional theater." << endl << endl;
    cout << "A new theater costs $" << THEATER_PRICE << "." << endl << endl;
    cout << "Keep in mind that each theater you own costs you $" << THEATER_RENT << " per Week in rent." << endl << endl;
    cout << "Your cinema currently has " << Theaters << " theater(s) out of a maximum of " << THEATERS_MAX << "." << endl << endl;
    cout << "This number of theater(s) costs you $" << Theaters * THEATER_RENT << " per Week in rent." << endl << endl;
    if ( !(Theaters >= THEATERS_MAX) )
    {
        cout << endl << "Expand for an additional theater space? (Y or N)";
    }
    else
    {
        cout << endl << "You already have the maximum amount of theaters your building will support" << endl << endl;
        cout << "Try upgrading your existing theaters, picking a better promotion, or hiring more workers." << endl << endl;
        Pause();
    }
}

void DecisionMaker::choiceTree_02()
{
    cout << endl << "You've selected to Manage your Staff." << endl << endl;
    cout << "1. Hire Employees" << endl;
    cout << "2. Fire Employees" << endl << endl;
    cout << "R. Go Back" << endl << endl;
    cout << "Which of these actions would you like to perform?";
}

void DecisionMaker::choiceTree_03(float TicketPrice)
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "You've selected to Change the Ticket Price.";
    BlankSpaces(31);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "Current Ticket Price is $" << TicketPrice;
    if (TicketPrice < 10)
    {
        BlankSpaces(45);
    }
    else if (TicketPrice >= 10)
    {
        BlankSpaces(44);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "You can choose any price between $0.00 and $20.00";
    BlankSpaces(25);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "What do you want the new Ticket Price to be: (Type number, then ENTER)";
    BlankSpaces(4);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);
}

void DecisionMaker::choiceTree_04(int Theaters)
{
    if (Theaters > 1)
    {
        cout << "You've selected to Change the Movie in one of your theaters." << endl << endl;
        cout << "You have " << Theaters << " theater(s)." << endl << endl;
        cout << "Select 1 through " << Theaters << " to choose which theater to change movies for:";
    }
}

void DecisionMaker::choiceNumOfSeats(int TheaterNumber, int AmountOfSeats)
{
    cout << "In Theater #" << TheaterNumber << ", you have " << AmountOfSeats << " seats." << endl << endl;
    cout << "Each new seat costs $" << SEAT_PRICE << ". The maximum number of seats is 100 for any theater." << endl << endl;
    cout << "How many seats would you like to buy? (Enter 0 seats to change your mind)";
}

void DecisionMaker::choiceUpgradeLevels(int TheaterNumber, float ScreenLevel, float ProjectorLevel, float SoundLevel)
{
    cout << "In Theater #" << TheaterNumber << ", you have:" << endl;
    cout << "1. Screen Size:        " << (ScreenLevel * 100) << " square feet." << endl;
    cout << "2. Projector Quality:  " << (ProjectorLevel * 1000) << " pixels/square foot." << endl;
    cout << "3. Sound Intensity:    " << (SoundLevel * 70) << " decibels." << endl << endl;
    cout << "R. Go Back" << endl << endl;
    cout << "Which of these systems would you like to upgrade?";
}

void DecisionMaker::choiceUpgradeChosenEquipment(float Level, Equipment EquipmentUpgraded)
{
    float LevelUpgraded = Level + 0.1;
    cout << "You've selected to increase your ";
    if (EquipmentUpgraded == 0)
    {
        cout << "screen size." << endl << endl;
        cout << "To upgrade from " << (Level * 100) << " square feet to "
         << (LevelUpgraded * 100) << " square feet," << endl;
    }
    else if (EquipmentUpgraded == 1)
    {
        cout << "projector quality." << endl << endl;
        cout << "To upgrade from " << (Level * 1000) << " pixels/square foot to "
         << (LevelUpgraded * 1000) << " pixels/square foot," << endl;
    }
    else if (EquipmentUpgraded == 2)
    {
        cout << "sound intensity." << endl << endl;
        cout << "To upgrade from " << (Level * 70) << " decibels to "
         << (LevelUpgraded * 70) << " decibels," << endl;
    }
    else cout << endl << endl << "ERROR: No such equipment type exists!" << endl << endl;
    cout << " it will cost $" << UPGRADE_PRICE << ". Purchase upgrade? (Y or N)";
}

string DecisionMaker::calculateStaffLevel(int Employees, int Theaters)
{
    int MaxEmployees = Theaters * 5;
    int StaffLevelEquation = (int)(5 * ((float)Employees / ((float)MaxEmployees))) - 1;
    return StaffPerformance[StaffLevelEquation];
}

string DecisionMaker::calculatePromotionLevel(int PromotionInUseIndex)
{
    string PromotionType = Promotions[PromotionInUseIndex];
    return PromotionType;
}
void DecisionMaker::choiceHireStaff(int Employees, int Theaters)
{
    int MaxEmployees = Theaters * 5;
    int NumAllowedToChange = MaxEmployees - Employees;

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees, Theaters));

    cout << "You currently employ " << Employees << " ";
    if (Employees == 1)
    {
        cout << "person, ";
    }
    else
    {
        cout << "people, ";
    }
    cout << "for a total weekly cost of $" << (Employees * EMPLOYEE_WAGE) << "." << endl << endl;
    cout << "Your staff's performance is " << TheCinema->getStaffPerformance() << "." << endl << endl;
    cout << "You can employ 5 people for every theater in your cinema." << endl << endl;
    cout << "Since you have " << Theaters << " theater, you can employ ";
    cout << "a total of " << MaxEmployees << " people." << endl << endl;
    cout << "As it stands, you can hire at most: " << NumAllowedToChange << " more ";
    if (NumAllowedToChange == 1)
    {
        cout << "person.";
    }
    else
    {
        cout << "people.";
    }
    cout << endl << endl << "Remember that each employee costs $" << EMPLOYEE_WAGE << " per week." << endl << endl;
    cout << "Hire how many people? (Enter 0 if you're budget can't spare it)";
}

void DecisionMaker::choiceFireStaff(int Employees, int Theaters)
{
    int MaxEmployees = Theaters * 5;
    int NumAllowedToChange = MaxEmployees - Employees;

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees, Theaters));

    cout << "You currently employ " << Employees << " ";
    if (Employees == 1)
    {
        cout << "person, ";
    }
    else
    {
        cout << "people, ";
    }
    cout << "for a total weekly cost of $" << (Employees * EMPLOYEE_WAGE) << "." << endl << endl;
    cout << "Your staff's performance is " << TheCinema->getStaffPerformance() << "." << endl << endl;
    cout << "You must have at least 1 employee to operate your cinema, and " << endl;
    cout << "each employee costs $" << EMPLOYEE_WAGE << " per week." << endl << endl;
    cout << "As it stands, you can fire at most: " << (Employees - 1) << "  ";
    if (NumAllowedToChange == 1)
    {
        cout << "person.";
    }
    else
    {
        cout << "people.";
    }
    cout << endl << endl << "Fire how many people? (Enter 0 if you've had a change of heart)";
}

void DecisionMaker::currentMovie(int TheaterNumber, string Title)
{
    cout << "In Theater #" << TheaterNumber << ", ";
    if (Title != "No Movie Playing")
    {
        cout << "the movie " << Title << " is now playing." << endl << endl;
    }
    else
    {
        cout << "there is no movie playing at the moment." << endl << endl;
    }

    cout << "You are able to play the following movies: " << endl << endl;
}

char DecisionMaker::getYesOrNo()
{
    char ch;

    do
    {
        ch = getch();
    } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

    return ch;
}

char DecisionMaker::getConfirmation(char input)
{
    // This function can be used in either the get help, or quit, selections.
    if (input == 'Q' || input == 'q')
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(25);
        cout << "You've chosen to quit.";
        BlankSpaces(30);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(25);
        cout << "Are you sure? (Y or N)";
        BlankSpaces(30);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);
    }
    if (input == 'h' || input == 'H')
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(12);
        cout << "You've chosen to read the instructions and game info.";
        BlankSpaces(12);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(25);
        cout << "Are you sure? (Y or N)";
        BlankSpaces(30);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);
    }

    char ch;

    ch = getYesOrNo();

    if (ch == 'n' || ch == 'N')
    {
        return '0';
    }
    else if (ch == 'y' || ch == 'Y')
    {
        if (input == 'Q' || input == 'q')
        {
            return 'Q';
        }
        if (input == 'h' || input == 'H')
        {
            return 'H';
        }
    }
    else
    {
        cout << "Error in quitting/get help input" << endl;
        return 'Q';
    }

    //else statement above should have accounted for all other possibilities.
    //If program has reached this point, there is a serious flaw.
    cout << "ERROR:The DecisionMaker::getConfirmation(char input) has";
    cout << "reached a point it shouldn't." << endl;
    Pause();
    return '0';
}

char DecisionMaker::getSelectionMain()
{
    char c;

    do
    {
        c = getch();
    } while (c != '1' && c != '2' && c != '3' && c != '4'
             && c != '5' && c != 'h' && c != 'H' && c != 'q' && c != 'Q');

    return c;
}

char DecisionMaker::getSelection_01()
{
    char c;

    do
    {
        c = getch();
    } while (c != '1' && c != '2' && c != '3' && c != '4'
             && c != '5' && c != '6' && c != 'r' && c != 'R');

    if (c == 'r')
        c = 'R';

    return c;
}

int DecisionMaker::getSelection_01_02()
{
    int Input = 1;

    // Should never happen, but in case
    if (OFFERED_LICENSES_MAX == 0)
    {
        cout << "WARNING: OFFERED_LICENSES_MAX was set to 0" << endl << endl;
        return Input;
    }

    do
    {
        if ( !(cin >> Input) )
        {
            cout << "Incorrect choice made." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(Input > 0 && Input <= (OFFERED_LICENSES_MAX + 1)) );

    return Input;
}

char DecisionMaker::getSelection_01_05(int PreviousPromotion)
{
    char c;

    do
    {
        c = getch();
    } while (c != '0' && c != '1' && c != '2' && c != '3'
             && c != '4' && c != '5' && c != 'r' && c != 'R');

    ClearScreen();

    for (int i = 48; i < 54; i++)
    {
        if ((int)c == i)
        {
            if (PreviousPromotion != (i - 48))
            {
                cout << "You've selected the promotion: " << Promotions[i - 48] << endl << endl;
                cout << "It will cost you $" << (PROMOTION_MULTIPLY_COST * (i - 48)) << " / Week to use." << endl << endl;
            }
            else cout << "You've chosen to keep the same promotion." << endl << endl;

            Pause();

            return (i - 48);
        }
    }
    cout << "ERROR: getSelection_01_05(int PreviousPromotion) returned an incorrect" << endl;
    cout << "integer of 6 (outside Promotions[6] array)" << endl << endl;
    return 6;
}

bool DecisionMaker::getSelection_01_06(int Bank, int Theaters)
{
    char ch;

    while ( !(Theaters >= THEATERS_MAX) )
    {
        ch = getYesOrNo();

        ClearScreen();

        if (ch =='Y' || ch == 'y')
        {
            if (Bank >= THEATER_PRICE)
            {
                cout << endl << endl << "Congratulations!" << endl << endl;
                cout << "You've expanded your cinema by one theater." << endl << endl;
                cout << "It starts off with " << SEATS_MIN << " seats, and currently isn't playing a movie." << endl << endl;
                cout << "You now have a total of " << (Theaters + 1)<< " theaters, costing you $" << ((Theaters + 1) * THEATER_RENT);
                cout << " per Week" << endl << endl;
                Pause();

                return true;
            }
            else
            {
                cout << endl << endl << "You don't have enough money in the bank for this expansion." << endl << endl;
                cout << "Try again when you've got more money." << endl << endl;
                Pause();

                return false;
            }
        }
        else if (ch =='N' || ch == 'n')
        {
            cout << endl << endl << "Perhaps another time then..." << endl << endl;
            Pause();

            return false;
        }
        else
        {
            cout << "ERROR: Invalid result reached in getSelection_01_06(int Bank, int Theaters)" << endl << endl;
            Pause();

            return false;
        }
    }

    // Only a yes return a different result.
    return false;
}

char DecisionMaker::getSelection_02()
{
    char c;

    do
    {
        c = getch();
    } while (c != '1' && c != '2' && c != 'r' && c != 'R');

    if (c == 'r')
        c = 'R';

    return c;
}

int DecisionMaker::getSelection_TheaterNum(int Theaters)
{
    int TheaterSelection;

    do
    {
        if ( !(cin >> TheaterSelection) )
        {
            cout << "Incorrect choice made." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(TheaterSelection >= 1 && TheaterSelection <= Theaters) );

    return TheaterSelection;
}

int DecisionMaker::getSelectionSeatPurchase()
{
    int SeatQuantity;

    do
    {
        if ( !(cin >> SeatQuantity) )
        {
            cout << "Incorrect choice made." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(SeatQuantity >= 0 && SeatQuantity <= 90) );

    return SeatQuantity;
}

char DecisionMaker::getSelectionUpgradePurchase()
{
    char c;

    do
    {
        c = getch();
    } while (c != '1' && c != '2' && c != '3' && c != 'r' && c != 'R');

    if (c == 'r')
        c = 'R';

    return c;
}

int DecisionMaker::getNumOfEmployeesToHire(int Employees, int Theaters)
{
    int HireQuantity;

    do
    {
        if ( !(cin >> HireQuantity) )
        {
            cout << "Incorrect choice made." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(HireQuantity >= 0 && HireQuantity <= ((Theaters * 5) - Employees)) );

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees + HireQuantity, Theaters));

    ClearScreen();

    if (HireQuantity > 0)
    {
        cout << endl << endl << "You've hired " << HireQuantity << " new employees." << endl << endl;
        cout << "There are " << (Employees + HireQuantity) << " people now working at your cinema." << endl << endl;
        cout << "Your staff's performance is now " << TheCinema->getStaffPerformance() << "." << endl << endl;
    }
    else cout << "Perhaps you'll want to hire more people later..." << endl << endl;

    return HireQuantity;
}

int DecisionMaker::getNumOfEmployeesToFire(int Employees, int Theaters)
{
    int FireQuantity;

    do
    {
        if ( !(cin >> FireQuantity) )
        {
            cout << "Incorrect choice made." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(FireQuantity >= 0 && FireQuantity < (Employees)) );

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees - FireQuantity, Theaters));

    ClearScreen();

    if (FireQuantity > 0)
    {
        cout << endl << endl << "You've fired " << FireQuantity << " workers." << endl << endl;
        cout << "There are " << (Employees - FireQuantity) << " people trying to make up the difference." << endl << endl;
        cout << "Your staff's performance is now " << TheCinema->getStaffPerformance() << "." << endl << endl;
    }
    else cout << "At least now the lazy peons know you could fire them anytime..." << endl << endl;

    return FireQuantity;
}

float DecisionMaker::getNewTicketPrice()
{
    float NewPrice = -(9456);

    do
    {
        if (NewPrice != -(9456))
        {
            if (NewPrice > 0)
            {
                cin.clear();
                string garbage;
                getline(cin, garbage);
                ClearScreen();
                choiceTree_03(TheCinema->getTicketPrice());
                cout << "==> ";
            }
            else if (NewPrice < 0)
            {
                cin.clear();
                string garbage;
                getline(cin, garbage);
                ClearScreen();
                choiceTree_03(TheCinema->getTicketPrice());
                cout << "==> ";
            }
            else if ( !(NewPrice >= 0 && NewPrice <= 20) )
            {
                cin.clear();
                string garbage;
                getline(cin, garbage);
                ClearScreen();
                choiceTree_03(TheCinema->getTicketPrice());
                cout << "==> ";
            }
        }
        if ( !(cin >> NewPrice) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
    } while ( !(NewPrice >= 0.0 && NewPrice <= 20.0) );
    if (NewPrice >= 20.0)
    {
        NewPrice = 20.0;
    }
    else if (NewPrice <= 0)
    {
        NewPrice = 0.0;
    }
    // Round to the nearest hundredths.
    NewPrice = float(int(NewPrice * 100 + 0.5)) / 100;

    return NewPrice;
}

int DecisionMaker::getSelectedLicense()
{
    int NewMovie = -(9768);

    do
    {
        if (NewMovie != -(9768))
        {
            if (NewMovie >= 0)
            {
                cout << endl << NewMovie << " is not a valid selection. Try again: ";
                cin.clear();
                string garbage;
                getline(cin, garbage);
            }
            else if (NewMovie < 0)
            {
                cout << endl << "-" << abs(NewMovie) << " is not a valid selection. Try again: ";
            }
        }
        if ( !(cin >> NewMovie) )
        {
            cout << "Clearing egregious input flags." << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }
        cout << endl << "You entered: " << NewMovie << "." << endl << endl;

    } while ( !(NewMovie > 0 && NewMovie < 22) );

    // Takes into account the [0] index.
    return (NewMovie - 1);
}

char DecisionMaker::getRandomEventChoice()
{
    char c;

    do
    {
        c = getch();
    } while (c != 'a' && c != 'A' && c != 'b' && c != 'B' && c != 'c' && c != 'C' && c != 'd' && c != 'D');

    return c;
}

float DecisionMaker::getTPriceFactor(float TicketPrice)
{
    float TPriceFactor;
    if (TicketPrice > -0.01 && TicketPrice < 0.01)
    {
        TPriceFactor = 2.0;
    }
    else if (TicketPrice > 0.0 && TicketPrice <= 2.5)
    {
        TPriceFactor = 1.75;
    }
    else if (TicketPrice > 2.5 && TicketPrice <= 5.0)
    {
        TPriceFactor = 1.5;
    }
    else if (TicketPrice > 5.0 && TicketPrice <= 7.5)
    {
        TPriceFactor = 1.25;
    }
    else if (TicketPrice > 7.5 && TicketPrice < 10.0)
    {
        TPriceFactor = 1.1;
    }
    else if (TicketPrice > 9.99 && TicketPrice < 10.01)
    {
        TPriceFactor = 1.0;
    }
    else if (TicketPrice > 10.0 && TicketPrice <= 12.5)
    {
        TPriceFactor = 0.9;
    }
    else if (TicketPrice > 12.5 && TicketPrice <= 15.0)
    {
        TPriceFactor = 0.75;
    }
    else if (TicketPrice > 15.0 && TicketPrice <= 17.5)
    {
        TPriceFactor = 0.5;
    }
    else if (TicketPrice > 17.5 && TicketPrice <= 20.0)
    {
        TPriceFactor = 0.25;
    }
    return TPriceFactor;
}

float DecisionMaker::getSeasonFactor(Season CurrentSeason, Season BestSeason, Season WorstSeason)
{
    float SeasonFactor;
    if (BestSeason == CurrentSeason)
    {
        SeasonFactor = 1.25;
    }
    else if (WorstSeason == CurrentSeason)
    {
        SeasonFactor = 0.75;
    }
    else
    {
        SeasonFactor = 1;
    }
    return SeasonFactor;
}

float DecisionMaker::getPromoFactor(int Promotion)
{
    float PromoFactor;
    if (Promotion == 0)
    {
        PromoFactor = 1;
    }
    else
    {
        PromoFactor = 1 + (Promotion / 10);
    }
    return PromoFactor;
}

float DecisionMaker::getStaffFactor(int Employees, int Theaters)
{
    float StaffFactor;
    // Should be decimal from 0 to 1.
    int StaffLevel = (int)((float)Employees / ((float)(Employees * Theaters * 5)));
    // Lower than half lowers factor below 1. Higher is higher than 1. 0.5 is equal to 1.
    if (StaffLevel > 0.49 && StaffLevel < 0.51)
    {
        StaffFactor = 1.0;
    }
    else if (StaffLevel > 0.75 && StaffLevel <= 1.0)
    {
        StaffFactor = 1.2;
    }
    else if (StaffLevel > 0.5 && StaffLevel <= 0.75)
    {
        StaffFactor = 1.1;
    }
    else if (StaffLevel >= 0.25 && StaffLevel < 0.5)
    {
        StaffFactor = 0.9;
    }
    else if (StaffLevel >= 0.0 && StaffLevel < 0.25)
    {
        StaffFactor = 0.8;
    }
    return StaffFactor;
}

bool DecisionMaker::checksPurchaseOfSeats(int Bank, int AmountOfSeats, int SeatsToPurchase)
{
    int CostOfPurchase;

    CostOfPurchase = SeatsToPurchase * SEAT_PRICE;

    if (CostOfPurchase > Bank)
    {
        cout << "That would cost $" << CostOfPurchase << " and you only have $"
             << Bank << " in the Bank. Try a smaller purchase." << endl;

        Pause();

        return false;
    }
    else if ((AmountOfSeats + SeatsToPurchase) > SEATS_MAX)
    {
        cout << "That purchase would put you in excess of the " << SEATS_MAX << " seat per theater limit." << endl;
        cout << "Try a smaller purchase." << endl;

        Pause();

        return false;
    }
    else
    {
        cout << "This purchase will cost you $" << SEAT_PRICE * SeatsToPurchase << "." << endl;
        cout << "Do you want to make the purchase? (Y or N)";
        char ch = getYesOrNo();

        ClearScreen();

        if (ch == 'y' || ch == 'Y')
        {
            if (SeatsToPurchase > 0)
            {
                cout << endl << endl << "Congratulations!" << endl << endl;
                cout << "You've purchased " << SeatsToPurchase << " seats for this theater." << endl << endl;
                cout << "The theater now has " << SeatsToPurchase + AmountOfSeats << " seats." << endl << endl;;
            }
            else cout << "Perhaps you'll want to buy seats some other time..." << endl << endl;

            Pause();

            return true;
        }
        else if (ch == 'n' || ch == 'N')
        {
            cout << endl << endl << "Perhaps a different quantity then..." << endl << endl;

            Pause();

            return false;
        }
    }

    return false;
}

bool DecisionMaker::checkPurchaseOfMovieLicense(int Bank, int Cost)
{
    if (Bank >= Cost)
        return true;
    else return false;
}

bool DecisionMaker::checkPurchaseOfSnacks(int Bank, int SnacksOwned)
{
    if (Bank < SNACK_PRICE)
    {
        cout << endl << endl << "You don't have enough money. Perhaps you can try again later." << endl << endl;
        Pause();
        return true;
    }
    else
    {
        cout << endl << endl << "Congratulations!" << endl << endl;
        cout << "You've purchased the equipment for a new snack to sell." << endl << endl;
        cout << "You now sell: ";
        for (int i = 0; i < SnacksOwned + 1; i++)
        {
            if (i >= SnacksOwned)
            {
                cout << "and ";
            }
            cout << Snacks[i];
            if (i < SnacksOwned)
            {
                cout << ", ";
            }
        }
        cout << "." << endl << endl;
        Pause();
        return false;
    }
}

bool DecisionMaker::checkPurchaseOfUpgrade(int Bank, float Level, Equipment EquipmentUpgraded)
{
    if (Bank < UPGRADE_PRICE)
    {
        cout << endl << endl << "You don't have enough money. Perhaps you can try again later." << endl << endl;
        Pause();
        return true;
    }
    else
    {
        cout << endl << endl << "Congratulations!" << endl << endl;
        cout << "You've purchased an upgrade to your ";
        if (EquipmentUpgraded == 0)
        {
            cout << "screen size. It is now " << ((Level + 0.1) * 100) << " square feet." << endl << endl;
        }
        else if (EquipmentUpgraded == 1)
        {
            cout << "projector quality." << endl << "It is now " << ((Level + 0.1) * 1000) << " pixels/square foot." << endl << endl;
        }
        else if (EquipmentUpgraded == 2)
        {
            cout << "sound intensity. It is now " << ((Level + 0.1) * 70) << " decibels." << endl << endl;
        }
        else cout << endl << endl << "ERROR: No such equipment type exists!" << endl << endl;
        Pause();
        return false;
    }
}

void DecisionMaker::activateDecisionTree()
{
    do
    {
        int CurrentEmployeeAmount = TheCinema->getNumOfEmployees();
        int CurrentTheaterAmount = TheCinema->getNumOfTheaters();
        float CurrentBankAmount = TheCinema->getBank();
        int CurrentNumberOfSnacks = TheCinema->getNumOfSnacks();
        int CurrentPromotionsSelected = TheCinema->getPromotionSelected();
        int CurrentNumOfLicensesOwned = TheCinema->getNumOfMovieLicenses();
        float CurrentTicketPrice = TheCinema->getTicketPrice();
        Season CurrentSeasonInt = TheCinema->p_Calendar->getCurrentSeasonInt();

        // The only way for a player to lose, is to incur -5000 in debt.
        // The player is warned when they are in debt, but above the losing threshold.
        // When -5000 is reached, a goodbye message is delivered, and main loop is broken.
        if (TheCinema->getBank() <= 0 && TheCinema->getBank() > -(DEBT_MAX))
        {
            cout << "WARNING: You are in debt to the bank for a total of -$";
            cout << fabs(TheCinema->getBank()) << "." << endl << endl;
            cout << "If your debt reaches -$" << DEBT_MAX << ", they will foreclose on your cinema." << endl;
            Divider();
            Pause();
            ClearScreen();
        }
        if (TheCinema->getBank() <= -(DEBT_MAX))
        {
            cout << "Your debt has reached -$" << fabs(TheCinema->getBank());
            cout << ", which is more than the allowable -$" << DEBT_MAX << "." << endl << endl;
            cout << "The bank has decided you are too high a risk," << endl;
            cout << "and have foreclosed on your cinema. You've lost." << endl << endl;
            cout << "Try again some time." << endl;
            Divider();
            Pause();
            ClearScreen();
            break;
        }
        if (TheCinema->getBank() >= PROFIT_MAX)
        {
            cout << " You've earned more than $" << TheCinema->getBank() << "!" << endl << endl;
            cout << "You have won CinemaGURU. Congratulations!" << endl << endl;
            cout << "Play again some time." << endl;
            Divider();
            Pause();
            ClearScreen();
            break;
        }

        // Displays the cinema's assets, recent profits and expenses, and time.
        TheCinema->hud();

        // Displays main choices: buy, staff, ticket price, movie, end turn, and quit.
        choiceTree_Main();
        // Player's selection is collected and stored.
        Decision = getSelectionMain();
        ClearScreen();

//START OF MAIN SWITCH@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        // Nested switch/do-loop for main choices.
        switch (Decision)
        {
//MAIN SWITCH - BUY STUFF############################################################################################
        case '1' :
            // Player chose to Make Purchase. Loop breaks when 'R' or Go Back is selected.
            do
            {
                ClearScreen();
                // Displays Make Purchase choices: Buy Seats, Buy Movie License, Buy Snacks, Buy Upgrades,
                // Buy Promotions, Buy Additional Theater, and Go Back.
                choiceTree_01();
                // Player's selection is collected and stored.
                DecisionBuy = getSelection_01();
                // Player chose to Buy More Seats. Loop breaks when 'R' or Go Back is selected.
//-------------------------------------------------------------------------------------------------------------------
                if (DecisionBuy == '1')
                {
                    // Loop control variable.
                    bool IllegalPurchase = false;

                    ClearScreen();

                    if (CurrentTheaterAmount > 1)
                    {
                        // Displays the question of which theater to purchase more seats for.
                        choiceTree_01_01(CurrentTheaterAmount);
                        // Player's selection is collected and stored.
                        Decision_TheaterNum = getSelection_TheaterNum(CurrentTheaterAmount);
                        // Takes into account the p_Theaters[] array has a zero index for the first theater.
                        Decision_TheaterNum -= 1;
                    }
                    // Takes into account the p_Theaters[] array has a zero index for the first theater.
                    else Decision_TheaterNum = 0;

                    do
                    {
                        ClearScreen();
                        // Displays theater chosen and the amount of seats present.
                        // Explains price of each seat and asks player how many to buy.
                        choiceNumOfSeats(Decision_TheaterNum + 1,
                                         TheCinema->accessTheaters(Decision_TheaterNum)->getNumOfSeats());
                        // Player's selection is collected and stored.
                        HowManySeatsToBuy = getSelectionSeatPurchase();
                        // Checks if player has enough money, or if number exceeds max seats for theater.
                        IllegalPurchase = checksPurchaseOfSeats(CurrentBankAmount,
                                                                TheCinema->accessTheaters(Decision_TheaterNum)->getNumOfSeats(),
                                                                HowManySeatsToBuy);
                        // If purchase was successful, update Bank and NumOfSeats for that theater.
                        if (IllegalPurchase)
                        {
                            TheCinema->adjustBank(-(HowManySeatsToBuy*SEAT_PRICE));
                            TheCinema->accessTheaters(Decision_TheaterNum)->addSeats(HowManySeatsToBuy);
                        }
                        // With purchase made, control reverts back to main menu with updates to HUD.
                    } while (IllegalPurchase == false);
                        DecisionBuy = 'R';
                }
                // Player chose to Buy More Movie Licenses. Loop breaks when 'R' or Go Back is selected.
//-------------------------------------------------------------------------------------------------------------------
                else if (DecisionBuy == '2')
                {
                    char ch;
                    int DesiredLicense;

                    ClearScreen();

                    do
                    {
                        cout << "You've chosen to purchase additional movie licenses." << endl << endl;
                        cout << "Below is a list of newly released movies available for purchase:" << endl;
                        int Counter = 0;
                        // Displays the items on the list.
                        for (int i =0; i < OFFERED_LICENSES_MAX; i++)
                        {
                            if (TheCinema->accessMovieLicensesOffered(i)->getTitle() != "Not Available")
                            {
                                cout << (Counter + 1) << ". "
                                     << TheCinema->accessMovieLicensesOffered(i)->getTitle() << endl;
                                Counter++;
                            }
                        }
                        // If there's at least one movie offered, offer the no choice option.
                        cout << Counter + 1<< ". None of these" << endl;
                        cout << endl << endl << "Which of these do you choose?";
                        // Player's selection is collected and stored.
                        DesiredLicense = getSelection_01_02();

                        ClearScreen();

                        // Player selected "None of these"
                        if (DesiredLicense == (OFFERED_LICENSES_MAX + 1))
                        {
                            cout << "None of those tickle your fancy, eh?" << endl << endl;
                            cout << "Not to worry!" << endl << endl;
                            cout << "A new batch of movies come out every new season." << endl << endl;
                            cout << "Also, every time you purchase a license it's replaced with a new option.";
                            cout << endl << endl;
                            Pause();
                        }
                        // Player selected 1-3.
                        else
                        {
                            TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->displayMovieDetails();
                            cout << endl << endl;
                            cout << "Do you want to purchase the license for this movie? (Y or N)";
                            ch = getYesOrNo();
                            if (ch == 'N' || ch == 'n')
                            {
                                // Displays list of license options again.
                                DecisionBuyMovieLicense = 'Z';
                                continue;
                            }
                            else
                            {
                                ClearScreen();
                                // Check to make sure there's enough money in the back.
                                if (checkPurchaseOfMovieLicense(TheCinema->getBank(),
                                                                TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->getCostOfLicensePerWeek()))
                                {
                                    TheCinema->adjustBank(-(TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->getCostOfLicensePerWeek()));
                                    cout << "Congratulations!" << endl << endl;
                                    cout << "You've purchased the license for ";
                                    cout << TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->getTitle();
                                    cout << endl << endl;
                                    cout << "Your license to play the movie will expire in ";
                                    cout << TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->getUseOfLicenseRemainingInWeeks();
                                    cout << " Weeks." << endl << endl;
                                    Pause();
                                    TheCinema->addNumOfMovieLicenses();
                                    *TheCinema->accessMovieLicense((TheCinema->getNumOfMovieLicenses()) - 1) =
                                                *TheCinema->accessMovieLicensesOffered(DesiredLicense - 1);
                                    // Next random license offer is created.
                                    do
                                    {
                                        NewLicenseOffered = (rand()% (MOVIES_MAX - 1)) + 1;
                                        // Checks to see if all the movies have already shown up in Licenses Offered.
                                    } while ( !(TheCinema->checkPreviousLicenseMatch(NewLicenseOffered)) );

                                    Pause();

                                    TheCinema->changeDisplayedMovieLicense((DesiredLicense - 1), NewLicenseOffered);

                                    Pause();
                                }
                                else
                                {
                                    cout << "You don't have enough cash in the bank to buy a license for ";
                                    cout << TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->getTitle();
                                    cout << endl << endl;
                                    cout << "Make some more money, and try again later." << endl << endl;
                                    Pause();
                                }
                            }
                        }
                        // Once selection is finalized, loop is broken, control reverts to main menu.
                        DecisionBuyMovieLicense = 'R';
                        DecisionBuy = 'R';
                    } while(DecisionBuyMovieLicense != 'R');
                }
                // Player chose to Buy More Snack Options. Loop breaks when 'R' or Go Back is selected.
//-------------------------------------------------------------------------------------------------------------------
                else if (DecisionBuy == '3')
                {
                    ClearScreen();
                    // Displays details about snacks, explains price to upgrade, and asks if upgrade is desired.
                    choiceTree_01_03(CurrentNumberOfSnacks);

                    // If all the snacks are purchased, skip ahead.
                    if (!(CurrentNumberOfSnacks >= SNACK_MAX))
                    {
                        // Player's selection is collected and stored.
                        char ch = getYesOrNo();

                        if (ch == 'y' || ch == 'Y')
                        {
                            // If check comes back true, there's not enough money in the bank.
                            if (checkPurchaseOfSnacks(CurrentBankAmount, CurrentNumberOfSnacks))
                                break;
                            else
                            {
                                TheCinema->adjustBank(-(SNACK_PRICE));
                                TheCinema->addSnacks();
                            }
                        }
                        else if (ch == 'n' || ch == 'N')
                        {
                            cout << endl << endl << "Perhaps another time then..." << endl << endl;
                            Pause();
                        }
                    }

                    DecisionBuy = 'R';
                }
//-------------------------------------------------------------------------------------------------------------------
                // Player chose to Buy Upgrades. Loop breaks when 'R' or Go Back is selected.
                else if (DecisionBuy == '4')
                {
                    ClearScreen();

                    if (CurrentTheaterAmount > 1)
                    {
                        // Displays the question of which theater to purchase more seats for.
                        choiceTree_01_04(CurrentTheaterAmount);
                        // Player's selection is collected and stored.
                        Decision_TheaterNum = getSelection_TheaterNum(CurrentTheaterAmount);
                        // Takes into account the p_Theaters[] array has a zero index for the first theater.
                        Decision_TheaterNum -= 1;
                    }
                    // Takes into account the p_Theaters[] array has a zero index for the first theater.
                    else Decision_TheaterNum = 0;

                    do
                    {
                        ClearScreen();
                        // Displays theater chosen and the levels for the
                        // sound system, screen size, and projector quality.
                        // Asks which area to upgrade.
                        choiceUpgradeLevels(Decision_TheaterNum + 1,
                                         TheCinema->accessTheaters(Decision_TheaterNum)->getScreenLevel(),
                                         TheCinema->accessTheaters(Decision_TheaterNum)->getProjectorLevel(),
                                         TheCinema->accessTheaters(Decision_TheaterNum)->getSoundLevel());
                        // Player's selection is collected and stored.
                        DecisionBuyUpgrade = getSelectionUpgradePurchase();
                        ClearScreen();
//...................................................................................................................
                        // Player chose to upgrade screen size.
                        if (DecisionBuyUpgrade == '1')
                        {
                            // Displays next level of screen size and cost. Asks player yes or no to purchase.
                            choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getScreenLevel(),
                                                         Screen_Size);
                            // Player's selection is collected and stored.
                            char ch = getYesOrNo();
                            if (ch == 'y' || ch == 'Y')
                            {
                                // If check comes back true, there's not enough money in the bank.
                                if (checkPurchaseOfUpgrade(CurrentBankAmount,
                                                          TheCinema->accessTheaters(Decision_TheaterNum)->getScreenLevel(),
                                                          Screen_Size))
                                {
                                    // Purchase failed, control reverts back to specific theater's upgrade options.
                                    DecisionBuyUpgrade = 'R';
                                }
                                else
                                {
                                    TheCinema->adjustBank(-(UPGRADE_PRICE));
                                    TheCinema->accessTheaters(Decision_TheaterNum)->addScreenLevel();
                                    // With purchase made, control reverts back to main menu.
                                    DecisionBuyUpgrade = 'R';
                                    DecisionBuy = 'R';
                                }
                            }
                            else if (ch == 'n' || ch == 'N')
                            {
                                cout << endl << endl << "Perhaps another time then..." << endl << endl;
                                Pause();
                            }
                        }
//...................................................................................................................
                        // Player chose to upgrade projector quality.
                        else if (DecisionBuyUpgrade == '2')
                        {
                            // Displays next level of projector quality and cost. Asks player yes or no to purchase.
                            choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getProjectorLevel(),
                                                         Projector_Quality);
                            // Player's selection is collected and stored.
                            char ch = getYesOrNo();
                            if (ch == 'y' || ch == 'Y')
                            {
                                // If check comes back true, there's not enough money in the bank.
                                if (checkPurchaseOfUpgrade(CurrentBankAmount,
                                                          TheCinema->accessTheaters(Decision_TheaterNum)->getProjectorLevel(),
                                                          Projector_Quality))
                                {
                                    // Purchase failed, control reverts back to specific theater's upgrade options.
                                    DecisionBuyUpgrade = 'R';
                                }
                                else
                                {
                                    TheCinema->adjustBank(-(UPGRADE_PRICE));
                                    TheCinema->accessTheaters(Decision_TheaterNum)->addProjectorLevel();
                                    // With purchase made, control reverts back to main menu.
                                    DecisionBuyUpgrade = 'R';
                                    DecisionBuy = 'R';
                                }
                            }
                            else if (ch == 'n' || ch == 'N')
                            {
                                cout << endl << endl << "Perhaps another time then..." << endl << endl;
                                Pause();
                            }
                        }
//...................................................................................................................
                        // Player chose to upgrade sound intensity.
                        else if (DecisionBuyUpgrade == '3')
                        {
                            // Displays next level of sound intensity and cost. Asks player yes or no to purchase.
                            choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getSoundLevel(),
                                                         Sound_Intensity);
                            // Player's selection is collected and stored.
                            char ch = getYesOrNo();
                            if (ch == 'y' || ch == 'Y')
                            {
                                // If check comes back true, there's not enough money in the bank.
                                if (checkPurchaseOfUpgrade(CurrentBankAmount,
                                                          TheCinema->accessTheaters(Decision_TheaterNum)->getSoundLevel(),
                                                          Sound_Intensity))
                                {
                                    // Purchase failed, control reverts back to specific theater's upgrade options.
                                    DecisionBuyUpgrade = 'R';
                                }
                                else
                                {
                                    TheCinema->adjustBank(-(UPGRADE_PRICE));
                                    TheCinema->accessTheaters(Decision_TheaterNum)->addSoundLevel();
                                    // With purchase made, control reverts back to main menu.
                                    DecisionBuyUpgrade = 'R';
                                    DecisionBuy = 'R';
                                }
                            }
                            else if (ch == 'n' || ch == 'N')
                            {
                                cout << endl << endl << "Perhaps another time then..." << endl << endl;
                                Pause();
                            }
                        }
                        // Player chose to go back a step.
                        else DecisionBuyUpgrade = 'R';

                        // With purchase made, control reverts back to main menu with updates to HUD.
                    } while (DecisionBuyUpgrade != 'R');

                        DecisionBuy = 'R';
                }
                // Player chose to Buy a Promotional Offer. Loop breaks when 'R' or Go Back is selected.
//-------------------------------------------------------------------------------------------------------------------
                else if (DecisionBuy == '5')
                {
                    ClearScreen();
                    // Displays details about promotions, and asks if a promotion is desired.
                    choiceTree_01_05(CurrentPromotionsSelected);
                    // Player's selection is collected and stored.
                    int NewPromotion = getSelection_01_05(CurrentPromotionsSelected);
                    // Player's selection is converted to PromotionsSelected, and announces result.
                    TheCinema->changePromotionSelected(NewPromotion);
                    TheCinema->setPromotionInUse(calculatePromotionLevel(NewPromotion));
                    // With change complete, control reverts to main menu.
                    DecisionBuy = 'R';
                }
                // Player chose to Buy an Additional Theater. Loop breaks when 'R' or Go Back is selected.
//-------------------------------------------------------------------------------------------------------------------
                else if (DecisionBuy == '6')
                {
                    ClearScreen();
                    // Displays details about purchasing another theater, and asks if yes/no.
                    choiceTree_01_06(CurrentTheaterAmount);
                    // Player's selection is collected and stored.
                    bool PlayerBuysTheater = getSelection_01_06(CurrentBankAmount, CurrentTheaterAmount);
                    // Player said yes to theater purchase
                    if (PlayerBuysTheater)
                    {
                        TheCinema->addTheater();
                        TheCinema->adjustBank(-(THEATER_PRICE));
                    }
                    // With decision to buy (or not) complete, control reverts to main menu.
                    DecisionBuy = 'R';
                }
            } while (DecisionBuy != 'R');
            break;
//MAIN SWITCH - MANAGE STAFF#########################################################################################
        case '2' :
            // Player chose to Manage the Staff. Loop breaks when 'R' or Go Back is selected.
            do
            {
                ClearScreen();
                // Displays Manage Staff choices: Hire more people, or Fire them.
                choiceTree_02();
                // Player's selection is collected and stored.
                DecisionStaff = getSelection_02();
//...................................................................................................................
                // Player chose to Hire more people.
                if (DecisionStaff == '1')
                {
                    // Player chose to Hire Staff
                    ClearScreen();
                    choiceHireStaff(CurrentEmployeeAmount, CurrentTheaterAmount);
                    ChangeStaff = getNumOfEmployeesToHire(CurrentEmployeeAmount, CurrentTheaterAmount);
                    TheCinema->changeNumOfEmployees(ChangeStaff);
                    DecisionStaff = 'R';
                    Pause();
                }
//...................................................................................................................
                // Player chose to Fire some people.
                else if (DecisionStaff == '2')
                {
                    // Player chose to Fire Staff
                    ClearScreen();
                    choiceFireStaff(CurrentEmployeeAmount, CurrentTheaterAmount);
                    ChangeStaff = getNumOfEmployeesToFire(CurrentEmployeeAmount, CurrentTheaterAmount);
                    TheCinema->changeNumOfEmployees(-ChangeStaff);
                    DecisionStaff = 'R';
                    Pause();
                }
            } while (DecisionStaff != 'R');
            break;
//MAIN SWITCH - CHANGE TICKET PRICE##################################################################################
        case '3' :
            ClearScreen();
            // Player chose to Change the Ticket Price. Loop breaks when 'R' or Go Back is selected.
            choiceTree_03(CurrentTicketPrice);
            // Player's selection is collected and stored.
            cout << "==> ";
            TheCinema->changeTicketPrice(getNewTicketPrice());
            break;
//MAIN SWITCH - CHANGE MOVIE#########################################################################################
        case '4' :

            char ch;

            // Player chose to Change the Movie in a selected theater.
            ClearScreen();
            if (CurrentTheaterAmount > 1)
            {
                // Displays the question of which theater to change the movie for.
                choiceTree_04(CurrentTheaterAmount);
                // Player's selection is collected and stored.
                Decision_TheaterNum = getSelection_TheaterNum(CurrentTheaterAmount);
                // Takes into account the p_Theaters[] array has a zero index for the first theater.
                Decision_TheaterNum -= 1;
            }
            else Decision_TheaterNum = 0;
            // Lists movies player has license to play. Asks player to choose a movie.
            DecisionMovieSelection = 'Z';
            while (CurrentNumOfLicensesOwned > 0 && DecisionMovieSelection != 'R')
            {
                // This loop continue to refresh list of available licenses until a change in finalized.
                do
                {
                    ClearScreen();
                    // Displays theater chosen and the movie presently playing.
                    currentMovie(Decision_TheaterNum + 1,
                                 TheCinema->accessTheaters(Decision_TheaterNum)->getSelectedMovie()->getTitle());
                    // Displays all the movie licenses purchased by Player.
                    for (int i = 0; i <= CurrentNumOfLicensesOwned; i += 2)
                    {
                        if (TheCinema->accessMovieLicense(i)->getTitle() != "Untitled")
                        {
                            cout << (i + 1) << ". " << TheCinema->accessMovieLicense(i)->getTitle();
                            cout << "\t\t\t";
                        }
                        if (CurrentNumOfLicensesOwned > (i + 1))
                        {
                            cout << (i + 2) << ". " << TheCinema->accessMovieLicense(i + 1)->getTitle();
                            cout << endl;
                        }
                    }
                    cout << (CurrentNumOfLicensesOwned + 1) <<". Play Nothing" << endl << endl;
                    cout << "Select one of the above choices for more information:";
                    // Since the number of options is variable depending how many licenses are owned at the
                    // time of call, the loop ensures the selection entered matches only the options offered.
                    do
                    {
                        // Player's selection is collected and stored.
                        MovieLicenseSelected = getSelectedLicense();
                        if (MovieLicenseSelected > CurrentNumOfLicensesOwned)
                        {
                            // The + 1 return what the Player selected, not the index position given w/o + 1.
                            cout << (MovieLicenseSelected + 1) << " is not a valid selection. Try again: ";
                        }
                    } while (MovieLicenseSelected > CurrentNumOfLicensesOwned);

                    ClearScreen();
                    // Distinguishes between an actual title selected or the option to Play Nothing.
                    if (MovieLicenseSelected != CurrentNumOfLicensesOwned)
                    {
                        // Display Title, Synopsis, Popularity, etc of the Movie that Player selected.
                        TheCinema->accessMovieLicense(MovieLicenseSelected)->displayMovieDetails();
                        cout << endl << endl << "Would you like to play this movie in your theater? (Y or N)";
                        ch = getYesOrNo();
                    }
                    else if (MovieLicenseSelected == CurrentNumOfLicensesOwned)
                    {
                        cout << "When there's no movie playing in a theater, it won't sell any tickets." << endl << endl;
                        cout << "Are you sure you want to play no movie in this theater? (Y or N)";
                        ch = getYesOrNo();
                    }
                } while (ch != 'Y' && ch != 'y');

                // If Play nothing, the default options are installed.
                if (MovieLicenseSelected >= CurrentNumOfLicensesOwned)
                {
                    TheCinema->accessTheaters(Decision_TheaterNum)->changeMovie(NULL);
                }
                // If not Play Nothing, the chosen movie is installed.
                else
                {
                    TheCinema->accessTheaters(Decision_TheaterNum)->changeMovie(
                               TheCinema->accessMovieLicense(MovieLicenseSelected));
                }
                // Lets Player know what Movie is now playing in the selected theater number.
                string Title = TheCinema->accessTheaters(Decision_TheaterNum)->getSelectedMovie()->getTitle();

                cout << "You've selected to play ";
                if (Title != "No Movie Playing")
                {
                    cout << Title;
                }
                else
                    {
                        cout << "nothing";
                    }
                cout << " in Theater #" << (Decision_TheaterNum + 1) << endl << endl;

                Pause();
                // With Selection completed, control reverts back to main menu.
                DecisionMovieSelection = 'R';
            }
            // Player owns no licenses.
            if (CurrentNumOfLicensesOwned <= 0)
            {
                cout << "You currently have no licenses." << endl << endl;
                cout << "Purchase at least one or you won't sell any tickets." << endl << endl;
                Pause();
            }
            break;
//MAIN SWITCH - END TURN#############################################################################################
        case '5' :
            // Counts how many theaters have no movies playing.
            TheatersWithoutMoviesPlaying = 0;
            for (int i = 0; i < CurrentTheaterAmount; i++)
            {
                if (TheCinema->accessTheaters(i)->getSelectedMovie()->getTitle() == "No Movie Playing")
                {
                    TheatersWithoutMoviesPlaying++;
                }
            }
            // Checks to make sure player wants to end turn even if some theaters have no movies playing.
            char cha;
            // Resets variable for next loop.
            cha = 'Z';
            if (TheatersWithoutMoviesPlaying > 0)
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(10);
                cout << "You have one or more theaters without movies playing.";
                BlankSpaces(14);
                cout << "X" << endl << "X";
                BlankSpaces(10);
                cout << "Theaters without movies playing, earn no profit.";
                BlankSpaces(19);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(10);
                cout << "Are you sure you want to end you your turn? (Y or N)";
                BlankSpaces(15);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(6);
                do
                {
                    cha = getYesOrNo();
                } while (cha != 'N' && cha != 'n' && cha != 'Y' && cha != 'y');
                if (cha == 'N' || cha == 'n')
                {
                    break;
                }
            }
            TheatersWithoutMoviesPlaying = 0;
            // Makes sure player actually wants to end turn. This If checks in case previous If already checked.
            if (cha != 'Y' && cha != 'y')
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "Are you sure you want to end your turn? (Y or N)";
                BlankSpaces(14);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(8);
                do
                {
                    cha = getYesOrNo();
                } while (cha != 'N' && cha != 'n' && cha != 'Y' && cha != 'y');
                if (cha == 'N' || cha == 'n')
                {
                    break;
                }
            }
            // The number of people who buy tickets is calculated and Bank is adjusted.
            NumTicketsPurchased = 0;
            RandomAttendanceQuotient = ((float)rand() / (RAND_MAX)) + 0.1;
            for (int i = 0; i < CurrentTheaterAmount; i++)
            {
                Season BSeason = TheCinema->accessTheaters(i)->getSelectedMovie()->getBestSeason();
                Season WSeason = TheCinema->accessTheaters(i)->getSelectedMovie()->getWorstSeason();

                NumTicketsPurchased += TheCinema->accessTheaters(i)->
                    getNumTicketsPurchased(RandomAttendanceQuotient,
                                           getTPriceFactor(CurrentTicketPrice),
                                           getSeasonFactor(CurrentSeasonInt, BSeason, WSeason),
                                           getPromoFactor(CurrentPromotionsSelected),
                                           getStaffFactor(CurrentEmployeeAmount, CurrentTheaterAmount));
            }
            TheCinema->adjustTicketSales(NumTicketsPurchased);
            // The amount in $ of snacks purchased is calculated and Bank is adjusted--assuming $5 per snack.
            RandomAttendanceQuotient = ((float)rand() / (RAND_MAX)) + 0.1;
            TheCinema->adjustSnackSales(RandomAttendanceQuotient * (1 + (TheCinema->getNumOfSnacks() / 10)) * NumTicketsPurchased * 5);
            // Random event encounter has a one in three chance of happening.
            if ( (rand() % 3) == 2)
            {
                ClearScreen();
                RandomEventIndex = rand() % RANDOM_EVENTS_MAX;
                TheREHandler->getRandomEvent(RandomEventIndex)->presentEvent();
                DecisionRandomEvent = getRandomEventChoice();
                ClearScreen();
                // Presents outcome of player's decision, calculates money gained or lost, and adds/subtracts that from Bank.
                TheCinema->adjustBank(TheREHandler->getRandomEvent(RandomEventIndex)->presentOutcome(DecisionRandomEvent));
            }
            else
            {
                ClearScreen();
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "Nothing out of the ordinary happens this week.";
                BlankSpaces(16);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(8);
                Pause();
                ClearScreen();
            }

            // Advance the calendar one week.
            TheCinema->p_Calendar->nextWeek();
            // Deduct rent and employees from the bank.
            TheCinema->adjustExpenses((CurrentTheaterAmount * THEATER_RENT), (CurrentEmployeeAmount * EMPLOYEE_WAGE));
            // Reduces each owned movie license by one week.
            for (int i = 0; i < CurrentNumOfLicensesOwned; i++)
            {
                TheCinema->accessMovieLicense(i)->adjustUseOfLicenseRemainingInWeeks();
            }
            // If license runs out, it's removed from owned licenses.
            for (int i = 0; i < MOVIES_MAX; i++)
            {
                if (TheCinema->accessMovieLicense(i)->getUseOfLicenseRemainingInWeeks() <= 0 &&
                    TheCinema->accessMovieLicense(i)->getTitle() != "Untitled")
                {
                    // If a theater is playing an expired license, it is set to blank screen mode.
                    for (int k = 0; k < CurrentTheaterAmount; k++)
                    {
                        if (TheCinema->accessTheaters(k)->getSelectedMovie() == TheCinema->accessMovieLicense(i))
                        {
                            TheCinema->accessTheaters(k)->changeMovie(NULL);
                        }
                    }
                    // If license to be removed is in last index, simply replace with blank movie license.
                    if ( i == (MOVIES_MAX - 1) )
                    {

                        TheCinema->addMovieLicense(new Movie, i);
                    }
                    // If license is anywhere but last, shift all items down one through replacing
                    // the present index with the +1 index.
                    else
                    {
                        for (int j = i; j < (MOVIES_MAX - 1); j++)
                        {
                            TheCinema->addMovieLicense(TheCinema->accessMovieLicense(j + 1), j);
                        }
                    }
                    // This is where the count of owned licenses is reduced by 1.
                    TheCinema->subtractNumOfMovieLicenses();
                    // Since the movie in i index was removed, and the next license set in it's place,
                    // the i must be brought back by one to avoid skipping a license.
                    i--;
                }
            }
            break;
//MAIN SWITCH - HELP#################################################################################################
        case 'h' :
            Decision = getConfirmation('H');
            ClearScreen();
            if (Decision == 'H')
            {
                runInstructions();
            }
            break;
        case 'H' :
            Decision = getConfirmation('H');
            ClearScreen();
            if (Decision == 'H')
            {
                runInstructions();
            }
            break;
//MAIN SWITCH - QUIT#################################################################################################
        case 'q' :
            Decision = getConfirmation(Decision);
            break;
        case 'Q' :
            Decision = getConfirmation(Decision);
            break;
        default:
            cout << "Case statement reached default. This should not happen." << endl;
        }
//END OF MAIN SWITCH@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

        ClearScreen();
    } while(Decision != 'Q');
}
