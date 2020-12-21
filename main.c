#include <stdio.h>
#include "AirportManager.h"
#include "Airline.h"
#include "ControllerMenu.h"

int main() {
	Airline *airline = (Airline*) malloc(sizeof(Airline));
	AirportManager *airportM = (AirportManager*) malloc(sizeof(AirportManager));
	puts("Welcome, lets initialize our Airline:");
	initAirline(airline);
	puts("Okay, now lets initialize our Airport Manager:");
	initAirportManager(airportM);
	menu(airportM, airline);
	return 0;
}

