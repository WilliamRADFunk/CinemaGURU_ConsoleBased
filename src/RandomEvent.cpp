#include <iostream>
#include <sstream>
#include <locale>

#include "RandomEvent.h"
#include "Global.h"

using namespace std;

RandomEvent::RandomEvent()
{

}

RandomEvent::~RandomEvent()
{

}

char RandomEvent::getRating()
{
    return Rating;
}

float RandomEvent::getMonetaryBase()
{
    return MonetaryBase;
}

int RandomEvent::getFactorChoiceA()
{
    return FactorChoiceA;
}

int RandomEvent::getFactorChoiceB()
{
    return FactorChoiceB;
}

int RandomEvent::getFactorChoiceC()
{
    return FactorChoiceC;
}

int RandomEvent::getFactorChoiceD()
{
    return FactorChoiceD;
}

void RandomEvent::printScenario()
{
    locale loc;
    char c;
    string String1 = "";
    string String2 = "";
    string String3 = "";
    string String4 = "";
    string String5 = "";
    XBorderedBlankSpace();
    for (int i = 0, j = 0, k = 0; i < Scenario.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = Scenario[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 73)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 73)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 73 && k < 146)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 146 && k < 219)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 219 && k < 292)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += Scenario[i];
                i++;
                if ( i >= Scenario.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The Scenario string is too long." << endl;
            String5 += Scenario[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "")
    {
        cout << "X    " << String4 << "X" << endl;
    }
    XBorderedBlankSpace();
    cout << "X    Do you:";
    for (int i = 0; i < 66; i++)
    {
        cout << " ";
    }
    cout << "X" << endl;
    XBorderedBlankSpace();
}

void RandomEvent::printOptionA()
{
    locale loc;
    char c;
    string String1 = "A. ";
    string String2 = "   ";
    string String3 = "   ";
    string String4 = "   ";
    string String5 = "   ";
    for (int i = 0, j = 0, k = 0; i < OptionA.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = OptionA[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 70)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 70)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 70 && k < 140)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 140 && k < 210)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 210 && k < 280)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += OptionA[i];
                i++;
                if ( i >= OptionA.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The OptionA string is too long." << endl;
            String5 += OptionA[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "   ")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "   ")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "   ")
    {
        cout << "X    " << String4 << "X" << endl;
    }
    XBorderedBlankSpace();
}

void RandomEvent::printOptionB()
{
    locale loc;
    char c;
    string String1 = "B. ";
    string String2 = "   ";
    string String3 = "   ";
    string String4 = "   ";
    string String5 = "   ";
    for (int i = 0, j = 0, k = 0; i < OptionB.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = OptionB[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 70)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 70)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 70 && k < 140)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 140 && k < 210)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 210 && k < 280)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += OptionB[i];
                i++;
                if ( i >= OptionB.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The OptionB string is too long." << endl;
            String5 += OptionB[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "   ")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "   ")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "   ")
    {
        cout << "X    " << String4 << "X" << endl;
    }
    XBorderedBlankSpace();
}

void RandomEvent::printOptionC()
{
    locale loc;
    char c;
    string String1 = "C. ";
    string String2 = "   ";
    string String3 = "   ";
    string String4 = "   ";
    string String5 = "   ";
    for (int i = 0, j = 0, k = 0; i < OptionC.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = OptionC[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 70)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 70)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 70 && k < 140)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 140 && k < 210)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 210 && k < 280)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += OptionC[i];
                i++;
                if ( i >= OptionC.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The OptionC string is too long." << endl;
            String5 += OptionC[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "   ")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "   ")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "   ")
    {
        cout << "X    " << String4 << "X" << endl;
    }
    XBorderedBlankSpace();
}

void RandomEvent::printOptionD()
{
    locale loc;
    char c;
    string String1 = "D. ";
    string String2 = "   ";
    string String3 = "   ";
    string String4 = "   ";
    string String5 = "   ";
    for (int i = 0, j = 0, k = 0; i < OptionD.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = OptionD[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 70)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 70)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 70 && k < 140)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 140 && k < 210)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 210 && k < 280)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += OptionD[i];
                i++;
                if ( i >= OptionD.length() )
                {
                    for (; j < 69; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The OptionD string is too long." << endl;
            String5 += OptionD[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "   ")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "   ")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "   ")
    {
        cout << "X    " << String4 << "X" << endl;
    }
    XBorderedBlankSpace();
}

void RandomEvent::printDescriptionResultA()
{
    locale loc;
    char c;
    string String1 = "";
    string String2 = "";
    string String3 = "";
    string String4 = "";
    string String5 = "";
    XBorderedBlankSpace();
    for (int i = 0, j = 0, k = 0; i < DescriptionResultA.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = DescriptionResultA[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 73)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 73)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 73 && k < 146)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 146 && k < 219)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 219 && k < 292)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += DescriptionResultA[i];
                i++;
                if ( i >= DescriptionResultA.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The DescriptionResultA string is too long." << endl;
            String5 += DescriptionResultA[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "")
    {
        cout << "X    " << String4 << "X" << endl;
    }
}

void RandomEvent::printDescriptionResultB()
{
    locale loc;
    char c;
    string String1 = "";
    string String2 = "";
    string String3 = "";
    string String4 = "";
    string String5 = "";
    XBorderedBlankSpace();
    for (int i = 0, j = 0, k = 0; i < DescriptionResultB.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = DescriptionResultB[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 73)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 73)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 73 && k < 146)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 146 && k < 219)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 219 && k < 292)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += DescriptionResultB[i];
                i++;
                if ( i >= DescriptionResultB.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The DescriptionResultB string is too long." << endl;
            String5 += DescriptionResultB[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "")
    {
        cout << "X    " << String4 << "X" << endl;
    }
}

void RandomEvent::printDescriptionResultC()
{
    locale loc;
    char c;
    string String1 = "";
    string String2 = "";
    string String3 = "";
    string String4 = "";
    string String5 = "";
    XBorderedBlankSpace();
    for (int i = 0, j = 0, k = 0; i < DescriptionResultC.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = DescriptionResultC[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 73)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 73)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 73 && k < 146)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 146 && k < 219)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 219 && k < 292)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += DescriptionResultC[i];
                i++;
                if ( i >= DescriptionResultC.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The DescriptionResultC string is too long." << endl;
            String5 += DescriptionResultC[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "")
    {
        cout << "X    " << String4 << "X" << endl;
    }
}

void RandomEvent::printDescriptionResultD()
{
    locale loc;
    char c;
    string String1 = "";
    string String2 = "";
    string String3 = "";
    string String4 = "";
    string String5 = "";
    XBorderedBlankSpace();
    for (int i = 0, j = 0, k = 0; i < DescriptionResultD.length();)
    {
        // i keeps track of index in original string.
        // j creates enough whitespace after each string to each line align with border.
        // k ensures there are the same number of character in each string.
        c = DescriptionResultD[i];
        // Resets j for the next string once j reaches maximum string length.
        if (j >= 73)
        {
            j = 0;
            i++;
        }
        // Fills String1 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string2.
        if (k < 73)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String1 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String1 += " ";
            }
            else
            {
                String1 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String1 += " ";
                    }
                }
            }
        }
        // Fills String2 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string3.
        else if (k >= 73 && k < 146)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String2 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String2 += " ";
            }
            else
            {
                String2 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String2 += " ";
                    }
                }
            }
        }
        // Fills String3 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string4.
        else if (k >= 146 && k < 219)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String3 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String3 += " ";
            }
            else
            {
                String3 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String3 += " ";
                    }
                }
            }
        }
        // Fills String4 with approx 50 characters from original string.
        // At the end of nearest word, input begins on string5.
        else if (k >= 219 && k < 292)
        {
            if (j >= 50 && !isspace(c,loc))
            {
                String4 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
            else if (j >= 50 && isspace(c,loc))
            {
                String4 += " ";
            }
            else
            {
                String4 += DescriptionResultD[i];
                i++;
                if ( i >= DescriptionResultD.length() )
                {
                    for (; j < 72; j++)
                    {
                        String4 += " ";
                    }
                }
            }
        }
        // In the event the maximum number of character is passed. The extras are dumped into a dummy string.
        else
        {
            cout << "The DescriptionResultD string is too long." << endl;
            String5 += DescriptionResultD[i];
        }
        j++;
        k++;
    }
    cout << "X    " << String1 << "X" << endl;
    // If the description was short enough to fit into one string, don't display the others.
    if (String2 != "")
    {
        cout << "X    " << String2 << "X" << endl;
    }
    if (String3 != "")
    {
        cout << "X    " << String3 << "X" << endl;
    }
    if (String4 != "")
    {
        cout << "X    " << String4 << "X" << endl;
    }
}

void RandomEvent::presentEvent()
{
    BorderX();
    printScenario();
    printOptionA();
    printOptionB();
    printOptionC();
    printOptionD();
    BorderX();
    cout << endl << "(Type either A, B, C, or D): ";
}

float RandomEvent::presentOutcome(char Choice)
{
    BorderX();
    XBorderedBlankSpace();
    cout << "X    You chose:";
    for (int i = 0; i < 63; i++)
    {
        cout << " ";
    }
    cout << "X" << endl;
    XBorderedBlankSpace();

    if (Choice == 'a' || Choice == 'A')
    {
        printOptionA();
        XBorderedBlankSpace();
        printDescriptionResultA();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(2);
        Pause();
        // Determines how much money the player won or lost based on their decision
        // and whether the Random Event was a 'G'ood event or a 'B'ad event.
        if (Rating == 'G')
        {
            return (MonetaryBase * FactorChoiceA);
        }
        else
        {
            return ( -(MonetaryBase * FactorChoiceA) );
        }
    }
    if (Choice == 'b' || Choice == 'B')
    {
        printOptionB();
        XBorderedBlankSpace();
        printDescriptionResultB();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(2);
        Pause();
        // Determines how much money the player won or lost based on their decision
        // and whether the Random Event was a 'G'ood event or a 'B'ad event.
        if (Rating == 'G')
        {
            return (MonetaryBase * FactorChoiceB);
        }
        else
        {
            return ( -(MonetaryBase * FactorChoiceB) );
        }
    }
    if (Choice == 'c' || Choice == 'C')
    {
        printOptionC();
        XBorderedBlankSpace();
        printDescriptionResultC();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(2);
        Pause();
        // Determines how much money the player won or lost based on their decision
        // and whether the Random Event was a 'G'ood event or a 'B'ad event.
        if (Rating == 'G')
        {
            return (MonetaryBase * FactorChoiceC);
        }
        else
        {
            return ( -(MonetaryBase * FactorChoiceC) );
        }
    }
    if (Choice == 'd' || Choice == 'D')
    {
        printOptionD();
        XBorderedBlankSpace();
        printDescriptionResultD();
        XBorderedBlankSpace();
        BorderX();
        BlankLines(2);
        Pause();
        // Determines how much money the player won or lost based on their decision
        // and whether the Random Event was a 'G'ood event or a 'B'ad event.
        if (Rating == 'G')
        {
            return (MonetaryBase * FactorChoiceD);
        }
        else
        {
            return ( -(MonetaryBase * FactorChoiceD) );
        }
    }
    cout << "Program should not reach this point. Returning $0.0" << endl;
    return 0.0;
}

void RandomEvent::setRating(char R)
{
    Rating = R;
}

void RandomEvent::setMonetaryBase(float Base)
{
    MonetaryBase = Base;
}

void RandomEvent::setFactorChoiceA(int Choice)
{
    FactorChoiceA = Choice;
}

void RandomEvent::setFactorChoiceB(int Choice)
{
    FactorChoiceB = Choice;
}

void RandomEvent::setFactorChoiceC(int Choice)
{
    FactorChoiceC = Choice;
}

void RandomEvent::setFactorChoiceD(int Choice)
{
    FactorChoiceD = Choice;
}

void RandomEvent::setScenario(string Scene)
{
    Scenario = Scene;
}

void RandomEvent::setOptionA(string Option)
{
    OptionA = Option;
}

void RandomEvent::setOptionB(string Option)
{
    OptionB = Option;
}

void RandomEvent::setOptionC(string Option)
{
    OptionC = Option;
}

void RandomEvent::setOptionD(string Option)
{
    OptionD = Option;
}

void RandomEvent::setDescriptionResultA(string Result)
{
    // Calculates how much money is gained or lost by player's decision.
    int NetCash;
    NetCash = (MonetaryBase * FactorChoiceA);
    // Converts the integer into string form and adds it to the end of the DescriptionResultA
    stringstream SS;
    SS << NetCash;
    DescriptionResultA = Result;
    DescriptionResultA += SS.str();
}

void RandomEvent::setDescriptionResultB(string Result)
{
    // Calculates how much money is gained or lost by player's decision.
    int NetCash;
    NetCash = (MonetaryBase * FactorChoiceB);
    // Converts the integer into string form and adds it to the end of the DescriptionResultA
    stringstream SS;
    SS << NetCash;
    DescriptionResultB = Result;
    DescriptionResultB += SS.str();
}

void RandomEvent::setDescriptionResultC(string Result)
{
    // Calculates how much money is gained or lost by player's decision.
    int NetCash;
    NetCash = (MonetaryBase * FactorChoiceC);
    // Converts the integer into string form and adds it to the end of the DescriptionResultA
    stringstream SS;
    SS << NetCash;
    DescriptionResultC = Result;
    DescriptionResultC += SS.str();
}

void RandomEvent::setDescriptionResultD(string Result)
{
    // Calculates how much money is gained or lost by player's decision.
    int NetCash;
    NetCash = (MonetaryBase * FactorChoiceD);
    // Converts the integer into string form and adds it to the end of the DescriptionResultA
    stringstream SS;
    SS << NetCash;
    DescriptionResultD = Result;
    DescriptionResultD += SS.str();
}
