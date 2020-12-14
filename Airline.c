#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"


void userAddFlight(Airline* airline, const int flightNum){
	Flight* flight = (Flight*)malloc(sizeof(Flight));
	puts("please enter departure code:");
	flight->depatureCode= (char*)malloc(sizeof(char));
	fgets(flight->depatureCode,STR_MAXSIZE,stdin);
	puts("please enter destination code:");
	flight->destinationCode = (char*)malloc(sizeof(char));
	fgets(flight->destinationCode,STR_MAXSIZE, stdin);
	puts("please enter Integer number that provide the time flight:");
	flight->departureTime = -1;
	while(flight->departureTime < 0 || flight->departureTime >23)
		scanf("%d", &flight->departureTime);
	puts("please enter a date flight:");
	char* textDate = (char*)malloc(sizeof(char));
	fgets(textDate,STR_MAXSIZE,stdin);
	Date* date = (Date*)malloc(sizeof(Date));
	userAddDate(date, textDate);
	airline->flights[flightNum] = flight; // ----> allocate(realloc) in the main
	airline->numOfFlights++;
	// -----------> free all!!!!!!!!!!!
	free(flight);
}

void printNumFlights(Airline* airline, char* depCode,char* destCode){
	for (int i = 0; i < airline->numOfFlights; ++i) {

	}
//	airline->flights
}

