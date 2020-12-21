#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"
#include "Flight.h"
#include "Airport.h"
#include "StringFuncHelper.h"

void initAirline(Airline *airline) // initialize an empty airline
{
	puts("Enter the Airline Name:");
	airline->name = (char*) malloc(MAX_STR * sizeof(char));
	scanf("%[^\n]%*c", airline->name);
	airline->numOfFlights = 0;
	airline->flights = (Flight**) malloc(sizeof(Flight*));
}

void userAddFlightToAirline(Airline *airline) {
	Flight *flight = (Flight*) malloc(sizeof(Flight));
	initFlight(flight);
	airline->flights[airline->numOfFlights] = flight;
	airline->numOfFlights++;
	airline->flights = (Flight**) realloc(airline->flights,
			(airline->numOfFlights) * sizeof(Flight*));
	puts("Flight added");
}

void printNumFlightsFromAirline(const Airline *airline, const char *depCode,
		const char *destCode) {
	int counter = numOfFlightsInLine(airline->flights, airline->numOfFlights,
			depCode, destCode);
	printf("Airline %s: There are %d Flights in the required line\n",
			airline->name, counter);

}

void getAndPrintFlightsBetween2Airports(Airline *airline) {
	char depCode[IATA_SIZE] = "";
	char destCode[IATA_SIZE] = "";
	puts("please enter Source IATA code:");
	scanIATACode(depCode);
	puts("please enter Destination IATA code:");
	scanIATACode(destCode);
	printNumFlightsFromAirline(airline, depCode, destCode);

}

void printAirline(const Airline *airline) {
	printf("Airline \"%s\" has %d Flights in it : \n", airline->name,
			airline->numOfFlights);
	for (int i = 0; i < airline->numOfFlights; i++) {
		printFlight(airline->flights[i]);
	}
}

void freeAirline(Airline *airline) {
	free(airline->name);
	for (int i = 0; i < airline->numOfFlights; ++i) {
		freeFlight(airline->flights[i]);
	}
	free(airline->flights);
	free(airline);
}

