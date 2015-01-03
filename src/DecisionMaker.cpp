#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <locale>
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
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You've selected to Make a Purchase.";
    BlankSpaces(37);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "1. Buy More Seats";
    BlankSpaces(55);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "2. Buy More Movie Licenses";
    BlankSpaces(46);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "3. Buy More Snack Choices";
    BlankSpaces(47);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "4. Buy Upgrades";
    BlankSpaces(57);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "5. Buy Promotional Event";
    BlankSpaces(48);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "6. Buy Additional Theater";
    BlankSpaces(47);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "R. Go Back";
    BlankSpaces(62);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Which of these actions do you want to perform?";
    BlankSpaces(26);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(3);
}

void DecisionMaker::choiceTree_01_01(int Theaters)
{
    if (Theaters > 1)
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You've chosen to purchase more seats for your theater.";
        BlankSpaces(18);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You have " << Theaters << " theater(s).";
        if (Theaters < 10)
        {
            BlankSpaces(50);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(49);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(48);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Select 1 through " << Theaters << " to choose which theater to buy seats for:";
        if (Theaters < 10)
        {
            BlankSpaces(12);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(11);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(10);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
        cout << "==> ";
    }
    else
    {
        cout << "WARNING: An incorrent # of Theaters was entered into" << endl;
        cout << "DecisionMaker::choiceTree_01_01(int Theaters)" << endl;
    }
}

void DecisionMaker::choiceTree_01_03(int SnacksOwned)
{
    string SnackToBuy = Snacks[SnacksOwned];

    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You've chosen to increase your selection of snacks offered.";
    BlankSpaces(13);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You currently offer: ";
    for (int i = 0; i < SnacksOwned; i++)
    {
        // Bypasses the commas and the "and"
        if (SnacksOwned == 1)
        {
            cout << Snacks[i];
            break;
        }
        // Because the sixth snack won't fit, this drops it down to the next line.
        if (i == 5)
        {
            BlankSpaces(6);
            cout << "X" << endl << "X";
            BlankSpaces(26);
            cout << "and " << Snacks[i];
            break;
        }
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
    cout << ".";
    if (SnacksOwned <= 0)
        {
            cout << "ERROR: System reading Zero or less snacks owned!" << endl;
            Pause();
        }
        else if (SnacksOwned == 1)
        {
            BlankSpaces(43);
        }
        else if (SnacksOwned == 2)
        {
            BlankSpaces(31);
        }
        else if (SnacksOwned == 3)
        {
            BlankSpaces(21);
        }
        else if (SnacksOwned == 4)
        {
            BlankSpaces(12);
        }
        else if (SnacksOwned == 5)
        {
            BlankSpaces(3);
        }
        else if (SnacksOwned == 6)
        {
            BlankSpaces(32);
        }
        else if (SnacksOwned == 7)
        {
            cout << "ERROR: Maximum snack amount exceeded. Please readjust SNACK_MAX." << endl;
            Pause();
        }

    if (SnacksOwned >= SNACK_MAX)
    {
        BlankSpaces(7);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You currently offer all the available snacks.";
        BlankSpaces(27);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Try spending your money on other lucrative purchases.";
        BlankSpaces(19);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);

        Pause();

        return;
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "The next snack option, " << SnackToBuy << ", will cost you $" << SNACK_PRICE;
    BlankSpaces(22);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "to buy the necessary machinery.";
    BlankSpaces(41);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Would you like to add " << SnackToBuy << " to your snacks counter? (Y or N)";
    BlankSpaces(10);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);
}

void DecisionMaker::choiceTree_01_04(int Theaters)
{
    if (Theaters > 1)
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You've chosen to purchase upgrades for your cinema.";
        BlankSpaces(21);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You have " << Theaters << " theater(s).";
        if (Theaters < 10)
        {
            BlankSpaces(50);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(49);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(48);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Select 1 through " << Theaters << ", (then ENTER)";
        if (Theaters < 10)
        {
            BlankSpaces(40);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(39);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(38);
        }
        cout << "X" << endl << "X";
        BlankSpaces(5);
        cout << "to choose which theater to buy upgrades for:";
        BlankSpaces(28);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
        cout << "==> ";
    }
}

void DecisionMaker::choiceTree_01_05(int PromotionInUseIndex)
{
    string PromotionInUse = Promotions[PromotionInUseIndex];

    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "You've chosen to change the promotion you're using.";
    BlankSpaces(16);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "You're currently using: " << PromotionInUse << " ($" << (PROMOTION_MULTIPLY_COST * PromotionInUseIndex);
    cout << " / Week)";
    BlankSpaces(19);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "The available promotions are as follows:";
    BlankSpaces(27);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    for (int i = 0; i < 6; i++)
    {
        cout << i << ". " << Promotions[i] << " ($" << (PROMOTION_MULTIPLY_COST * i) << " / Week)";
        if (i == 0)
        {
            BlankSpaces(40);
        }
        else
        {
            BlankSpaces(38);
        }
        cout << "X" << endl << "X";
        BlankSpaces(10);
    }
    cout << "Which promotion would like to use?";
    BlankSpaces(33);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(2);
}

void DecisionMaker::choiceTree_01_06(int Theaters)
{
    int TotalTheaterRent = Theaters * THEATER_RENT;

    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You've chosen to expand your Cinema by one additional theater.";
    BlankSpaces(10);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "A new theater costs $" << THEATER_PRICE << ".";
    if (THEATER_PRICE < 10)
    {
        BlankSpaces(49);
    }
    else if (THEATER_PRICE >= 10 && THEATER_PRICE < 100)
    {
        BlankSpaces(48);
    }
    else if (THEATER_PRICE >= 100 && THEATER_PRICE < 1000)
    {
        BlankSpaces(47);
    }
    else if (THEATER_PRICE >= 1000 && THEATER_PRICE < 10000)
    {
        BlankSpaces(46);
    }
    else if (THEATER_PRICE >= 10000 && THEATER_PRICE < 100000)
    {
        BlankSpaces(45);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Keep in mind that each theater you own costs";
    BlankSpaces(28);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "you $" << THEATER_RENT << " per Week in rent.";
    if (THEATER_RENT < 10)
    {
        BlankSpaces(48);
    }
    else if (THEATER_RENT >= 10 && THEATER_RENT < 100)
    {
        BlankSpaces(47);
    }
    else if (THEATER_RENT >= 100 && THEATER_RENT < 1000)
    {
        BlankSpaces(46);
    }
    else if (THEATER_RENT >= 1000 && THEATER_RENT < 10000)
    {
        BlankSpaces(45);
    }
    else if (THEATER_RENT >= 10000 && THEATER_RENT < 100000)
    {
        BlankSpaces(44);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Your cinema currently has " << Theaters << " theater(s) out of a maximum of " << THEATERS_MAX << ".";
    if (Theaters < 10 && THEATERS_MAX < 10)
    {
        BlankSpaces(11);
    }
    else if (Theaters < 10 && THEATERS_MAX >= 10 && THEATERS_MAX < 100)
    {
        BlankSpaces(10);
    }
    else if ((Theaters < 10 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000) ||
             (Theaters >= 10 && Theaters < 100 && THEATERS_MAX >= 10 && THEATERS_MAX < 100))
    {
        BlankSpaces(9);
    }
    else if (Theaters >= 10 && Theaters < 100 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000)
    {
        BlankSpaces(8);
    }
    else if (Theaters >= 100 && Theaters < 1000 && THEATERS_MAX >= 100 && THEATERS_MAX < 1000)
    {
        BlankSpaces(7);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "This number of theater(s) costs you $" << TotalTheaterRent << " per Week in rent.";
    if (TotalTheaterRent < 10)
    {
        BlankSpaces(16);
    }
    else if (TotalTheaterRent >= 10 && TotalTheaterRent < 100)
    {
        BlankSpaces(15);
    }
    else if (TotalTheaterRent >= 100 && TotalTheaterRent < 1000)
    {
        BlankSpaces(14);
    }
    else if (TotalTheaterRent >= 1000 && TotalTheaterRent < 10000)
    {
        BlankSpaces(13);
    }
    else if (TotalTheaterRent >= 10000 && TotalTheaterRent < 100000)
    {
        BlankSpaces(12);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    if ( !(Theaters >= THEATERS_MAX) )
    {
        cout << "X";
        BlankSpaces(5);
        cout << "Expand for an additional theater space? (Y or N)";
        BlankSpaces(24);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(3);
    }
    else
    {
        XBorderedBlankSpace();
        BorderX();
        BlankLines(4);

        Pause();
        ClearScreen();

        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You already have the maximum amount of theaters";
        BlankSpaces(25);
        cout << "X" << endl << "X";
        BlankSpaces(5);
        cout << "your building will support";
        BlankSpaces(46);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Try upgrading your existing theaters, picking a better promotion,";
        BlankSpaces(7);
        cout << "X" << endl << "X";
        BlankSpaces(5);
        cout << "or hiring more workers.";
        BlankSpaces(49);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
        Pause();
    }
}

void DecisionMaker::choiceTree_02()
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "You've selected to Manage your Staff.";
    BlankSpaces(30);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "1. Hire Employees";
    BlankSpaces(50);
    cout << "X" << endl << "X";
    BlankSpaces(10);
    cout << "2. Fire Employees";
    BlankSpaces(50);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "R. Go Back";
    BlankSpaces(57);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(10);
    cout << "Which of these actions would you like to perform?";
    BlankSpaces(18);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);
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
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You've selected to Change the Movie in one of your theaters.";
        BlankSpaces(12);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You have " << Theaters << " theater(s).";
        if (Theaters < 10)
        {
            BlankSpaces(50);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(49);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(48);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Select 1 through " << Theaters << ", (then ENTER)";
        if (Theaters < 10)
        {
            BlankSpaces(40);
        }
        else if (Theaters >= 10 && Theaters < 100)
        {
            BlankSpaces(39);
        }
        else if (Theaters >= 100 && Theaters < 1000)
        {
            BlankSpaces(38);
        }
        cout << "X" << endl << "X";
        BlankSpaces(5);
        cout << "to choose which theater to change movies for:";
        BlankSpaces(27);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
        cout << "==> ";
    }
}

void DecisionMaker::choiceNumOfSeats(int TheaterNumber, int AmountOfSeats)
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "In Theater #" << TheaterNumber << ", you have " << AmountOfSeats << " seats.";
    if (TheaterNumber < 10 && AmountOfSeats < 10)
    {
        BlankSpaces(40);
    }
    else if ((TheaterNumber < 10 && AmountOfSeats >= 10 && AmountOfSeats < 100) ||
             (TheaterNumber >= 10 && TheaterNumber < 100 && AmountOfSeats < 10))
    {
        BlankSpaces(39);
    }
    else if ((TheaterNumber < 10 && AmountOfSeats >= 100 && AmountOfSeats < 1000) ||
             (TheaterNumber >= 10 && TheaterNumber < 100 && AmountOfSeats >= 10 && AmountOfSeats < 100))
    {
        BlankSpaces(38);
    }
    else if (TheaterNumber >= 10 && TheaterNumber < 100 && AmountOfSeats >= 100 && AmountOfSeats < 1000)
    {
        BlankSpaces(37);
    }
    else if ((TheaterNumber < 10 && TheaterNumber < 100 && AmountOfSeats >= 1000 && AmountOfSeats < 10000) ||
             (TheaterNumber >= 100 && AmountOfSeats >= 100 && AmountOfSeats < 1000))
    {
        BlankSpaces(36);
    }
    else if ((TheaterNumber < 10 && TheaterNumber < 100 && AmountOfSeats >= 10000 && AmountOfSeats < 100000) ||
             (TheaterNumber >= 100 && AmountOfSeats >= 1000 && AmountOfSeats < 10000))
    {
        BlankSpaces(35);
    }
    else if (TheaterNumber >= 100 && AmountOfSeats >= 10000 && AmountOfSeats < 100000)
    {
        BlankSpaces(34);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Each new seat costs $" << SEAT_PRICE << ".";
    if (SEAT_PRICE < 10)
    {
        BlankSpaces(49);
    }
    else if (SEAT_PRICE >= 10 && SEAT_PRICE < 100)
    {
        BlankSpaces(48);
    }
    else if (SEAT_PRICE >= 100 && SEAT_PRICE < 1000)
    {
        BlankSpaces(47);
    }
    else if (SEAT_PRICE >= 1000 && SEAT_PRICE < 10000)
    {
        BlankSpaces(46);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "The maximum number of seats is " << SEATS_MAX << " for any theater.";
    if (SEATS_MAX < 10)
    {
        BlankSpaces(23);
    }
    else if (SEATS_MAX >= 10 && SEATS_MAX < 100)
    {
        BlankSpaces(22);
    }
    else if (SEATS_MAX >= 100 && SEATS_MAX < 1000)
    {
        BlankSpaces(21);
    }
    else if (SEATS_MAX >= 1000 && SEATS_MAX < 10000)
    {
        BlankSpaces(20);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "How many seats would you like to buy? (Type a number, then ENTER)";
    BlankSpaces(7);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);
    cout << "==> ";
}

void DecisionMaker::choiceUpgradeLevels(int TheaterNumber, float ScreenLevel, float ProjectorLevel, float SoundLevel)
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "In Theater #" << TheaterNumber << ", you have:";
    BlankSpaces(48);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "1. Screen Size:        " << (ScreenLevel * 100) << " square feet.";
    BlankSpaces(30);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "2. Projector Quality:  " << (ProjectorLevel * 1000) << " pixels/square foot.";
    BlankSpaces(22);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "3. Sound Intensity:    " << (SoundLevel * 70) << " decibels.";
    if ((SoundLevel * 70) >= 10 && (SoundLevel * 70) < 100)
    {
        BlankSpaces(34);
    }
    else if ((SoundLevel * 70) >= 100 && (SoundLevel * 70) < 1000)
    {
        BlankSpaces(33);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "R. Go Back";
    BlankSpaces(62);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Which of these systems would you like to upgrade?";
    BlankSpaces(23);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(4);
}

bool DecisionMaker::choiceUpgradeChosenEquipment(float Level, Equipment EquipmentUpgraded)
{
    float LevelUpgraded = Level + 0.1;
    if (EquipmentUpgraded == 0)
    {
        if (Level >= LEVEL_MAX)
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "You've selected to increase your screen size.";
            BlankSpaces(19);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "Your screen size is " << (Level * 100) << " square feet.";
            BlankSpaces(25);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "This is the maximum size available on the market.";
            BlankSpaces(15);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "Try upgrading a different piece of equipment,";
            BlankSpaces(19);
            cout << "X" << endl << "X";
            BlankSpaces(13);
            cout << "or select a different theater.";
            BlankSpaces(34);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
            Pause();
            return false;
        }
        else
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "You've selected to increase your screen size.";
            BlankSpaces(17);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "To upgrade from " << (Level * 100) << " square feet to ";
            BlankSpaces(24);
            cout << "X" << endl << "X";
            BlankSpaces(15);
            cout << (LevelUpgraded * 100) << " square feet, it will cost $" << UPGRADE_PRICE << ".";
            BlankSpaces(24);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "Purchase upgrade? (Y or N)";
            BlankSpaces(36);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
        }
    }
    else if (EquipmentUpgraded == 1)
    {
        if (Level >= LEVEL_MAX)
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "You've selected to increase your projector quality.";
            BlankSpaces(13);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "Your projector quality is " << (Level * 1000) << " pixels/square foot.";
            BlankSpaces(11);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "This is the maximum size available on the market.";
            BlankSpaces(15);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(13);
            cout << "Try upgrading a different piece of equipment,";
            BlankSpaces(19);
            cout << "X" << endl << "X";
            BlankSpaces(13);
            cout << "or select a different theater.";
            BlankSpaces(34);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
            Pause();
            return false;
        }
        else
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(10);
            cout << "You've selected to increase your projector quality.";
            BlankSpaces(16);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(10);
            cout << "To upgrade from " << (Level * 1000) << " pixels/square foot to " << (LevelUpgraded * 1000);
            BlankSpaces(14);
            cout << "X" << endl << "X";
            BlankSpaces(10);
            cout << "pixels/square foot, it will cost $" << UPGRADE_PRICE;
            if (UPGRADE_PRICE < 10)
            {
                BlankSpaces(32);
            }
            else if (UPGRADE_PRICE >= 10 && UPGRADE_PRICE < 100)
            {
                BlankSpaces(31);
            }
            else if (UPGRADE_PRICE >= 100 && UPGRADE_PRICE < 1000)
            {
                BlankSpaces(30);
            }
            else if (UPGRADE_PRICE >= 1000 && UPGRADE_PRICE < 10000)
            {
                BlankSpaces(29);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(10);
            cout << "Purchase upgrade? (Y or N)";
            BlankSpaces(41);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
        }
    }
    else if (EquipmentUpgraded == 2)
    {
        if (Level >= LEVEL_MAX)
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "You've selected to increase your sound intensity.";
            BlankSpaces(14);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "Your sound volume is " << (Level * 70) << " decibels.";
            if ((Level * 70) >= 10 && (Level * 70) < 100)
            {
                BlankSpaces(27);
            }
            else if ((Level * 70) >= 100 && (Level * 70) < 1000)
            {
                BlankSpaces(26);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "This is the maximum size available on the market.";
            BlankSpaces(14);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "Try upgrading a different piece of equipment,";
            BlankSpaces(18);
            cout << "X" << endl << "X";
            BlankSpaces(14);
            cout << "or select a different theater.";
            BlankSpaces(33);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
            Pause();
            return false;
        }
        else
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "You've selected to increase your sound intensity.";
            BlankSpaces(14);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "To upgrade from " << (Level * 70) << " decibels to " << (LevelUpgraded * 70);
            if ((Level * 70) >= 10 && (Level * 70) < 100 && (LevelUpgraded * 70) >= 10 && (LevelUpgraded * 70) < 100)
            {
                BlankSpaces(24);
            }
            else if (((Level * 70) >= 100 && (Level * 70) < 1000 && (LevelUpgraded * 70) >= 10 && (LevelUpgraded * 70) < 100) ||
                     ((Level * 70) >= 10 && (Level * 70) < 100 && (LevelUpgraded * 70) >= 100 && (LevelUpgraded * 70) < 1000))
            {
                BlankSpaces(23);
            }
            cout << "X" << endl << "X";
            BlankSpaces(14);
            cout << "decibels, it will cost $" << UPGRADE_PRICE << ".";
            if (UPGRADE_PRICE < 10)
            {
                BlankSpaces(37);
            }
            else if (UPGRADE_PRICE >= 10 && UPGRADE_PRICE < 100)
            {
                BlankSpaces(36);
            }
            else if (UPGRADE_PRICE >= 100 && UPGRADE_PRICE < 1000)
            {
                BlankSpaces(35);
            }
            else if (UPGRADE_PRICE >= 1000 && UPGRADE_PRICE < 10000)
            {
                BlankSpaces(34);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(14);
            cout << "Purchase upgrade? (Y or N)";
            BlankSpaces(37);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);
        }
    }
    else
    {
        cout << endl << endl << "ERROR: No such equipment type exists!" << endl << endl;
    }
    return true;
}

string DecisionMaker::calculateStaffLevel(int Employees, int Theaters)
{
    int MaxEmployees = Theaters * 5;
    int StaffLevelEquation = (int)(5 * ((float)Employees / ((float)MaxEmployees))) - 1;
    if (StaffLevelEquation < 0)
    {
        StaffLevelEquation = 0;
    }
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
    int TotalEmployeeCost = Employees * EMPLOYEE_WAGE;

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees, Theaters));

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You currently employ " << Employees << " ";
    if (Employees == 1)
    {
        cout << "person, ";
    }
    else
    {
        cout << "people, ";
    }
    cout << "for a total weekly cost of $" << TotalEmployeeCost << ".";
    if (Employees < 10 && TotalEmployeeCost < 10)
    {
        BlankSpaces(11);
    }
    else if (Employees < 10 && TotalEmployeeCost >= 10 && TotalEmployeeCost < 100)
    {
        BlankSpaces(10);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 10 && TotalEmployeeCost < 100))
    {
        BlankSpaces(9);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000))
    {
        BlankSpaces(8);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000) ||
             (Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000))
    {
        BlankSpaces(7);
    }
    else if ((Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000))
    {
        BlankSpaces(6);
    }
    else if ((Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 1000 && Employees < 10000 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000))
    {
        BlankSpaces(5);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Your staff's performance is " << TheCinema->getStaffPerformance() << ".";
    BlankSpaces(37);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You can employ 5 people for every theater in your cinema.";
    BlankSpaces(15);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Since you have " << Theaters << " theater";
    if (Theaters == 1)
    {
        cout << ", you can employ a total of " << MaxEmployees << " people.";
    }
    else
    {
        cout << "s, you can employ a total of " << MaxEmployees << " people.";
    }

    if (Theaters == 1)
    {
        BlankSpaces(11);
    }
    else if (Theaters > 1 && Theaters < 10 && MaxEmployees < 10)
    {
        BlankSpaces(10);
    }
    else if (Theaters < 10 && MaxEmployees >= 10 && MaxEmployees < 100)
    {
        BlankSpaces(9);
    }
    else if (Theaters >= 10 && Theaters < 100 && MaxEmployees >= 10 && MaxEmployees < 100)
    {
        BlankSpaces(8);
    }
    else if (Theaters >= 10 && Theaters < 100 && MaxEmployees >= 100 && MaxEmployees < 1000)
    {
        BlankSpaces(7);
    }
    else if ((Theaters >= 10 && Theaters < 100 && MaxEmployees >= 1000 && MaxEmployees < 10000) ||
             (Theaters >= 100 && Theaters < 1000 && MaxEmployees >= 100 && MaxEmployees < 1000))
    {
        BlankSpaces(6);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "As it stands, you can hire at most: " << NumAllowedToChange << " more ";
    if (NumAllowedToChange == 1)
    {
        cout << "person.";
    }
    else
    {
        cout << "people.";
    }
    if (NumAllowedToChange < 10)
    {
        BlankSpaces(22);
    }
    else if (NumAllowedToChange >= 10 && NumAllowedToChange < 100)
    {
        BlankSpaces(21);
    }
    else if (NumAllowedToChange >= 100 && NumAllowedToChange < 1000)
    {
        BlankSpaces(20);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Remember that each employee costs $" << EMPLOYEE_WAGE << " per week.";
    if (EMPLOYEE_WAGE < 10)
    {
        BlankSpaces(26);
    }
    else if (EMPLOYEE_WAGE >= 10 && EMPLOYEE_WAGE < 100)
    {
        BlankSpaces(25);
    }
    else if (EMPLOYEE_WAGE >= 100 && EMPLOYEE_WAGE < 1000)
    {
        BlankSpaces(24);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Hire how many people? (Type a number, then ENTER)";
    BlankSpaces(23);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    BlankLines(3);
    cout << "==> ";
}

void DecisionMaker::choiceFireStaff(int Employees, int Theaters)
{
    int NumAllowedToChange = Employees - 1;
    int TotalEmployeeCost = Employees * EMPLOYEE_WAGE;

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees, Theaters));

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You currently employ " << Employees << " ";
    if (Employees == 1)
    {
        cout << "person, ";
    }
    else
    {
        cout << "people, ";
    }
    cout << "for a total weekly cost of $" << TotalEmployeeCost << ".";
    if (Employees < 10 && TotalEmployeeCost < 10)
    {
        BlankSpaces(11);
    }
    else if (Employees < 10 && TotalEmployeeCost >= 10 && TotalEmployeeCost < 100)
    {
        BlankSpaces(10);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 10 && TotalEmployeeCost < 100))
    {
        BlankSpaces(9);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000))
    {
        BlankSpaces(8);
    }
    else if ((Employees < 10 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000) ||
             (Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 100 && TotalEmployeeCost < 1000))
    {
        BlankSpaces(7);
    }
    else if ((Employees >= 10 && Employees < 100 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000))
    {
        BlankSpaces(6);
    }
    else if ((Employees >= 100 && Employees < 1000 && TotalEmployeeCost >= 10000 && TotalEmployeeCost < 100000) ||
             (Employees >= 1000 && Employees < 10000 && TotalEmployeeCost >= 1000 && TotalEmployeeCost < 10000))
    {
        BlankSpaces(5);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Your staff's performance is " << TheCinema->getStaffPerformance() << ".";
    BlankSpaces(37);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "You must have at least 1 employee to operate your cinema, and ";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "each employee costs $" << EMPLOYEE_WAGE << " per week.";
    if (EMPLOYEE_WAGE < 10)
    {
        BlankSpaces(40);
    }
    else if (EMPLOYEE_WAGE >= 10 && EMPLOYEE_WAGE < 100)
    {
        BlankSpaces(39);
    }
    else if (EMPLOYEE_WAGE >= 100 && EMPLOYEE_WAGE < 1000)
    {
        BlankSpaces(38);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "As it stands, you can fire at most: " << (Employees - 1);
    if (NumAllowedToChange == 1)
    {
        cout << " person.";
    }
    else
    {
        cout << " people.";
    }
    if (NumAllowedToChange < 10)
    {
        BlankSpaces(27);
    }
    else if (NumAllowedToChange >= 10 && NumAllowedToChange < 100)
    {
        BlankSpaces(26);
    }
    else if (NumAllowedToChange >= 100 && NumAllowedToChange < 1000)
    {
        BlankSpaces(25);
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Fire how many people? (Type a number, then ENTER)";
    BlankSpaces(23);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    BlankLines(4);
    cout << "==> ";
}

void DecisionMaker::currentMovie(int TheaterNumber, string Title)
{
    locale loc;
    char c;

    string Original = "the movie ";
    Original.append(Title);
    Original.append(" is now playing.");

    string String1 = "";
    string String2 = "";
    string String3 = "";

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "In Theater #" << TheaterNumber << ", ";
    if (Title != "No Movie Playing")
    {
        for (unsigned int i = 0, j = 0, k = 0; i < Original.length();)
        {
            // i keeps track of index in original string.
            // j creates enough whitespace after each string to each line align with border.
            // k ensures there are the same number of characters in each string.
            c = Original[i];
            // Resets j for the next string once j reaches maximum string length.
            if (j >= 57)
            {
                j = 0;
                i++;
            }
            // Fills String1 with approx 52 characters from original string.
            // At the end of nearest word, input begins on string2.
            if (k < 57)
            {
                if (j >= 52 && !isspace(c,loc))
                {
                    String1 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String1 += " ";
                        }
                    }
                }
                else if (j >= 52 && isspace(c,loc))
                {
                    String1 += " ";
                }
                else
                {
                    String1 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String1 += " ";
                        }
                    }
                }
            }
            // Fills String2 with approx 46 characters from original string.
            // At the end of nearest word, input begins on string3.
            else if (k >= 57 && k < 130)
            {
                if (j >= 46 && !isspace(c,loc))
                {
                    String2 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String2 += " ";
                        }
                    }
                }
                else if (j >= 46 && isspace(c,loc))
                {
                    String2 += " ";
                }
                else
                {
                    String2 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String2 += " ";
                        }
                    }
                }
            }
            // In the event the maximum number of character is passed.
            // The extras are dumped into a dummy string.
            else
            {
                cout << "The Original string is too long." << endl;
                String3 += Original[i];
            }
            j++;
            k++;
        }
        cout << String1 << "X" << endl;
        // If the description was short enough to fit into one string, don't display the others.
        if (String2 != "")
        {
            cout << String2 << "X" << endl;
        }
        if (String3 != "")
        {
            cout << String3 << "X" << endl;
        }
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
    }
    else
    {
        cout << "there is no movie playing at the moment.";
        if (TheaterNumber < 10)
        {
            BlankSpaces(17);
        }
        else if (TheaterNumber >= 10 && TheaterNumber < 100)
        {
            BlankSpaces(16);
        }
        else if (TheaterNumber >= 100 && TheaterNumber < 1000)
        {
            BlankSpaces(15);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
    }

    cout << "You are able to play the following movies: ";
    BlankSpaces(29);
    cout << "X" << endl;
    XBorderedBlankSpace();
}

void DecisionMaker::listOfAvailableMovies(int NumOfLicensesOwned)
{
    locale loc;
    char c;
    int TotalLicensesOwned = NumOfLicensesOwned;

    string Original = "";

    string String1 = "";

    cout << "X";
    BlankSpaces(5);

    for (int n = 0; n < TotalLicensesOwned; n++)
    {
        Original = TheCinema->accessMovieLicense(n)->getTitle();

        String1 = "";

        if (n == 0)
        {
            cout << (n + 1) << ". ";
        }
        else
        {
            cout << "X";
            BlankSpaces(5);
            cout << (n + 1) << ". ";
        }
        for (unsigned int i = 0, j = 0, k = 0; i < Original.length();)
        {
            // i keeps track of index in original string.
            // j creates enough whitespace after each string to each line align with border.
            // k ensures there are the same number of characters in each string.
            c = Original[i];
            // Resets j for the next string once j reaches maximum string length.
            if (j >= 57)
            {
                j = 0;
                i++;
            }
            // Fills String1 with approx 46 characters from original string.
            // At the end of nearest word, input begins on string2.
            if (k < 57)
            {
                if (j >= 46 && !isspace(c,loc))
                {
                    String1 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String1 += " ";
                        }
                    }
                }
                else if (j >= 46 && isspace(c,loc))
                {
                    String1 += " ";
                }
                else
                {
                    String1 += Original[i];
                    i++;
                    if ( i >= Original.length() )
                    {
                        for (; j < 56; j++)
                        {
                            String1 += " ";
                        }
                    }
                }
            }
            j++;
            k++;
        }
        cout << String1;
        BlankSpaces(12);
        cout << "X" << endl;
    }
    cout << "X";
    BlankSpaces(5);
    cout << (TotalLicensesOwned + 1) <<". Play Nothing";
    BlankSpaces(57);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Type the number matching your choice, then ENTER:";
    BlankSpaces(23);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    BlankLines(2);
    cout << "==> ";
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
        cout << "==> ";
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
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(17);
                cout << "You've selected the promotion: " << Promotions[i - 48];
                BlankSpaces(17);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(17);
                cout << "It will cost you $" << (PROMOTION_MULTIPLY_COST * (i - 48)) << " / Week to use.";
                if ((PROMOTION_MULTIPLY_COST * (i - 48)) < 10)
                {
                    BlankSpaces(26);
                }
                else if ((PROMOTION_MULTIPLY_COST * (i - 48)) >= 10 && (PROMOTION_MULTIPLY_COST * (i - 48)) < 100)
                {
                    BlankSpaces(25);
                }
                else if ((PROMOTION_MULTIPLY_COST * (i - 48)) >= 100 && (PROMOTION_MULTIPLY_COST * (i - 48)) < 1000)
                {
                    BlankSpaces(24);
                }
                else if ((PROMOTION_MULTIPLY_COST * (i - 48)) >= 1000 && (PROMOTION_MULTIPLY_COST * (i - 48)) < 10000)
                {
                    BlankSpaces(23);
                }
                else if ((PROMOTION_MULTIPLY_COST * (i - 48)) >= 10000 && (PROMOTION_MULTIPLY_COST * (i - 48)) < 100000)
                {
                    BlankSpaces(22);
                }
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(7);
            }
            else
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(18);
                cout << "You've chosen to keep the same promotion.";
                BlankSpaces(18);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(7);
            }

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
    int TotalTheatersCost = (Theaters + 1) * THEATER_RENT;

    while ( !(Theaters >= THEATERS_MAX) )
    {
        ch = getYesOrNo();

        ClearScreen();

        if (ch =='Y' || ch == 'y')
        {
            if (Bank >= THEATER_PRICE)
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "Congratulations!";
                BlankSpaces(46);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "You've expanded your cinema by one theater.";
                BlankSpaces(19);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "It starts off with " << SEATS_MIN << " seats,";
                if (SEATS_MIN < 10)
                {
                    BlankSpaces(35);
                }
                else if (SEATS_MIN >= 10 && SEATS_MIN < 100)
                {
                    BlankSpaces(34);
                }
                else if (SEATS_MIN >= 100 && SEATS_MIN < 1000)
                {
                    BlankSpaces(33);
                }
                else if (SEATS_MIN >= 1000 && SEATS_MIN < 10000)
                {
                    BlankSpaces(32);
                }
                cout << "X" << endl << "X";
                BlankSpaces(15);
                cout << "and currently isn't playing a movie.";
                BlankSpaces(26);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "You now have a total of " << (Theaters + 1) << " theaters,";
                if ((Theaters + 1) < 10)
                {
                    BlankSpaces(27);
                }
                else if ((Theaters + 1) >= 10 && (Theaters + 1) < 100)
                {
                    BlankSpaces(26);
                }
                else if ((Theaters + 1) >= 100 && (Theaters + 1) < 1000)
                {
                    BlankSpaces(25);
                }
                cout << "X" << endl << "X";
                BlankSpaces(15);
                cout << "costing you $" << TotalTheatersCost << " per Week";
                if (TotalTheatersCost < 10)
                {
                    BlankSpaces(39);
                }
                else if (TotalTheatersCost >= 10 && TotalTheatersCost < 100)
                {
                    BlankSpaces(38);
                }
                else if (TotalTheatersCost >= 100 && TotalTheatersCost < 1000)
                {
                    BlankSpaces(37);
                }
                else if (TotalTheatersCost >= 1000 && TotalTheatersCost < 10000)
                {
                    BlankSpaces(36);
                }
                else if (TotalTheatersCost >= 10000 && TotalTheatersCost < 100000)
                {
                    BlankSpaces(35);
                }
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(5);
                Pause();

                return true;
            }
            else
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(9);
                cout << "You don't have enough money in the bank for this expansion.";
                BlankSpaces(9);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(9);
                cout << "Try again when you've got more money.";
                BlankSpaces(31);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(7);
                Pause();

                return false;
            }
        }
        else if (ch =='N' || ch == 'n')
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(24);
            cout << "Perhaps another time then...";
            BlankSpaces(25);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(8);
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
        // Makes sure the number is a number. If not, TheaterSelection is set to trigger next if statement.
        if ( !(cin >> TheaterSelection) )
        {
            TheaterSelection = -1.00;
        }
        // If TheaterSelection isn't within the acceptable range, cin is reset, and the question is re-asked.
        if ( !(TheaterSelection > 0 && TheaterSelection <= Theaters) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            choiceTree_01_01(Theaters);
        }
    } while ( !(TheaterSelection >= 1 && TheaterSelection <= Theaters) );

    return TheaterSelection;
}

int DecisionMaker::getSelectionSeatPurchase(int TheaterNumber, int AmountOfSeats)
{
    int SeatQuantity;

    do
    {
        // Makes sure the number is a number. If not, SeatQuantity is set to trigger next if statement.
        if ( !(cin >> SeatQuantity) )
        {
            SeatQuantity = -1.00;
        }
        // If SeatQuantity isn't within the acceptable range, cin is reset, and the question is re-asked.
        if ( !(SeatQuantity >= 0) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            choiceNumOfSeats(TheaterNumber, AmountOfSeats);
        }
    } while ( !(SeatQuantity >= 0) );

    ClearScreen();

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
    int MaxEmployeesToHire = (Theaters * 5) - Employees;

    do
    {
        // Makes sure the number is a number. If not, HireQuantity is set to trigger next if statement.
        if ( !(cin >> HireQuantity) )
        {
            HireQuantity = -1.00;
        }
        // If HireQuantity isn't within the acceptable range, cin is reset, and the question is re-asked.
        if ( !(HireQuantity >= 0 && HireQuantity <= MaxEmployeesToHire) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            choiceHireStaff(Employees, Theaters);
        }
    } while ( !(HireQuantity >= 0 && HireQuantity <= MaxEmployeesToHire) );

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees + HireQuantity, Theaters));

    ClearScreen();

    if (HireQuantity > 0)
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "You've hired " << HireQuantity << " new employees.";
        if (HireQuantity < 10)
        {
            BlankSpaces(33);
        }
        else if (HireQuantity >= 10 && HireQuantity < 100)
        {
            BlankSpaces(32);
        }
        else if (HireQuantity >= 100 && HireQuantity < 1000)
        {
            BlankSpaces(31);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "There are " << (Employees + HireQuantity) << " people now working at your cinema.";
        if ((Employees + HireQuantity) < 10)
        {
            BlankSpaces(16);
        }
        else if ((Employees + HireQuantity) >= 10 && (Employees + HireQuantity) < 100)
        {
            BlankSpaces(15);
        }
        else if ((Employees + HireQuantity) >= 100 && (Employees + HireQuantity) < 1000)
        {
            BlankSpaces(14);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "Your staff's performance is now " << TheCinema->getStaffPerformance() << ".";
        BlankSpaces(23);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
    }
    else
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(10);
        cout << "Perhaps you'll want to hire more people later...";
        BlankSpaces(19);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(8);
    }

    return HireQuantity;
}

int DecisionMaker::getNumOfEmployeesToFire(int Employees, int Theaters)
{
    int FireQuantity;
    int MaxEmployeesToFire = Employees - 1;

    do
    {
        // Makes sure the number is a number. If not, FireQuantity is set to trigger next if statement.
        if ( !(cin >> FireQuantity) )
        {
            FireQuantity = -1.00;
        }
        // If FireQuantity isn't within the acceptable range, cin is reset, and the question is re-asked.
        if ( !(FireQuantity >= 0 && FireQuantity <= MaxEmployeesToFire) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            choiceFireStaff(Employees, Theaters);
        }
    } while ( !(FireQuantity >= 0 && FireQuantity <= MaxEmployeesToFire) );

    TheCinema->setStaffPerformance(calculateStaffLevel(Employees - FireQuantity, Theaters));

    ClearScreen();

    if (FireQuantity > 0)
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "You've fired " << FireQuantity << " worker";
        if (FireQuantity == 1)
        {
            cout << ". ";
        }
        else
        {
            cout << "s.";
        }
        if (FireQuantity < 10)
        {
            BlankSpaces(39);
        }
        else if (FireQuantity >= 10 && FireQuantity < 100)
        {
            BlankSpaces(38);
        }
        else if (FireQuantity >= 100 && FireQuantity < 1000)
        {
            BlankSpaces(37);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "There ";
        if ((Employees - FireQuantity) == 1)
        {
            cout << "is " << (Employees - FireQuantity) << " person trying to make up the difference.";
        }
        else
        {
            cout << "are " << (Employees - FireQuantity) << " people trying to make up the difference.";
        }
        if ((Employees - FireQuantity) == 1)
        {
            BlankSpaces(11);
        }
        else if ((Employees - FireQuantity) > 1 && (Employees - FireQuantity) < 10)
        {
            BlankSpaces(10);
        }
        else if ((Employees - FireQuantity) >= 10 && (Employees - FireQuantity) < 100)
        {
            BlankSpaces(9);
        }
        else if ((Employees - FireQuantity) >= 100 && (Employees - FireQuantity) < 1000)
        {
            BlankSpaces(8);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "Your staff's performance is now " << TheCinema->getStaffPerformance() << ".";
        BlankSpaces(23);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
    }
    else
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "At least now the lazy peons know you could fire them anytime...";
        BlankSpaces(9);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(8);
    }

    return FireQuantity;
}

float DecisionMaker::getNewTicketPrice()
{
    float NewPrice;

    do
    {
        // Makes sure the number is a number. If not, NewPrice is set to trigger next if statement.
        if ( !(cin >> NewPrice) )
        {
            NewPrice = -1.00;
        }
        // If NewPrice isn't within the acceptable range, cin is reset, and questions is re-asked.
        if ( !(NewPrice >= 0 && NewPrice <= 20) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            choiceTree_03(TheCinema->getTicketPrice());
            cout << "==> ";
        }
    } while ( !(NewPrice >= 0.0 && NewPrice <= 20.0) );
    // Round to the nearest hundredths.
    NewPrice = float(int(NewPrice * 100 + 0.5)) / 100;

    return NewPrice;
}

int DecisionMaker::getSelectedLicense(int NumOfLicensesOwned, int TheaterNum, string Title)
{
    int NewMovie;

    do
    {
        // Makes sure the number is a number. If not, NewMovie is set to trigger next if statement.
        if ( !(cin >> NewMovie) )
        {
            NewMovie = -1.00;
        }
        // If NewMovie isn't within the acceptable range, cin is reset, and the question is re-asked.
        if ( !(NewMovie > 0 && NewMovie <= MOVIES_MAX) )
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            ClearScreen();
            // Recursive use of this function until useful input is received.
            currentMovie(TheaterNum, Title);
            listOfAvailableMovies(NumOfLicensesOwned);
        }
    } while ( !(NewMovie > 0 && NewMovie <= MOVIES_MAX) );

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
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "That would cost $" << CostOfPurchase << ".";
        if (CostOfPurchase < 10)
        {
            BlankSpaces(53);
        }
        else if (CostOfPurchase >= 10 && CostOfPurchase < 100)
        {
            BlankSpaces(52);
        }
        else if (CostOfPurchase >= 100 && CostOfPurchase < 1000)
        {
            BlankSpaces(51);
        }
        else if (CostOfPurchase >= 1000 && CostOfPurchase < 10000)
        {
            BlankSpaces(50);
        }
        else if (CostOfPurchase >= 10000 && CostOfPurchase < 100000)
        {
            BlankSpaces(49);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "You only have $" << Bank << " in the Bank.";
        if (Bank < 10)
        {
            BlankSpaces(43);
        }
        else if (Bank >= 10 && Bank < 100)
        {
            BlankSpaces(42);
        }
        else if (Bank >= 100 && Bank < 1000)
        {
            BlankSpaces(41);
        }
        else if (Bank >= 1000 && Bank < 10000)
        {
            BlankSpaces(40);
        }
        else if (Bank >= 10000 && Bank < 100000)
        {
            BlankSpaces(39);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Try a smaller purchase.";
        BlankSpaces(49);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);

        Pause();
        ClearScreen();

        return false;
    }
    else if ((AmountOfSeats + SeatsToPurchase) > SEATS_MAX)
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(2);
        cout << "That purchase would put you in excess of the " << SEATS_MAX << " seat per theater limit.";
        if (SEATS_MAX < 10)
        {
            BlankSpaces(5);
        }
        else if (SEATS_MAX >= 10 && SEATS_MAX < 100)
        {
            BlankSpaces(4);
        }
        else if (SEATS_MAX >= 100 && SEATS_MAX < 1000)
        {
            BlankSpaces(3);
        }
        else if (SEATS_MAX >= 1000 && SEATS_MAX < 10000)
        {
            BlankSpaces(2);
        }
        else
        {
            BlankSpaces(1);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(2);
        cout << "Try a smaller purchase.";
        BlankSpaces(52);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);

        Pause();

        return false;
    }
    else
    {
        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "This purchase will cost you $" << SEAT_PRICE * SeatsToPurchase << ".";
        if ((SEAT_PRICE * SeatsToPurchase) < 10)
        {
            BlankSpaces(41);
        }
        else if ((SEAT_PRICE * SeatsToPurchase) >= 10 && (SEAT_PRICE * SeatsToPurchase) < 100)
        {
            BlankSpaces(40);
        }
        else if ((SEAT_PRICE * SeatsToPurchase) >= 100 && (SEAT_PRICE * SeatsToPurchase) < 1000)
        {
            BlankSpaces(39);
        }
        else if ((SEAT_PRICE * SeatsToPurchase) >= 1000 && (SEAT_PRICE * SeatsToPurchase) < 10000)
        {
            BlankSpaces(38);
        }
        else if ((SEAT_PRICE * SeatsToPurchase) >= 10000 && (SEAT_PRICE * SeatsToPurchase) < 100000)
        {
            BlankSpaces(37);
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(5);
        cout << "Do you want to make the purchase? (Y or N)";
        BlankSpaces(30);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);
        char ch = getYesOrNo();

        ClearScreen();

        if (ch == 'y' || ch == 'Y')
        {
            if (SeatsToPurchase > 0)
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(5);
                cout << "Congratulations!";
                BlankSpaces(56);
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(5);
                cout << "You've purchased " << SeatsToPurchase << " seat(s) for this theater.";
                if (SeatsToPurchase < 10)
                {
                    BlankSpaces(28);
                }
                else if (SeatsToPurchase >= 10 && SeatsToPurchase < 100)
                {
                    BlankSpaces(27);
                }
                else if (SeatsToPurchase >= 100 && SeatsToPurchase < 1000)
                {
                    BlankSpaces(26);
                }
                cout << "X" << endl;
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(5);
                cout << "The theater now has " << (SeatsToPurchase + AmountOfSeats) << " seats.";
                if ((SeatsToPurchase + AmountOfSeats) < 10)
                {
                    BlankSpaces(44);
                }
                else if ((SeatsToPurchase + AmountOfSeats) >= 10 && (SeatsToPurchase + AmountOfSeats) < 100)
                {
                    BlankSpaces(43);
                }
                else if ((SeatsToPurchase + AmountOfSeats) >= 100 && (SeatsToPurchase + AmountOfSeats) < 1000)
                {
                    BlankSpaces(42);
                }
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(5);
            }
            else
            {
                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(13);
                cout << "Perhaps you'll want to buy seats some other time...";
                BlankSpaces(13);
                cout << "X" << endl;
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                BorderX();
                BlankLines(8);
            }

            Pause();

            return true;
        }
        else if (ch == 'n' || ch == 'N')
        {
            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(20);
            cout << "Perhaps a different quantity then...";
            BlankSpaces(21);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(8);

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
        ClearScreen();

        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(24);
        cout << "You don't have enough money.";
        BlankSpaces(25);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(24);
        cout << "Perhaps you can try again later.";
        BlankSpaces(21);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);
        Pause();
        return true;
    }
    else
    {
        ClearScreen();

        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(3);
        cout << "Congratulations!";
        BlankSpaces(58);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(3);
        cout << "You've purchased the equipment for a new snack to sell.";
        BlankSpaces(19);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(3);
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
                if (SnacksOwned > 1)
                {
                    cout << ", ";
                }
                else cout << " ";
            }
        }
        cout << ".";
        if (SnacksOwned <= 0)
        {
            cout << "ERROR: System reading Zero or less snacks owned!" << endl;
            Pause();
        }
        else if (SnacksOwned == 1)
        {
            BlankSpaces(40);
        }
        else if (SnacksOwned == 2)
        {
            BlankSpaces(30);
        }
        else if (SnacksOwned == 3)
        {
            BlankSpaces(21);
        }
        else if (SnacksOwned == 4)
        {
            BlankSpaces(12);
        }
        else if (SnacksOwned == 5)
        {
            BlankSpaces(3);
        }
        else if (SnacksOwned == 6)
        {
            cout << "ERROR: Maximum snack amount exceeded. Please readjust SNACK_MAX." << endl;
            Pause();
        }
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(6);

        Pause();
        return false;
    }
}

bool DecisionMaker::checkPurchaseOfUpgrade(int Bank, float Level, Equipment EquipmentUpgraded)
{
    if (Bank < UPGRADE_PRICE)
    {
        ClearScreen();

        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(24);
        cout << "You don't have enough money.";
        BlankSpaces(25);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(24);
        cout << "Perhaps you can try again later.";
        BlankSpaces(21);
        cout << "X" << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(7);
        Pause();
        return true;
    }
    else
    {
        ClearScreen();

        BorderX();
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "Congratulations!";
        BlankSpaces(46);
        cout << "X" << endl;
        XBorderedBlankSpace();
        cout << "X";
        BlankSpaces(15);
        cout << "You've purchased an upgrade to your ";
        if (EquipmentUpgraded == 0)
        {
            cout << "screen size.";
            BlankSpaces(14);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "It is now " << ((Level + 0.1) * 100) << " square feet.";
            BlankSpaces(33);
            cout << "X" << endl;
        }
        else if (EquipmentUpgraded == 1)
        {
            cout << "projector quality.";
            BlankSpaces(8);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "It is now " << ((Level + 0.1) * 1000) << " pixels/square foot.";
            BlankSpaces(25);
            cout << "X" << endl;
        }
        else if (EquipmentUpgraded == 2)
        {
            cout << "sound intensity.";
            BlankSpaces(10);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "It is now " << ((Level + 0.1) * 70) << " decibels.";
            if (((Level + 0.1) * 70) >= 10 && ((Level + 0.1) * 70) < 100)
            {
                BlankSpaces(37);
            }
            else if (((Level + 0.1) * 70) >= 100 && ((Level + 0.1) * 70) < 1000)
            {
                BlankSpaces(36);
            }
            cout << "X" << endl;
        }
        else cout << endl << endl << "ERROR: No such equipment type exists!" << endl << endl;
        XBorderedBlankSpace();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(5);
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
            int CurrentBank = fabs(TheCinema->getBank());

            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(5);
            cout << "WARNING: You are in debt to the bank for a total of -$";
            cout << CurrentBank << ".";
            if (CurrentBank < 10)
            {
                BlankSpaces(16);
            }
            else if (CurrentBank >= 10 && CurrentBank < 100)
            {
                BlankSpaces(15);
            }
            else if (CurrentBank >= 100 && CurrentBank < 1000)
            {
                BlankSpaces(14);
            }
            else if (CurrentBank >= 1000 && CurrentBank < 10000)
            {
                BlankSpaces(13);
            }
            else if (CurrentBank >= 10000 && CurrentBank < 100000)
            {
                BlankSpaces(12);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(5);
            cout << "If your debt reaches -$" << DEBT_MAX << ", they will foreclose on your cinema.";
            if (DEBT_MAX < 10)
            {
                BlankSpaces(11);
            }
            else if (DEBT_MAX >= 10 && DEBT_MAX < 100)
            {
                BlankSpaces(10);
            }
            else if (DEBT_MAX >= 100 && DEBT_MAX < 1000)
            {
                BlankSpaces(9);
            }
            else if (DEBT_MAX >= 1000 && DEBT_MAX < 10000)
            {
                BlankSpaces(8);
            }
            else if (DEBT_MAX >= 10000 && DEBT_MAX < 100000)
            {
                BlankSpaces(7);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(7);
            Pause();
            ClearScreen();
        }
        if (TheCinema->getBank() <= -(DEBT_MAX))
        {
            int CurrentBank = fabs(TheCinema->getBank());

            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "Your debt has reached -$" << fabs(TheCinema->getBank()) << ",";
            if (CurrentBank < 10)
            {
                BlankSpaces(36);
            }
            else if (CurrentBank >= 10 && CurrentBank < 100)
            {
                BlankSpaces(35);
            }
            else if (CurrentBank >= 100 && CurrentBank < 1000)
            {
                BlankSpaces(34);
            }
            else if (CurrentBank >= 1000 && CurrentBank < 10000)
            {
                BlankSpaces(33);
            }
            else if (CurrentBank >= 10000 && CurrentBank < 100000)
            {
                BlankSpaces(32);
            }
            cout << "X" << endl << "X";
            BlankSpaces(15);
            cout << "which is more than the allowable -$" << DEBT_MAX << ".";
            if (DEBT_MAX < 10)
            {
                BlankSpaces(25);
            }
            else if (DEBT_MAX >= 10 && DEBT_MAX < 100)
            {
                BlankSpaces(24);
            }
            else if (DEBT_MAX >= 100 && DEBT_MAX < 1000)
            {
                BlankSpaces(23);
            }
            else if (DEBT_MAX >= 1000 && DEBT_MAX < 10000)
            {
                BlankSpaces(22);
            }
            else if (DEBT_MAX >= 10000 && DEBT_MAX < 100000)
            {
                BlankSpaces(21);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "The bank has decided you are too high a risk,";
            BlankSpaces(17);
            cout << "X" << endl << "X";
            BlankSpaces(15);
            cout << "and have foreclosed on your cinema. You've lost.";
            BlankSpaces(14);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "Try again some time.";
            BlankSpaces(42);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(5);

            Pause();
            ClearScreen();
            break;
        }
        if (TheCinema->getBank() >= PROFIT_MAX)
        {
            int CurrentBank = TheCinema->getBank();

            BorderX();
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "You've earned more than $" << TheCinema->getBank() << "!";
            if (CurrentBank < 10)
            {
                BlankSpaces(35);
            }
            else if (CurrentBank >= 10 && CurrentBank < 100)
            {
                BlankSpaces(34);
            }
            else if (CurrentBank >= 100 && CurrentBank < 1000)
            {
                BlankSpaces(33);
            }
            else if (CurrentBank >= 1000 && CurrentBank < 10000)
            {
                BlankSpaces(32);
            }
            else if (CurrentBank >= 10000 && CurrentBank < 100000)
            {
                BlankSpaces(31);
            }
            else if (CurrentBank >= 100000 && CurrentBank < 1000000)
            {
                BlankSpaces(30);
            }
            else if (CurrentBank >= 1000000 && CurrentBank < 10000000)
            {
                BlankSpaces(29);
            }
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "You have won CinemaGURU. Congratulations!";
            BlankSpaces(21);
            cout << "X" << endl;
            XBorderedBlankSpace();
            cout << "X";
            BlankSpaces(15);
            cout << "Play again some time.";
            BlankSpaces(41);
            cout << "X" << endl;
            XBorderedBlankSpace();
            XBorderedBlankSpace();
            BorderX();
            BlankLines(6);

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
                        HowManySeatsToBuy = getSelectionSeatPurchase(Decision_TheaterNum + 1,
                                                                     TheCinema->accessTheaters(Decision_TheaterNum)->getNumOfSeats());
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
                        BorderX();
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "You've chosen to purchase additional movie licenses.";
                        BlankSpaces(20);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "Below is a list of newly released movies available for purchase:";
                        BlankSpaces(8);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        int Counter = 0;
                        // Displays the items on the list.
                        for (int n = 0; n < OFFERED_LICENSES_MAX; n++)
                        {
                            if (TheCinema->accessMovieLicensesOffered(n)->getTitle() != "Not Available")
                            {
                                cout << "X";
                                BlankSpaces(10);
                                /////////
                                locale loc;
                                char c;

                                string Original = TheCinema->accessMovieLicensesOffered(n)->getTitle();

                                string String1 = "";

                                for (unsigned int i = 0, j = 0, k = 0; i < Original.length();)
                                {
                                    // i keeps track of index in original string.
                                    // j creates enough whitespace after each string to each line align with border.
                                    // k ensures there are the same number of characters in each string.
                                    c = Original[i];
                                    // Resets j for the next string once j reaches maximum string length.
                                    if (j >= 52)
                                    {
                                        j = 0;
                                        i++;
                                    }
                                    // Fills String1 with approx 46 characters from original string.
                                    // At the end of nearest word, input begins on string2.
                                    if (k < 52)
                                    {
                                        if (j >= 46 && !isspace(c,loc))
                                        {
                                            String1 += Original[i];
                                            i++;
                                            if ( i >= Original.length() )
                                            {
                                                for (; j < 51; j++)
                                                {
                                                    String1 += " ";
                                                }
                                            }
                                        }
                                        else if (j >= 46 && isspace(c,loc))
                                        {
                                            String1 += " ";
                                        }
                                        else
                                        {
                                            String1 += Original[i];
                                            i++;
                                            if ( i >= Original.length() )
                                            {
                                                for (; j < 51; j++)
                                                {
                                                    String1 += " ";
                                                }
                                            }
                                        }
                                    }
                                    j++;
                                    k++;
                                }
                                /////////
                                cout << (Counter + 1) << ". " << String1;
                                BlankSpaces(12);
                                cout << "X" << endl;
                                Counter++;
                            }
                        }
                        // If there's at least one movie offered, offer the no choice option.
                        cout << "X";
                        BlankSpaces(10);
                        cout << Counter + 1<< ". None of these";
                        BlankSpaces(51);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "Which of these do you choose? (Type a number, then ENTER)";
                        BlankSpaces(15);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        BorderX();
                        BlankLines(4);
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
                            BorderX();
                            XBorderedBlankSpace();
                            XBorderedBlankSpace();
                            TheCinema->accessMovieLicensesOffered(DesiredLicense - 1)->displayMovieDetails();
                            XBorderedBlankSpace();
                            cout << "X";
                            BlankSpaces(5);
                            cout << "Do you want to purchase the license for this movie? (Y or N)";
                            BlankSpaces(12);
                            cout << "X" << endl;
                            XBorderedBlankSpace();
                            XBorderedBlankSpace();
                            BorderX();

                            ch = getYesOrNo();
                            if (ch == 'N' || ch == 'n')
                            {
                                ClearScreen();
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
                            ClearScreen();

                            BorderX();
                            XBorderedBlankSpace();
                            XBorderedBlankSpace();
                            cout << "X";
                            BlankSpaces(24);
                            cout << "Perhaps another time then...";
                            BlankSpaces(25);
                            cout << "X" << endl;
                            XBorderedBlankSpace();
                            XBorderedBlankSpace();
                            BorderX();
                            BlankLines(8);
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
                            // Displays next level of Screen Size and cost. Asks player yes or no to purchase.
                            // Also, if maximum level has been achieved, if returns false and exits.
                            if (choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getScreenLevel(),
                                                         Screen_Size))
                            {
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
                                    ClearScreen();

                                    BorderX();
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    cout << "X";
                                    BlankSpaces(24);
                                    cout << "Perhaps another time then...";
                                    BlankSpaces(25);
                                    cout << "X" << endl;
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    BorderX();
                                    BlankLines(8);
                                    Pause();
                                }
                            }
                        }
//...................................................................................................................
                        // Player chose to upgrade projector quality.
                        else if (DecisionBuyUpgrade == '2')
                        {
                            // Displays next level of projector quality and cost. Asks player yes or no to purchase.
                            // Also, if maximum level has been achieved, if returns false and exits.
                            if (choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getProjectorLevel(),
                                                         Projector_Quality))
                            {
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
                                    ClearScreen();

                                    BorderX();
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    cout << "X";
                                    BlankSpaces(24);
                                    cout << "Perhaps another time then...";
                                    BlankSpaces(25);
                                    cout << "X" << endl;
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    BorderX();
                                    BlankLines(8);
                                    Pause();
                                }
                            }
                        }
//...................................................................................................................
                        // Player chose to upgrade sound intensity.
                        else if (DecisionBuyUpgrade == '3')
                        {
                            // Displays next level of Sound Intensity and cost. Asks player yes or no to purchase.
                            // Also, if maximum level has been achieved, if returns false and exits.
                            if (choiceUpgradeChosenEquipment(TheCinema->accessTheaters(Decision_TheaterNum)->getSoundLevel(),
                                                         Sound_Intensity))
                            {
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
                                    ClearScreen();

                                    BorderX();
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    cout << "X";
                                    BlankSpaces(24);
                                    cout << "Perhaps another time then...";
                                    BlankSpaces(25);
                                    cout << "X" << endl;
                                    XBorderedBlankSpace();
                                    XBorderedBlankSpace();
                                    BorderX();
                                    BlankLines(8);
                                    Pause();
                                }
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
                    listOfAvailableMovies(CurrentNumOfLicensesOwned);
                    // Since the number of options is variable depending how many licenses are owned at the
                    // time of call, the loop ensures the selection entered matches only the options offered.
                    do
                    {
                        // Player's selection is collected and stored.
                        MovieLicenseSelected = getSelectedLicense(CurrentNumOfLicensesOwned, Decision_TheaterNum + 1,
                                                                  TheCinema->accessTheaters(Decision_TheaterNum)->getSelectedMovie()->getTitle());
                        if (MovieLicenseSelected > CurrentNumOfLicensesOwned)
                        {
                            // The + 1 returns what the Player selected, not the index position given w/o + 1.
                            cout << "ERROR: " << (MovieLicenseSelected + 1);
                            cout << " is not a valid selection. Try again: ";
                        }
                    } while (MovieLicenseSelected > CurrentNumOfLicensesOwned);

                    ClearScreen();
                    // Distinguishes between an actual title selected or the option to Play Nothing.
                    if (MovieLicenseSelected != CurrentNumOfLicensesOwned)
                    {
                        // Display Title, Synopsis, Popularity, etc of the Movie that Player selected.
                        BorderX();
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        TheCinema->accessMovieLicense(MovieLicenseSelected)->displayMovieDetails();
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "Would you like to play this movie in your theater? (Y or N)";
                        BlankSpaces(13);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        BorderX();

                        ch = getYesOrNo();
                    }
                    else if (MovieLicenseSelected == CurrentNumOfLicensesOwned)
                    {
                        BorderX();
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "When there's no movie playing in a theater,";
                        BlankSpaces(29);
                        cout << "X" << endl << "X";
                        BlankSpaces(5);
                        cout << "it won't sell any tickets.";
                        BlankSpaces(46);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        cout << "X";
                        BlankSpaces(5);
                        cout << "Are you sure you want to play no movie in this theater? (Y or N)";
                        BlankSpaces(8);
                        cout << "X" << endl;
                        XBorderedBlankSpace();
                        XBorderedBlankSpace();
                        BorderX();
                        BlankLines(7);

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

                ClearScreen();

                BorderX();
                XBorderedBlankSpace();
                XBorderedBlankSpace();
                cout << "X";
                BlankSpaces(15);
                cout << "You've selected to play ";
                if (Title != "No Movie Playing")
                {
                    locale loc;
                    char c;

                    string Original;
                    string String1;

                    Original = Title;

                    for (unsigned int i = 0, j = 0, k = 0; i < Original.length();)
                    {
                        // i keeps track of index in original string.
                        // j creates enough whitespace after each string to each line align with border.
                        // k ensures there are the same number of characters in each string.
                        c = Original[i];
                        // Resets j for the next string once j reaches maximum string length.
                        if (j >= 57)
                        {
                            j = 0;
                            i++;
                        }
                        // Fills String1 with approx 28 characters from original string.
                        // At the end of nearest word, input begins on string2.
                        if (k < 57)
                        {
                            if (j >= 34 && !isspace(c,loc))
                            {
                                String1 += Original[i];
                                i++;
                                if ( i >= Original.length() )
                                {
                                    for (; j < 37; j++)
                                    {
                                        String1 += " ";
                                    }
                                }
                            }
                            else if (j >= 34 && isspace(c,loc))
                            {
                                String1 += " ";
                            }
                            else
                            {
                                String1 += Original[i];
                                i++;
                                if ( i >= Original.length() )
                                {
                                    for (; j < 37; j++)
                                    {
                                        String1 += " ";
                                    }
                                }
                            }
                        }
                        j++;
                        k++;
                    }
                    cout << String1;
                    cout << "X" << endl << "X";
                    BlankSpaces(15);
                    cout << "in Theater #" << (Decision_TheaterNum + 1);
                    if ((Decision_TheaterNum + 1) < 10)
                    {
                        BlankSpaces(49);
                    }
                    else if ((Decision_TheaterNum + 1) >= 10 && (Decision_TheaterNum + 1) < 100)
                    {
                        BlankSpaces(48);
                    }
                    else if ((Decision_TheaterNum + 1) >= 100 && (Decision_TheaterNum + 1) < 1000)
                    {
                        BlankSpaces(47);
                    }
                    cout << "X" << endl;
                    XBorderedBlankSpace();
                    XBorderedBlankSpace();
                    BorderX();
                    BlankLines(8);
                }
                else
                {
                    cout << "nothing";
                    BlankSpaces(31);
                    cout << "X" << endl << "X";
                    BlankSpaces(15);
                    cout << "in Theater #" << (Decision_TheaterNum + 1);
                    if ((Decision_TheaterNum + 1) < 10)
                    {
                        BlankSpaces(49);
                    }
                    else if ((Decision_TheaterNum + 1) >= 10 && (Decision_TheaterNum + 1) < 100)
                    {
                        BlankSpaces(48);
                    }
                    else if ((Decision_TheaterNum + 1) >= 100 && (Decision_TheaterNum + 1) < 1000)
                    {
                        BlankSpaces(47);
                    }
                    cout << "X" << endl;
                    XBorderedBlankSpace();
                    XBorderedBlankSpace();
                    BorderX();
                    BlankLines(8);
                }

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
