#include "AirportManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void userAddAirport(AirportManager* airportM)
{
	Airport* newAirport = (Airport*)malloc(sizeof(Airport));
	printf("Please enter a name: ");
	fgets(newAirport->nameAirport, STR_MAXSIZE, stdin);
	printf("Please enter a state: ");
	fgets(newAirport->nameState, STR_MAXSIZE, stdin);
	printf("Please enter the code of the airport: ");
	fgets(newAirport->nameCode, CODE_SIZE, stdin);

	addAirport(airportM,newAirport);

	free(newAirport);
}

void addAirport(AirportManager* airportM, Airport* newAirport)
{

	if(airportM->amountAirport==0) {
		airportM->airportArr=(Airport**)malloc(sizeof(Airport*));
		airportM->airportArr[0]=newAirport;
		airportM->amountAirport=1;
	} else {
		int len=airportM->amountAirport;
		airportM->airportArr=(Airport**)realloc(airportM->airportArr, (len+1)*sizeof(Airport*));
		airportM->airportArr[len]=newAirport;
		airportM->amountAirport++;
	}

}

Airport* findAirport(AirportManager* airportM,char* code){
	for (int i = 0;  i < airportM->amountAirport; ++ i) {
		if(strcmp(airportM->airportArr[i]->nameCode,code))
				return airportM->airportArr[i];
	}
	return NULL;
}



