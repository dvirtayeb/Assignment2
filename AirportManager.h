#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_

#include "Airport.h"
#include <stdlib.h>

typedef struct {
	Airport *airportArr;
	int amountAirport;
} AirportManager;

void initAirportManager(AirportManager *airportM);
void userAddAirportToManager(AirportManager *airportM);
Airport* findAirport(const AirportManager *airportM, char *code);
int addAirportToManager(AirportManager *airportM, Airport *newAirport);
void printAirportManager(const AirportManager *airportM);
void freeAirportManager(AirportManager *airportM);
#endif /* AIRPORTMANAGER_H_ */
