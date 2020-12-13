
#ifndef AIRLINE_H_
#define AIRLINE_H_


#include "Flight.h"

typedef struct {
	char* name;
	int numOfFlights;
	Flight** flights;
}Airline;




#endif /* AIRLINE_H_ */
