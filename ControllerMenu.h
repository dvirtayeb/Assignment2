#ifndef CONTROLLERMENU_H_
#define CONTROLLERMENU_H_

#include "Airport.h"
#include "AirportManager.h"
#include "Airline.h"
#include "Flight.h"
#define ADD_FLIGHT_TO_AIRLINE 1
#define ADD_AIRPORT_TO_AIRLINE 2
#define PRINT_DETAILS_ABOUT_AIRPORT 3
#define PRINT_DETAILS_ABOUT_AIRLINE 4
#define PRINT_AMOUNT_FLIGHT_BETWEEN_AIRPORTS 5
#define EXIT 6

void menu(AirportManager* airportM);

#endif /* CONTROLLERMENU_H_ */
