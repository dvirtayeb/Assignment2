/*
 * Main.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */
#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManger.h"

int main(){
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	newAirport->nameAirport = (char*)realloc((newAirport->nameAirport), sizeof(newAirport->nameAirport));
	printf("choose name:");
	fgets(newAirport->nameAirport, 255, stdin);
	newAirport->nameAirport = fixNameAirport(newAirport->nameAirport);
	puts(newAirport->nameAirport);
	free(newAirport);

	return 0;
}

