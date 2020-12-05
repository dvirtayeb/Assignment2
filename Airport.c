/*
 * Airport.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */
#include "Airport.h"
#include <string.h>

int isEqualAirports(Airport* pAirport1, Airport* pAirport2)
{
	if(strcmp(pAirport1->nameCode, pAirport2->nameCode))
		return 1;
	return 0;
}


int checkCodeIATA(Airport* pAirport,char* code)
{
	if(strcmp(pAirport->nameCode, code))
		return 1;
	return 0;
}
