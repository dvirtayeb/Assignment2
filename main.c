#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"
#include "Airline.h"
#include "ControllerMenu.h"

int main(){
	AirportManager* airportM = (AirportManager*)malloc(sizeof(AirportManager));
	Airport** airport = (Airport**)malloc(sizeof(Airport*));
	int airportNum = 0;
	puts("please enter how many Airports do you want:");
			do{
				scanf("%d",&airportNum);
			}while(airportNum < 1);
			airport = (Airport**)realloc(airport, airportNum*sizeof(airport));
	menu(airportM, airport);
	return 0;
}

