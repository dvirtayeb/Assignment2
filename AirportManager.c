#include "AirportManager.h"
#include "Airport.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initAirportManager(AirportManager* airportM)
{
	int airportNum = 0;
	puts("please enter how many Airports do you want:");
	do{
		scanf("%d",&airportNum);
	}while(airportNum < 1);
	for (int i = 0; i < airportNum; ++i) {
		userAddAirport(airportM);
	}
}
void userAddAirport(AirportManager* airportM)
{
	Airport* newAirport;
	initAirport(newAirport);
	addAirportToManager(airportM,newAirport);
	freeAirport(newAirport);
}

void addAirportToManager(AirportManager* airportM, Airport* newAirport)
{

	if(airportM->amountAirport==0) {
		airportM->airportArr=(Airport*)malloc(sizeof(Airport));
		*(airportM->airportArr) = *(newAirport);
		airportM->amountAirport=1;
	} else {
		int len=airportM->amountAirport;
		airportM->airportArr=(Airport*)realloc(airportM->airportArr, (len+1)*sizeof(Airport));
		*(airportM->airportArr + len) = *(newAirport);
		airportM->amountAirport++;
	}

}

Airport* findAirport(AirportManager* airportM,char* code)
{
	for (int i = 0;  i < airportM->amountAirport; ++ i) {
		if(strcmp(airportM->airportArr[i]->IATACode,code))
				return airportM->airportArr[i];
	}
	return NULL;
}




