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

void runInstructions()
{
    cout << "The goal of CinemaGURU is to take control of and run a cinema." << endl << endl;
    cout << "Grow your business by building additional theaters, purchasing more seats," << endl;
    cout << "acquiring more snack types, upgrading the movie watching experience," << endl;
    cout << "and license new movies as they become available." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Theaters = a theater is a room with a projector, a screen," << endl;
    cout << "a sound system, and a number of chairs. They cost a one time sum to purchase" << endl;
    cout << "and a once-a-turn expense in the form of mortgage/rent." << endl << endl;
    cout << "Each theater can accommodate a finite number of seats." << endl;
    cout << "More theaters equals more potential seats." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Seats = a seat equals the potential for one purchased ticket." << endl;
    cout << "While other factors improve or diminish the probability of a ticket purchase," << endl;
    cout << "the total number seats determines the total number of tickets a player can sell per turn." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Snacks = a cinema lobby can provide a certain number of snack type for purchase." << endl;
    cout << "For a one time payment, a player can increase their offered snack types by one." << endl;
    cout << "The number of tickets sold in a turn is used to calculate how many snack can be sold." << endl;
    cout << "The larger variety of snack, however, increases that number." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Upgrades = In each theater, there is a projector, a sound system, and a screen." << endl;
    cout << "For a one time payment per upgrade, a player can gradually increase the performance" << endl;
    cout << "of one of these in a given theater. The quality of these systems directly impacts" << endl;
    cout << "(improves with each upgrade) how many of that theater's seats sold tickets." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Employees = employees play a crucial part in how many seats sell tickets." << endl;
    cout << "As each theater owned can be staffed by a total of five employees," << endl;
    cout << "the proportion of employees to theaters affects the cinema's efficiency and performance." << endl;
    cout << "However, each employee incurs an expense each turn." << endl;
    cout << "The player must balance how many employees their budget can manage" << endl;
    cout << "without under-staffing the cinema and decreasing ticket sales." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Movie License = movies are diverse in and of themselves." << endl;
    cout << "Each has a finite number of turns before they expire." << endl;
    cout << "Each has a one time cost to purchase. Each has their own good season, and bad season." << endl;
    cout << "Playing a movie in a given theater during a bad season, decreases ticket sales." << endl;
    cout << "Inversely, during a good season it can increase ticket sales." << endl;
    cout << "In the remaining two season the factor has no effect on sales." << endl;
    cout << "Movies also have an estimated and an actual popularity associated with them." << endl;
    cout << "Those with a higher expected popularity cost more, and have shorter license durations." << endl;
    cout << "In some cases, the actual popularity can be higher or lower than the expected" << endl;
    cout << "(this is rare, and helps add a flare of unpredictability for the player," << endl;
    cout << "simulating a fickle consumer base). Available movies and their details" << endl;
    cout << "are on a text file. This allows the player the ability to create their own" << endl;
    cout << "movie titles, synopsis, etc. -- Added flavor." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Turns/Weeks/Years/Seasons = the game is turned-based." << endl;
    cout << "Each turn used passes a week of time. Each year is comprised of" << endl;
    cout << "four seasons (Winter, Spring, Summer, and Fall) that affect a movie's playability." << endl;
    cout << "The season changes every 13 weeks, or 13 turns." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Random Events = To avoid letting the game feel repetitive from one turn to the next," << endl;
    cout << "there is a random chance of 33.33% that a random event will occur at the end of every turn." << endl;
    cout << "This random event can either be positive (each response increases revenue) or" << endl;
    cout << "negative (each response decreases revenue) and presents a scenario with four" << endl;
    cout << "possible choices for the player. After the player chooses," << endl;
    cout << "the reaction to that choice is displayed and the amount of money" << endl;
    cout << "to be gained or lost is shown. These events are also stored on a text file" << endl;
    cout << "to allow the player the option of customizing their experience." << endl << endl;
    Divider();
    Pause();
    ClearScreen();

    cout << "Technically, there is no end to the game until the player either" << endl;
    cout << "goes into a certain amount of debt, or chooses to quit." << endl;
    cout << "There are a finite number of theaters, seats, upgrades, movie licenses," << endl;
    cout << "and employees a player can attain, however, and anything beyond this point" << endl;
    cout << "would result in pure profit without end." << endl << endl;
    cout << "A hard ending was not chosen in this version of the game." << endl;
    cout << "Future (more graphics-based) versions may incorporate a deeper story line," << endl;
    cout << "and more challenging obstacles, as the visuals accompanying them" << endl;
    cout << "could better enrich the experience." << endl << endl;
    Divider();
    Pause();
    ClearScreen();
}
