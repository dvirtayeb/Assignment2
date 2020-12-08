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

typedef struct{
	Airport** airportArr;
	int amountAirport;
}AirportManger;

Airport* addAirport();
Airport* findAirport(AirportManger* airportManger,char* code);

#endif /* AIRPORTMANGER_H_ */
