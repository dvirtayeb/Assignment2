/*
 * AirportManger.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */

#include "AirportManger.h"
#include <stdio.h>
#include <stdlib.h>

Airport* addAirport()
{
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	printf("Please enter a name: ");
	scanf("%s",newAirport->nameAirport);
	printf("Please enter a state: ");
	scanf("%s",newAirport->nameState);
	printf("Please enter the code of the airport: ");
	scanf("%s",newAirport->nameCode);

	return newAirport;
}


