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

#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>

#include "Global.h"


class RandomEvent
{
private:
    // Initializing variable to an inert value.
    char Rating = 'A';

    float MonetaryBase = 0.0;
    // These are the multipliers for each of the four choices the player can choose from.
    int FactorChoiceA = 0,FactorChoiceB = 0, FactorChoiceC = 0, FactorChoiceD = 0;
    // The explanation of the event for the player.
    std::string Scenario = "Not Available";
    // These are the four possible actions the player can take for each event.
    std::string OptionA = "Not Available", OptionB = "Not Available";
    std::string OptionC = "Not Available", OptionD = "Not Available";
    // These are the four possible outcome descriptions respective to the player's chosen action.
    std::string DescriptionResultA = "Not Available", DescriptionResultB = "Not Available";
    std::string DescriptionResultC = "Not Available", DescriptionResultD = "Not Available";

public:
    RandomEvent();
    ~RandomEvent();

    // This cluster of functions do exactly what their names imply.
    char getRating();
    float getMonetaryBase();
    int getFactorChoiceA();
    int getFactorChoiceB();
    int getFactorChoiceC();
    int getFactorChoiceD();
    // This cluster of functions do what their names imply with additional formatting for display.
    void printScenario();
    void printOptionA();
    void printOptionB();
    void printOptionC();
    void printOptionD();
    void printDescriptionResultA();
    void printDescriptionResultB();
    void printDescriptionResultC();
    void printDescriptionResultD();
    // Runs the previous functions in specific order (printScenario(), printOptionA(), printOptionB(),
    // printOptionC(), printOptionD(), presentEvent()).
    void presentEvent();
    // Determines which outcome relates to player's choice and displays it in formatted form.
    float presentOutcome(char);
    // This cluster of functions do exactly what their names imply.
    void setRating(char);
    void setMonetaryBase(float);
    void setFactorChoiceA(int);
    void setFactorChoiceB(int);
    void setFactorChoiceC(int);
    void setFactorChoiceD(int);
    void setScenario(std::string);
    void setOptionA(std::string);
    void setOptionB(std::string);
    void setOptionC(std::string);
    void setOptionD(std::string);
    void setDescriptionResultA(std::string);
    void setDescriptionResultB(std::string);
    void setDescriptionResultC(std::string);
    void setDescriptionResultD(std::string);
};

#endif // RANDOMEVENT_H
