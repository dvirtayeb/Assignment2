#include "Airport.h"
#include "Flight.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_STR 255

int isCurrectDestination(Flight* flight, char* depCode,char* destCode){
	if(flight->depatureCode==depCode && flight->destinationCode==destCode)
		return 1;

	return 0;
}

int numOfFlightsInLine(Flight** flights,char* depCode,char* destCode){
	int counter=0;
	int i=0;
	while(flights[i]!=NULL){
		if(isCurrectDestination(flights[i],depCode,destCode)){
			counter++;
		}
		i++;
	}

	return counter;
}



