#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"
#include "Flight.h"
#include "Airport.h"

void initAirline(Airline* airline) // initialize an empty airline
{
	puts("Enter the Airline Name:");
	airline->name=(char*)malloc(sizeof(char));
	scanf("%[^\n]%*c",airline->name);
	airline->numOfFlights=0;
	airline->flights=(Flight**)malloc(sizeof(Flight*));
}


void userAddFlightToAirline(Airline* airline){
	Flight* flight = (Flight*)malloc(sizeof(Flight));
	initFlight(flight);
	airline->flights[airline->numOfFlights] = flight; // ----> allocate(realloc) in the main
	airline->numOfFlights++;
	airline->flights=(Flight**)realloc(airline->flights, (airline->numOfFlights)*sizeof(Flight*));
	freeFlight(flight);
}

void printNumFlightsFromAirline(Airline* airline, char* depCode,char* destCode){
	int counter= numOfFlightsInLine(airline->flights,depCode,destCode);
	printf("%s: There are %d Flights in the required line",airline->name,counter);

}
void getAndPrintFlightsBetween2Airports(Airline* airline){
	char depCode[SIZE]="";
	char destCode[SIZE]="";
	puts("please enter Source IATA code:");
	scanIATACode(depCode);
	puts("please enter Destination IATA code:");
	scanIATACode(destCode);
	printNumFlightsFromAirline(airline, depCode, destCode);

}

void printAirline(Airline* airline)
{
	printf("Airline \"%s\" has %d Flights in it : \n",airline->name,airline->numOfFlights);
	for ( int i = 0;  i < airline->numOfFlights; i++) {
		printFlight(airline->flights[i]);
	}
}

void freeAirline(Airline* airline)
{
	free(airline->name);
	free(airline->flights);
	free(airline);
}



