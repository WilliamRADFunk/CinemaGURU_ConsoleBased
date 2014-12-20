#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "DecisionMaker.h"
#include "RandomEvent.h"
#include "Global.h"

using namespace std;

int main()
{
    // Seed the random variable.
    srand(time(NULL));

    // Creation of main game entity.
    Cinema* TheCinema = new Cinema();

    // Creation of the DecisionMaker.
    DecisionMaker* TheDecisionMaker = new DecisionMaker(TheCinema);

    // Introduces player to the game.
    introduction();
    ClearScreen();

    TheDecisionMaker->activateDecisionTree();

    // Destroy all objects and direct there pointers to null.
    TheDecisionMaker->~DecisionMaker();
    TheDecisionMaker = 0;
    TheCinema->p_Calendar->~Calendar();
    TheCinema->p_Calendar = 0;
    TheCinema->~Cinema();
    TheCinema = 0;

    cout << "See you later, alligator!" << endl << endl << endl;

    return 0;
}
