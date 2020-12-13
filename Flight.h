
#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "Date.h"
#include "Airport.h"

typedef struct {
	char* depatureCode;
	char* destinationCode;
	int departureTime;
	Date* date;
}Flight;

int isCurrectDestination(Flight* flight, char* depCode,char* destCode);
int numOfFlightsInLine(Flight** flights,char* depCode,char* destCode);



#endif /* FLIGHT_H_ */
