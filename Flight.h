/*
 * Flight.h
 *
 *  Created on: 5 Dec 2020
 *      Author: dvirtayeb
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "Date.h";
#include "Airport.h"

typedef struct {
	Airport* depatureAirport;
	Airport* destinationAirpot;
	int departureTime;
	Date* date;
};


#endif /* FLIGHT_H_ */
