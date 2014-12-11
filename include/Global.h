#ifndef GLOBALVARIABLES_H_INCLUDED
#define GLOBALVARIABLES_H_INCLUDED

#include <iostream>

#define SEATS_MIN 10
#define SEATS_MAX 100
#define THEATERS_MAX 10
#define SNACK_MAX 6
#define SOUND_MAX 1.5
#define SCREEN_MAX 1.5
#define PORJECTOR_MAX 1.5
#define MOVIES_MAX 6
#define OFFERED_LICENSES_MAX 3
#define SEAT_PRICE 100
#define SNACK_PRICE 600
#define UPGRADE_PRICE 500
#define THEATER_PRICE 2000
#define THEATER_RENT 1000
#define EMPLOYEE_WAGE 100
#define PROMOTION_MULTIPLY_COST 100
#define RANDOM_EVENTS_MAX 20

enum Season {Winter, Spring, Summer, Fall, Error};
enum Equipment {Screen_Size, Projector_Quality, Sound_Intensity};

void Divider();
void XBorderedBlankSpace();
void BorderX();
void ClearScreen();
void Pause();
void introduction();

#endif // GLOBALVARIABLES_H_INCLUDED
