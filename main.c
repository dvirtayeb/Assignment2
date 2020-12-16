#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"
#include "Airline.h"
#include "ControllerMenu.h"

int main()
{
	AirportManager* airportM = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(airportM);
	menu(airportM);
	return 0;
}

