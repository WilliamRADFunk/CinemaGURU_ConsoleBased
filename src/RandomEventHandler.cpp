#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "RandomEventHandler.h"
#include "RandomEvent.h"
#include "Global.h"

using namespace std;

RandomEventHandler::RandomEventHandler()
{
    for (int i = 0; i < RANDOM_EVENTS_MAX; i++)
    {
        p_RandomEvents[i] = new RandomEvent();
    }

    // Takes info about all random events from file,
    // and creates all the random events,
    // placing them in the random events array.
    ifstream infile;
    infile.open ("RandomEventData.txt");
        for (int i = 0; i < RANDOM_EVENTS_MAX; i++)
        {
            string STRING;
            int INTEGER, FLOAT;

            if (infile.eof())
            {
                break;
            }

            for (int j = 0; j < 15; j++)
            {
                // Leaves for-loop if end-of-file is reached.
                if (infile.eof())
                {
                    break;
                }
                //Each random event has 15 lines of ordered info. The following assigns each piece of data to it's correct variable.
                if (j == 0)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setRating(STRING[0]);
                }
                else if (j == 1)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER to FLOAT.
                    if ( !(convert >> FLOAT) )
                    FLOAT = 0.0;
                    p_RandomEvents[i]->setMonetaryBase((float)FLOAT);
                }
                else if (j == 2)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_RandomEvents[i]->setFactorChoiceA(INTEGER);
                }
                else if (j == 3)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_RandomEvents[i]->setFactorChoiceB(INTEGER);
                }
                else if (j == 4)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_RandomEvents[i]->setFactorChoiceC(INTEGER);
                }
                else if (j == 5)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    istringstream convert(STRING);
                    // Converts STRING to INTEGER.
                    if ( !(convert >> INTEGER) )
                    INTEGER = 0;
                    p_RandomEvents[i]->setFactorChoiceD(INTEGER);
                }
                else if (j == 6)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setScenario(STRING);
                }
                else if (j == 7)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setOptionA(STRING);
                }
                else if (j == 8)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setOptionB(STRING);
                }
                else if (j == 9)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setOptionC(STRING);
                }
                else if (j == 10)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setOptionD(STRING);
                }
                else if (j == 11)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setDescriptionResultA(STRING);
                }
                else if (j == 12)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setDescriptionResultB(STRING);
                }
                else if (j == 13)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setDescriptionResultC(STRING);
                }
                else if (j == 14)
                {
                    getline(infile,STRING); // Saves the line in STRING.
                    cout << STRING << endl; // Prints our STRING.
                    p_RandomEvents[i]->setDescriptionResultD(STRING);
                }
                else cout << "ERROR: reading data from file and conversion failure." << endl;
            }
        }
    infile.close();
    Pause();
    ClearScreen();
}

RandomEventHandler::~RandomEventHandler()
{
    cout << "Destroying RandomEventHandler" << endl;
    cout << "deleting p_RandomEvents[]..." << endl;
    delete [] p_RandomEvents;
    cout << "p_RandomEvents[] deleted" << endl;
}

RandomEvent* RandomEventHandler::getRandomEvent(int index)
{
    cout << "Utilyzing RandomEvent* RandomEventHandler::getRandomEvent(int index)" << endl;
    /*if (!p_RandomEvents[index])
    {
        cout << "Object does not exist." << endl;
        return p_RandomEvents[0];
    }*/
    return p_RandomEvents[index];
}

