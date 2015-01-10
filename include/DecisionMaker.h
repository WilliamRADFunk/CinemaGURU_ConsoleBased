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

#ifndef DECISIONMAKER_H_INCLUDED
#define DECISIONMAKER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "RandomEvent.h"
#include "RandomEventHandler.h"
#include "Global.h"

class DecisionMaker
{
private:
    // Creates and contains a pointer to manipulate the player's cinema and everything it contains.
    Cinema* TheCinema;
    // Creates an instance of the class that facilitates the Random Events, and the player's response to them.
    RandomEventHandler* TheREHandler;
    // String form of the six available snack types.
    const std::string Snacks[6] =            {"Popcorn", "SodaPop", "HotDogs", "Coffees", "Pretzel", "Candies"};
    // String form of the five states of cinema efficiency based on number of employees--for display purposes.
    const std::string StaffPerformance[5] =  {"Dismal", "Shoddy", "Decent", "B+Work", "Superb"};
    // String form of the six promotions offered to the player.
    const std::string Promotions[6] =        {"No Promotion", "1/2 $ Monday", "Bonus Snacks",
                                              "Issue Fliers", "Coupon Books", "A Commercial"};
    // Variables to keep track of player's choices through the various switch statements.
    char Decision, DecisionBuy, DecisionBuyUpgrade, DecisionStaff,
         DecisionBuyMovieLicense, DecisionMovieSelection, DecisionRandomEvent;
    // Player choices in switch statements requiring int values,
    // Quantities of purchase, and intermediary variables.
    int Decision_TheaterNum, HowManySeatsToBuy, ChangeStaff,
        MovieLicenseSelected, NewLicenseOffered, NumTicketsPurchased,
        TheatersWithoutMoviesPlaying, RandomEventIndex;
    // Final factor multiplied against total seats to determine ticket sales each turn.
    float RandomAttendanceQuotient;

public:
    DecisionMaker(Cinema*);
    ~DecisionMaker();

    // Displays main choices: buy, staff, ticket price, movie, end turn, and quit.
    void choiceTree_Main();
    // Displays Make Purchase choices: Buy Seats, Buy Movie License, Buy Snacks, Buy Upgrades,
    // Buy Promotions, Buy Additional Theater, and Go Back.
    void choiceTree_01();
    // Displays the question of which theater to purchase more seats for.
    void choiceTree_01_01(int);
    // Displays the movie licenses available for player to purchase.
    void choiceTree_01_02();
    // Displays message is player chooses to purchase no movie licenses.
    bool choiceResult_01_02 (int);
    // Displays details about snacks, explains price to upgrade, and asks if upgrade is desired.
    void choiceTree_01_03(int);
    // Displays the question of which theater to purchase more seats for.
    void choiceTree_01_04(int);
    // Displays details about promotions, and asks if a promotion is desired.
    void choiceTree_01_05(int);
    // Displays details about purchasing another theater, and asks if yes/no.
    void choiceTree_01_06(int);
    // Displays Manage Staff choices: Hire more people, or Fire them.
    void choiceTree_02();
    // Player chose to Change the Ticket Price. Loop breaks when 'R' or Go Back is selected.
    void choiceTree_03(float);
    // Displays the question of which theater to change the movie for.
    void choiceTree_04(int);
    // Displays theater chosen and the amount of seats present.
    // Explains price of each seat and asks player how many to buy.
    void choiceNumOfSeats(int, int);
    // Displays theater chosen and the levels for the sound system, screen size,
    // and projector quality. Asks which area to upgrade.
    void choiceUpgradeLevels(int, float, float, float);
    // Displays next level of Screen Size and cost. Asks player yes or no to purchase.
    // Also, if maximum level has been achieved, it returns false and exits.
    bool choiceUpgradeChosenEquipment(float, Equipment);
    // Uses number of employees, and number of possible employees to
    // determine what performance level for display purposes.
    std::string calculateStaffLevel(int, int);
    // Converts player's integer selection into string form for display purposes.
    std::string calculatePromotionLevel(int);
    // Informs player of current employment number, possible employment number,
    // cost of each employee, current total, and then asks how many more employees to hire.
    void choiceHireStaff(int, int);
    // Informs player of current employment number, minimum employment number,
    // cost of each employee, current total, and then asks how many employees to fire.
    void choiceFireStaff(int, int);
    // Determines if a movie is playing in a chosen theater, and displays title.
    // It then sets up what movies are available to play for function: listOfAvailableMovies(int).
    void currentMovie(int, std::string);
    // Displays list of owned movies the player can play in the chosen theater.
    void listOfAvailableMovies(int);
    // Collects only a yes or no response from the player.
    char getYesOrNo();
    // Collects yes or no confirmation for either quit option, or the game help/information option.
    char getConfirmation(char);
    // Collects player's input for options given in choiceTree_Main.
    char getSelectionMain();
    // Collects player's input for options given in choiceTree_01.
    char getSelection_01();
    // Collects player's input for options given in choiceTree_01_02.
    int getSelection_01_02();
    // Collects player's input for options given in choiceTree_01_05.
    char getSelection_01_05(int);
    // Collects player's input for options given in choiceTree_01_06.
    bool getSelection_01_06(int, int);
    // Collects player's input for options given in choiceTree_02.
    char getSelection_02();
    // Collects player's input for options given in choiceTree_04.
    int getSelection_TheaterNum(int);
    // Collects player's input for options given in choiceNumOfSeats.
    int getSelectionSeatPurchase(int, int);
    // Collects player's input for options given in choiceUpgradeLevels.
    char getSelectionUpgradePurchase();
    // Collects player's input for options given in choiceHireStaff.
    int getNumOfEmployeesToHire(int, int);
    // Collects player's input for options given in choiceFireStaff.
    int getNumOfEmployeesToFire(int, int);
    // Collects player's input for options given in choiceTree_03.
    float getNewTicketPrice();
    // Collects player's input for options given in listOfAvailableMovies.
    int getSelectedLicense(int, int, std::string);
    // Collects player's input for options given in presentEvent (In RandomEvent).
    char getRandomEventChoice();
    // Calculates factor for ticket sales based on employees employed and maximum possible.
    float getStaffFactor(int, int);
    // Calculates factor for ticket sales based on chosen price in relation to minimum and maximum.
    float getTPriceFactor(float);
    // Calculates factor for ticket sales based on based on movie's worst,
    // and best, season compare to current season.
    float getSeasonFactor(Season, Season, Season);
    // Calculates factor for ticket sales based on which promotion player has chosen.
    float getPromoFactor(int);
    // Determines if seat number chosen for purchase does not exceed max number per theater,
    // and that player has the necessary amount in the bank.
    bool checksPurchaseOfSeats(int, int, int);
    // Determines if movie license chosen for purchase does not cost more than player has in Bank.
    bool checkPurchaseOfMovieLicense(int, int);
    // Determines if cost of snack option purchase exceeds player's Bank.
    bool checkPurchaseOfSnacks(int, int);
    // Determines if cost of upgrade purchase exceeds player's Bank.
    bool checkPurchaseOfUpgrade(int, float, Equipment);
    // Contains main switch statement, and main functionality for
    // offering and collecting player's choices.
    void activateDecisionTree();
};

#endif // DECISIONMAKER_H_INCLUDED
