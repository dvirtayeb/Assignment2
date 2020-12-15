
#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "Flight.h"
#define STR_MAXSIZE 255

typedef struct {
	char* name;
	int numOfFlights;
	Flight** flights;
}Airline;

void userAddFLightToAirline(Airline* airline, const int flightNum);
//void addFlight();
void initAirline();
int printNumFlightsFromAirline(Airline* airline, char* depCode,char* destCode);



#endif /* AIRLINE_H_ */
