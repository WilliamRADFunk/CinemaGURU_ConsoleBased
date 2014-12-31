#ifndef GLOBALVARIABLES_H_INCLUDED
#define GLOBALVARIABLES_H_INCLUDED

#include <iostream>

#define SEATS_MIN 10 // Formatting can handle a minimum of 0 seats. Do not set lower.
#define SEATS_MAX 100 // Formatting can handle up to 10,000 max seats per theater. Any more and formatting will need adjustment.
#define THEATERS_MAX 10 // Formatting can handle a total of 100 theaters. Any more and formatting of that section will need adjustment.
#define SNACK_MAX 6 // Formatting only accounts for a max of six snacks. If adjusted, adjust formatting of that section, too.
#define SOUND_MAX 1.5
#define SCREEN_MAX 1.5
#define PORJECTOR_MAX 1.5
#define MOVIES_MAX 20
#define OFFERED_LICENSES_MAX 3
#define SEAT_PRICE 100 // Formatting can handle a seat price of $99,999. Any more and adjustment is required.
#define SNACK_PRICE 600
#define UPGRADE_PRICE 500
#define THEATER_PRICE 2000
#define THEATER_RENT 1000
#define EMPLOYEE_WAGE 100 // Formatting can handle $999 per employee. Any more and that section will need adjustment.
#define PROMOTION_MULTIPLY_COST 100
#define RANDOM_EVENTS_MAX 20 // Only 20 scenarios have been written. More will need to be added before this can be changed.
#define PROFIT_MAX 100000 // Formatting can handle $999,999. It will need adjustment for more.
#define DEBT_MAX 5000 // Formatting can handle $999,999. It will need adjustment beyond that.
#define MaxLevel 1.5 // Do not exceed. This directly affects the algorithm used to determine tickets purchased each turn.

enum Season {Winter, Spring, Summer, Autumn, Error};
enum Equipment {Screen_Size, Projector_Quality, Sound_Intensity};

void Divider();
void XBorderedBlankSpace();
void XBorderedDivider();
void BorderX();
void ClearScreen();
void Pause();
void BlankLines(int);
void BlankSpaces(int);
void introduction();
void runInstructions();
void goodByeMessage();

#endif // GLOBALVARIABLES_H_INCLUDED
