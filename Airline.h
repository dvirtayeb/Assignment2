
#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "Flight.h"
#define STR_MAXSIZE 255

typedef struct {
	char* name;
	int numOfFlights;
	Flight** flights;
}Airline;

void userAddFLightToAirline(Airline* airline);
void initAirline(Airline* airline);
void printNumFlightsFromAirline(Airline* airline, char* depCode,char* destCode);
void printAirline(Airline* airline);
void freeAirline(Airline* airline);



#endif /* AIRLINE_H_ */
