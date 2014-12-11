#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <sstream>

#include "Global.h"

using namespace std;

// Creates a long series of hyphens, making a divider to better read the console screen.
void Divider()
{
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void XBorderedBlankSpace()
{
    cout << "X";
    for (int i = 0; i < 77; i++)
    {
        cout << " ";
    }
    cout << "X" << endl;
}

void BorderX()
{
    for (int i = 0; i < 79; i++)
    {
        cout << "X";
    }
    cout << endl;
}

void ClearScreen()
{
    for (int i = 0; i <= 100; i++)
    {
        cout << endl;
    }
}

void Pause()
{
    cout << "Press any key to continue." << endl;

    char c = 0;
    do
    {
        c = getch();
    } while (c == 0);
}

void introduction()
{
    cout << "Welcome to CinemaGURU. You are the proud new owner of a cinema!" << endl << endl;
    cout << "At the moment, you have only one theater with 10 seats." << endl;
    cout << "You've been licensed a free movie to start you off." << endl << endl;
    cout << "There are a number of factors that lead to success:" << endl;
    cout << "More seats equals more possible tickets;" << endl;
    cout << "upgrading screen size, projector quality, and" << endl;
    cout << "sound system will improve the movie experience;" << endl;
    cout << "Playing certain movies during their optimal season, and" << endl;
    cout << "buying promotions improve ticket sales." << endl;
    cout << "Don't forget that the more snacks you offer means more potential revenue, too." << endl;
    Divider();
    Pause();
}
