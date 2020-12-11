/*
 * AirportManger.h
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */

#ifndef AIRPORTMANGER_H_
#define AIRPORTMANGER_H_

#include "Airport.h"
#include <stdlib.h>

#define CODE_SIZE 3

typedef struct{
	Airport** airportArr;
	int amountAirport;
}AirportManager;

void userAddAirport();
Airport* findAirport(AirportManager* airportManager,char* code);
void addAirport(AirportManager airportM, char* nameAirport, char* nameState, char* nameCode);
#endif /* AIRPORTMANGER_H_ */
