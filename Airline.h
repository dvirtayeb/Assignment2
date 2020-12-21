#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "Flight.h"

typedef struct {
	char *name;
	int numOfFlights;
	Flight **flights;
} Airline;

void userAddFlightToAirline(Airline *airline);
void initAirline(Airline *airline);
void printNumFlightsFromAirline(const Airline *airline, const char *depCode,
		const char *destCode);
void getAndPrintFlightsBetween2Airports(Airline *airline);
void printAirline(const Airline *airline);
void freeAirline(Airline *airline);

#endif /* AIRLINE_H_ */
