#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_

#include "Airport.h"
#include <stdlib.h>

#define STR_MAXSIZE 255

typedef struct {
	Airport* airportArr;
	int amountAirport;
}AirportManager;

void initAirportManager(AirportManager* airportM);
void userAddAirport(AirportManager* airportM);
Airport* findAirport(AirportManager* airportM,char* code);
int addAirportToManager(AirportManager* airportM, Airport* newAirport);
#endif /* AIRPORTMANAGER_H_ */
