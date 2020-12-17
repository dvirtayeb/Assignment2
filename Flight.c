#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "Flight.h"
#define MAX_STR 255

void initFlight(Flight* flight)
{
	initFlightCodes(flight);
	initFlightTimeAndDate(flight);
}
void initFlightCodes(Flight* flight) // Flight Codes Are IATA code -> need to fix the IATA Func
{
	puts("please enter departure IATA code:");
	flight->depatureCode= (char*)malloc(sizeof(char));
	fgets(flight->depatureCode,MAX_STR,stdin); // Check IATA
	puts("please enter destination IATA code:");
	flight->destinationCode = (char*)malloc(sizeof(char));
	fgets(flight->destinationCode,MAX_STR, stdin);
}
void initFlightTimeAndDate(Flight* flight)
{
	puts("please enter Integer number that provide the time flight:");
	flight->departureTime = -1;
	while(flight->departureTime < 0 || flight->departureTime >23)
	{
		scanf("%d", &flight->departureTime);
	}
	puts("please enter a date flight:");
	char* textDate = (char*)malloc(sizeof(char));
	fgets(textDate,MAX_STR,stdin);
	flight->date = (Date*)malloc(sizeof(Date));
	userAddDate(flight->date, textDate);
}

int isCurrectDestination(Flight* flight, char* depCode,char* destCode){
	if(flight->depatureCode==depCode && flight->destinationCode==destCode)
		return 1;

	return 0;
}

int numOfFlightsInLine(Flight** flights,char* depCode,char* destCode){
	int counter=0;
	int i=0;
	while(flights[i]!=NULL){
		if(isCurrectDestination(flights[i],depCode,destCode)){
			counter++;
		}
		i++;
	}

	return counter;
}
void printFlight(Flight* flight)
{
	printf("Departure IATA Code: %s \n",flight->depatureCode);
	printf("Destination IATA Code: %s \n",flight->destinationCode);
	printf("Departs in hour: %d Date: %s\n",flight->departureTime,flight->date->dateStr);

}
void freeFlight(Flight* flight)
{
	free(flight->date);
	free(flight->departureTime);
	free(flight->depatureCode);
	free(flight->destinationCode);
	free(flight);
}



