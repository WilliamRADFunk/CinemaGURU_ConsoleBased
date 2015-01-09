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

#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>

#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "Global.h"

class Cinema
{
private:
    // Depends on ratio of employees employed to total possible to employ.
    // The (int) result directly affects the number of tickets sold each turn.
    // This is the string value for display purposes.
    std::string StaffPerformance;
    // String value for the promotion that the player has chosen--for display purposes.
    std::string PromotionInUse;

    // Total money player has to spend. Profits and losses are added and deducted from here.
    float Bank;
    // The cost of a ticket. Higher sells less tickets. Lower sells more.
    float TPrice;
    // Totals all expenses a player incurs at the end of a turn.
    float Expenses;
    // Keeps track of profits (last turn) from ticket sales--for display purposes.
    float TicketSales;
    // Keeps track of profits (last turn) from snack sales--for display purposes.
    float SnackSales;
    // Total number of theaters the player owns.
    int NumOfTheaters;
    // Total number of employees the player has employed at his cinema.
    int NumOfEmployees;
    // (Based on NumOfTheaters) The total number of employees a player can have.
    int EmployeesMax;
    // Total number of snack types player has purchased.
    int NumOfSnacks;
    // Total number of movie licenses the player has at that moment.
    int NumOfMovieLicenses;
    // The value of promotion chosen that is used as factor in ticket sales.
    int PromotionSelected;
    // Total number of seats from all owned theaters--for display purposes.
    int TotalNumOfSeats;
    // Array of indexes (available for purchase) corresponding to movies in the p_Movies[].
    int DisplayedMovieLicenses[OFFERED_LICENSES_MAX] = {0};
    // An array to keep track of theaters owned by player.
    Theater* p_Theaters[THEATERS_MAX];
    // An array of pointers to all movies that exist in player's universe.
    Movie* p_Movies[MOVIES_MAX];
    // An array of pointers to movie licenses owned by player.
    Movie* p_MovieLicenses[MOVIES_MAX];
    // An array of pointers to the movie objects available for player to purchase at that moment.
    Movie* p_MovieLicensesOffered[OFFERED_LICENSES_MAX];

public:
    Cinema();
    ~Cinema();

    // Pointer to calendar object contained here to display week, year, and season in Cinema::hud().
    Calendar* p_Calendar;

    // All get functions here are named appropriately for the variable's value that they return.
    float getBank();
    float getExpenses();
    float getTicketSales();
    float getSnackSales();
    float getTicketPrice();
    int getNumOfTheaters();
    int getTotalNumOfSeats();
    int getNumOfMovieLicenses();
    int getNumOfEmployees();
    int getNumOfSnacks();
    int getPromotionSelected();
    int getDisplayedMovieLicenses(int);
    std::string getStaffPerformance();
    std::string getPromotionInUse();
    // This is the main display, where at the beginning of each
    // turn the player can see most of his cinema's details.
    void hud();
    // When a theater is purchased by player, this function is
    // called to increase the "NumOfTheaters" variable.
    void addTheater();
    void changePromotionSelected(int);
    void changeTicketPrice(float);
    // Capable of handling positive and negative numbers, to account for either gains or losses.
    void adjustBank(int);
    // Takes "NumOfTheaters", "NumOfEmployees", and "PromotionSelected",
    // applying their cost multiplier, and produces a single expense total.
    // This number is then subtracted from the player's bank.
    void adjustExpenses(int, int);
    // Takes total tickets sold and multiplies by ticket price.
    // This number is then added to the player's bank.
    void adjustTicketSales(int);
    // Takes total snacks sold and formats the number.
    // This number is then added to the player's bank.
    void adjustSnackSales(float);
    // Increases "NumOfSnacks" by one.
    void addSnacks();
    // Increases "NumOfMovieLicenses" by one.
    void addNumOfMovieLicenses();
    // Decreases "NumOfMovieLicenses" by one.
    void subtractNumOfMovieLicenses();
    // Used for both firing and hiring. Total "NumOfEmployees"
    // is increased or decreased by the number inputed by player.
    void changeNumOfEmployees(int);
    // Takes movie randomly picked and places it in open spot on list of offered movie licenses.
    void changeDisplayedMovieLicense(int, int);
    void setStaffPerformance(std::string);
    void setPromotionInUse(std::string);
    // Ensures the randomly selected movie to display for
    // purchase is not already on display for purchase.
    // Also makes sure player does not already own that license.
    bool checkPreviousLicenseMatch(int);
    // Returns a theater object from the array of theaters owned by player.
    Theater* accessTheaters(int);
    // Returns pointer to a movie object from array of pointers to
    // total movies available in player's universe.
    Movie* getMovie(int);
    // Returns pointer to a movie object from array of pointers to licenses owned by player.
    Movie* accessMovieLicense(int);
    // Adds pointer to a movie object to array of pointers to licenses owned by player.
    void addMovieLicense(Movie*, int);
    // Returns pointer to a movie object from array of pointers
    // to licenses available for purchase by player.
    Movie* accessMovieLicensesOffered(int);
};

#endif // CINEMA_H
