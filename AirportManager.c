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
		getchar();
	}while(airportNum < 1);
	for (int i = 0; i < airportNum; ++i) {
		userAddAirport(airportM);
	}
}
void userAddAirport(AirportManager* airportM)
{
	Airport* newAirport=(Airport*)malloc(sizeof(Airport));
	initAirport(newAirport);
	addAirportToManager(airportM,newAirport);
	freeAirport(newAirport);
}

int addAirportToManager(AirportManager* airportM, Airport* newAirport)
{

	if(airportM->amountAirport==0) {
		airportM->airportArr=(Airport*)malloc(sizeof(Airport));
		*(airportM->airportArr) = *(newAirport);
		airportM->amountAirport=1;
	} else {

		for (int i = 0; i < airportM->amountAirport; ++i) {
				if((checkCodeIATA((airportM->airportArr + i), newAirport->IATACode)))
					return 0;
			}
		int len=airportM->amountAirport;
		airportM->airportArr=(Airport*)realloc(airportM->airportArr, (len+1)*sizeof(Airport));
		*(airportM->airportArr + len) = *(newAirport);
		airportM->amountAirport++;
	}
	return 1;
}

Airport* findAirport(AirportManager* airportM,char* code)
{
	for (int i = 0;  i < airportM->amountAirport; ++ i) {
		if(strcmp((airportM->airportArr+i)->IATACode,code))
				return (airportM->airportArr+i);
	}
	return NULL;
}
void printAirportManager(AirportManager* airportM)
{
	printf("There are %d Airports under this Airport Manager and those are:",airportM->amountAirport);
	for (int i = 0; i < airportM->amountAirport; ++i)
	{
		printAirport(airportM->airportArr+i);
	}
}




