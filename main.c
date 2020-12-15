/*
 * Main.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */
#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"

int main(){
//	AirportManager* airportM = (AirportManager*)malloc(sizeof(AirportManager));
//	Airport* airport =(Airport*)malloc(sizeof(Airport));
//	userAddAirport(airportM);
//	airport->airportArr[0] =
//	Date* date1 = (Date*)malloc(sizeof(Date));
//	while(strcmp(date1->dateStr, ""))
//		userAddDate(date1, "10/01/1990");
//	puts(date1->dateStr); // ------------------ check how we can print correctly.
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	newAirport->nameAirport = (char*)realloc((newAirport->nameAirport), sizeof(newAirport->nameAirport));
	printf("choose name:");
	fgets(newAirport->nameAirport, 255, stdin);
	newAirport->nameAirport = fixNameAirport(newAirport->nameAirport);
	puts(newAirport->nameAirport);
	free(newAirport->nameAirport);
	free(newAirport);

	Airport* newAirport2 = (Airport*)malloc(sizeof(Airport));
	newAirport2->nameAirport = (char*)realloc((newAirport2->nameAirport), sizeof(newAirport2->nameAirport));
	printf("choose name:");
	fgets(newAirport2->nameAirport, 255, stdin);
	newAirport2->nameAirport = fixNameAirport(newAirport2->nameAirport);
	puts(newAirport2->nameAirport);
//	addAirport();
	free(newAirport2->nameAirport);
	free(newAirport2);
//	free(date1);
//	free(airportM);
	return 0;
}

