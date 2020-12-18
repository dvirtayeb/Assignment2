#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"
#include "Airline.h"
#include "ControllerMenu.h"

int main()
{
	// check DATE:
//	Date* date = (Date*)malloc(sizeof(Date));
//	userAddDate(date, "19/05/1990");

	// Check Airport:
//	Airport* air = (Airport*)malloc(sizeof(Airport));
//	addAirportName(air);// ----> its work from here... WTF  ------------> YOOOOOOOOO MAMA.. check this shit



	// Final MAIN:
	AirportManager* airportM = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(airportM);
	menu(airportM);
	return 0;
}

