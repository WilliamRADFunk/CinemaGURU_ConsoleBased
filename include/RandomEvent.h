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
    char Rating = 'A';

    float MonetaryBase = 0.0;

    int FactorChoiceA = 0,FactorChoiceB = 0, FactorChoiceC = 0, FactorChoiceD = 0;

    std::string Scenario = "Not Available";
    std::string OptionA = "Not Available", OptionB = "Not Available", OptionC = "Not Available", OptionD = "Not Available";
    std::string DescriptionResultA = "Not Available", DescriptionResultB = "Not Available";
    std::string DescriptionResultC = "Not Available", DescriptionResultD = "Not Available";

public:
    RandomEvent();
    ~RandomEvent();

    char getRating();
    float getMonetaryBase();
    int getFactorChoiceA();
    int getFactorChoiceB();
    int getFactorChoiceC();
    int getFactorChoiceD();
    void printScenario();
    void printOptionA();
    void printOptionB();
    void printOptionC();
    void printOptionD();
    void printDescriptionResultA();
    void printDescriptionResultB();
    void printDescriptionResultC();
    void printDescriptionResultD();

    void presentEvent();
    float presentOutcome(char);

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
