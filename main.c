#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"
#include "Airline.h"
#include "ControllerMenu.h"

int main()
{
	Airport* air=(Airport*)malloc(sizeof(Airport));
	initAirport(air);
	printf("%s  %s",air->nameAirport,air->IATACode);
	Airport* air2=(Airport*)malloc(sizeof(Airport));
	initAirport(air2);
	printf("%s  %s",air2->nameAirport,air2->IATACode);
	//AirportManager* airportM = (AirportManager*)malloc(sizeof(AirportManager));
	//initAirportManager(airportM);
	//menu(airportM);
	return 0;
}

