#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "Date.h"
#include "Airport.h"

typedef struct {
	char *depatureCode;
	char *destinationCode;
	int departureTime;
	Date *date;
} Flight;

int isCurrectDestination(const Flight *flight, const char *depCode,
		const char *destCode);
int numOfFlightsInLine(Flight **flights, const int numOfFlights,
		const char *depCode, const char *destCode);
void initFlight(Flight *flight);
void initFlightTimeAndDate(Flight *flight);
void initFlightCodes(Flight *flight);
void printFlight(const Flight *flight);
void freeFlight(Flight *flight);

#endif /* FLIGHT_H_ */
