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

void XBorderedDivider()
{
    cout << "X";
    for (int i = 0; i < 77; i++)
    {
        cout << "-";
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
    cout << "Press any key to continue. ";

    char c = 0;
    do
    {
        c = getch();
    } while (c == 0);
}

void BlankLines(int NumOfLines)
{
    for (int i = 0; i < NumOfLines; i++)
    {
        cout << endl;
    }
}

void BlankSpaces(int NumOfSpaces)
{
    for (int i = 0; i < NumOfSpaces; i++)
    {
        cout << " ";
    }
}

void introduction()
{
    BlankLines(10);
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "Welcome to CinemaGURU. You are the proud new owner of a cinema!";
    BlankSpaces(9);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "At the moment, you have only one theater with " << SEATS_MIN << " seats.";
    if (SEATS_MIN < 10)
    {
        BlankSpaces(18);
        cout << "X" << endl;
    }
    else if (SEATS_MIN >= 10 && SEATS_MIN < 100)
    {
        BlankSpaces(17);
        cout << "X" << endl;
    }
    else if (SEATS_MIN >= 100 && SEATS_MIN < 1000)
    {
        BlankSpaces(16);
        cout << "X" << endl;
    }
    else
    {
        BlankSpaces(15);
        cout << "              X" << endl;
    }

    cout << "X";
    BlankSpaces(5);
    cout << "You've been licensed a free movie to start you off.";
    BlankSpaces(21);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(7);
    Pause();
}

void runInstructions()
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(5);
    cout << "The goal of CinemaGURU is to take control of and run a cinema.";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "Grow your business by building additional theaters, purchasing";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "more seats, acquiring more snack types, upgrading the movie";
    BlankSpaces(13);
    cout << "X" << endl << "X";
    BlankSpaces(5);
    cout << "watching experience, and license new movies as they become available.";
    BlankSpaces(3);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "The various components of your cinema that you can interact with are:";
    BlankSpaces(5);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedDivider();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Theaters***";
    BlankSpaces(60);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "A theater is a room with a projector, a screen, a sound system, and a";
    BlankSpaces(5);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "number of chairs. They cost a one-time sum to purchase, and a once-a-";
    BlankSpaces(5);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "turn expense in the form of mortgage/rent. Each theater can accommodate";
    BlankSpaces(3);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "a finite number of seats. More theaters equals more potential seats.";
    BlankSpaces(6);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedDivider();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Seats***";
    BlankSpaces(63);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "A seat equals the potential for one purchased ticket. While other";
    BlankSpaces(9);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "factors improve or diminish the probability of a ticket purchase,";
    BlankSpaces(9);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "the total number of seats determines the total number of tickets a";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "player can sell per turn.";
    BlankSpaces(49);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    cout << endl;

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Snacks***";
    BlankSpaces(62);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "A cinema lobby can provide a certain number of snack types for";
    BlankSpaces(12);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "purchase. For a one-time payment, a player can increase their";
    BlankSpaces(13);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "offered snack types by one. The number of tickets sold in a turn";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "is then used to calculate how many snacks can be sold. The larger";
    BlankSpaces(9);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "variety of snacks, however, increases that number.";
    BlankSpaces(24);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedDivider();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Upgrades***";
    BlankSpaces(60);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "In each theater, there is a projector, a sound system, and a screen.";
    BlankSpaces(6);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "For a one-time payment per upgrade, a player can gradually increase";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "the performance of one of these in a given theater. The quality of";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "these systems directly impacts (improves with each upgrade) how many";
    BlankSpaces(6);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "of that theater's seats sells tickets.";
    BlankSpaces(36);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    cout << endl << endl;

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Employees***";
    BlankSpaces(59);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "Employees play a crucial part in how many seats sell tickets. As each";
    BlankSpaces(5);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "theater owned can be staffed by a total of five employees, the";
    BlankSpaces(12);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "proportion of employees to theaters affects the cinema's efficiency";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "and performance.";
    BlankSpaces(58);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "However, each employee working for you creates an expense each turn.";
    BlankSpaces(6);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "The player must balance how many employees their budget can manage";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "without under-staffing the cinema and decreasing ticket sales.";
    BlankSpaces(12);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(3);

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Movie Licenses***";
    BlankSpaces(54);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "Movies are diverse in and of themselves. Each has a finite";
    BlankSpaces(16);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "number of turns before they expire. Each has a one-time cost";
    BlankSpaces(14);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "to purchase.";
    BlankSpaces(62);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "Each has their own good season, and bad season. Playing a movie";
    BlankSpaces(11);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "in a given theater during a bad season, decreases ticket sales.";
    BlankSpaces(11);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "Inversely, during a good season it can increase ticket sales.";
    BlankSpaces(13);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "In the remaining two seasons, the factor has no effect.";
    BlankSpaces(19);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "Movies also have an estimated, and an actual, popularity associated";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "with them. Those with a higher expected popularity cost more, and have";
    BlankSpaces(4);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "shorter license durations. In some cases, the actual popularity can be";
    BlankSpaces(4);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "higher or lower than the expected (this is rare, and helps add a flare";
    BlankSpaces(4);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "of unpredictability for the player, simulating a fickle consumer base).";
    BlankSpaces(3);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    BlankLines(3);

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Turns/Weeks/Years/Seasons***";
    BlankSpaces(43);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "The game is turned-based. Each turn completed passes a week of time.";
    BlankSpaces(6);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "Each year is comprised of four seasons (Winter, Spring, Summer, and";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "Autumn) that affect a movie's playability. The season changes every";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "13 weeks, or 13 turns.";
    BlankSpaces(52);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedDivider();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***Random Events***";
    BlankSpaces(55);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "At the end of every turn, there is a chance that a random event will";
    BlankSpaces(6);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "occur. This random event can either be positive (each response";
    BlankSpaces(12);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "increases revenue) or negative (each response decreases revenue)";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "and presents a scenario with four possible choices for the player.";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "After the player chooses, the reaction to that choice is displayed";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "and the amount of money to be gained or lost is shown.";
    BlankSpaces(20);
    cout << "X" << endl;
    XBorderedBlankSpace();
    BorderX();
    BlankLines(2);

    Pause();
    ClearScreen();

    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "***The End***";
    BlankSpaces(61);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "There are three possible ways to end the game. The player can quit,";
    BlankSpaces(7);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "win, or lose by reaching a certain amount of debt (Warnings are";
    BlankSpaces(11);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "displayed to show debt threshold).";
    BlankSpaces(40);
    cout << "X" << endl;
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(3);
    cout << "There are a finite number of theaters, seats, upgrades, movie";
    BlankSpaces(13);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "licenses, and employees a player can attain, however, and";
    BlankSpaces(17);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "anything beyond this point would result in pure profit without";
    BlankSpaces(12);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "end. As a result, there is a cap on the bank that, when reached,";
    BlankSpaces(10);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "the player is declared a winner. A hard ending was not chosen";
    BlankSpaces(13);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "in this version of the game. Future (more graphics-based) versions";
    BlankSpaces(8);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "may incorporate a deeper story line, and more challenging obstacles,";
    BlankSpaces(6);
    cout << "X" << endl << "X";
    BlankSpaces(3);
    cout << "as the visuals accompanying them could better enrich the experience.";
    BlankSpaces(6);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(3);

    Pause();
    ClearScreen();
}

void goodByeMessage()
{
    BorderX();
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    cout << "X";
    BlankSpaces(25);
    cout << "See you later, alligator!";
    BlankSpaces(27);
    cout << "X" << endl;
    XBorderedBlankSpace();
    XBorderedBlankSpace();
    BorderX();
    BlankLines(5);
}
