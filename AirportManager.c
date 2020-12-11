/*
 * AirportManger.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */

#include "AirportManger.h"
#include <stdio.h>
#include <stdlib.h>


void userAddAirport()
{
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	printf("Please enter a name: ");
	fgets(newAirport->nameAirport, 255, stdin);
	printf("Please enter a state: ");
	fgets(newAirport->nameState, 255, stdin);
	printf("Please enter the code of the airport: ");
	fgets(newAirport->nameCode, CODE_SIZE, stdin);


	free(newAirport);
}

void addAirport(AirportManager airportM, char* nameAirport, char* nameState, char* nameCode)
{
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	newAirport->nameAirport = nameAirport;
	newAirport->nameState = nameState;
	newAirport->nameCode = nameCode;

	airportM->(airportArr+ strlen(airpotArr) - 1) = newAirport; // -------------> check this shit

	free(newAirport);
}

