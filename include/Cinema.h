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
    std::string StaffPerformance;
    std::string PromotionInUse;

    float Bank;
    float TPrice;
    float Expenses;
    float TicketSales;
    float SnackSales;

    int NumOfTheaters;
    int NumOfEmployees;
    int EmployeesMax;
    int NumOfSnacks;
    int NumOfMovieLicenses;
    int PromotionSelected;
    int TotalNumOfSeats;

    int DisplayedMovieLicenses[OFFERED_LICENSES_MAX] = {0};

    Theater* p_Theaters[THEATERS_MAX];
    Movie* p_Movies[MOVIES_MAX];
    Movie* p_MovieLicenses[MOVIES_MAX];
    Movie* p_MovieLicensesOffered[3];

public:
    Cinema();
    ~Cinema();

    Calendar* p_Calendar;

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
    void hud();

    void addTheater();
    void changePromotionSelected(int);
    void changeTicketPrice(float);
    void adjustBank(int);
    void adjustExpenses(int, int);
    void adjustTicketSales(int);
    void adjustSnackSales(float);
    void addSnacks();
    void addNumOfMovieLicenses();
    void subtractNumOfMovieLicenses();
    void changeNumOfEmployees(int);
    void changeDisplayedMovieLicense(int, int);
    void setStaffPerformance(std::string);
    void setPromotionInUse(std::string);

    bool checkPreviousLicenseMatch(int);

    Theater* accessTheaters(int);
    Movie* getMovie(int);
    Movie* accessMovieLicense(int);
    void addMovieLicense(Movie*, int);
    Movie* accessMovieLicensesOffered(int);
};

#endif // CINEMA_H
