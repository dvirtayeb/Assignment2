#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "Flight.h"
#include "StringFuncHelper.h"

void initFlight(Flight *flight) {
	initFlightCodes(flight);
	initFlightTimeAndDate(flight);
}

void initFlightCodes(Flight *flight) {
	puts("please enter departure IATA code:");
	flight->depatureCode = (char*) malloc(MAX_STR * sizeof(char));
	scanIATACode(flight->depatureCode);
	puts("please enter destination IATA code:");
	flight->destinationCode = (char*) malloc(MAX_STR * sizeof(char));
	do{
		scanIATACode(flight->destinationCode);
		if(!strcmp(flight->destinationCode, flight->depatureCode))
			puts("You cannot insert the same value, please insert again:");
	}while(!strcmp(flight->destinationCode, flight->depatureCode));
}

void initFlightTimeAndDate(Flight *flight) {
	puts("please enter Integer number that provide the time flight:");
	flight->departureTime = -1;
	while (flight->departureTime < 0 || flight->departureTime > 23) {
		scanf("%d", &flight->departureTime);
		getchar();
		if (flight->departureTime < 0 || flight->departureTime > 23)
			puts("departure Time is not correct, please insert again.");
	}
	puts("please enter a date flight:");
	char *textDate = (char*) malloc(MAX_STR * sizeof(char));
	flight->date = (Date*) malloc(sizeof(Date));
	int flag;
	do {
		scanf("%[^\n]%*c", textDate);
		flag = userAddDate(flight->date, textDate);
		if (!flag)
			puts("Enter the date in the right format: dd/mm/yyyy");
	} while (!flag);
}

int isCurrectDestination(const Flight *flight, const char *depCode,
		const char *destCode) {
	if (!strcmp(flight->depatureCode, depCode)
			&& !strcmp(flight->destinationCode, destCode))
		return 1;

	return 0;
}

int numOfFlightsInLine(Flight **flights, const int numOfFlights,
		const char *depCode, const char *destCode) {
	int counter = 0;
	int i = 0;
	while (i < numOfFlights) {
		if (isCurrectDestination(flights[i], depCode, destCode)) {
			counter++;
		}
		i++;
	}

	return counter;
}
void printFlight(const Flight *flight) {
	printf("Departure IATA Code: %s \n", flight->depatureCode);
	printf("Destination IATA Code: %s \n", flight->destinationCode);
	printf("Departs in hour: %d \n", flight->departureTime);
	printf("Date:");
	printDate(flight->date);

}
void freeFlight(Flight *flight) {
	free(flight->date->dateStr);
	free(flight->date);
	free(flight->depatureCode);
	free(flight->destinationCode);
	free(flight);
}

