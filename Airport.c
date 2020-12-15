#include "Airport.h"
#include "StringFuncHelper.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_STR 255

void initAirport(Airport* newAirport)
{
	addAirportName(newAirport);
	addAirportState(newAirport);
	addIATACode(newAirport);
}
void addAirportName(Airport* newAirport)
{
	printf("Enter The Airport Name:");
	newAirport->nameAirport = (char*)malloc(sizeof(char));
	fgets(newAirport->nameAirport, 255, stdin);
	fixNameAirport(newAirport->nameAirport);
}
void addAirportState(Airport* newAirport)
{
	printf("Enter The Airport State's Name:");
	newAirport->nameState = (char*)malloc(sizeof(char));
	fgets(newAirport->nameState, 255, stdin);
}
void addIATACode(Airport* newAirport) // check this shit
{
	int i=1;
	printf("Enter The Airport's IATA Name in 3 uppercase characters exactly:");
	fgets(newAirport->IATACode, SIZE, stdin);
	while(i)
	{

	}
}

int isEqualAirports(Airport* pAirport1, Airport* pAirport2)
{
	if(strcmp(pAirport1->IATACode, pAirport2->IATACode))
		return 1;
	return 0;
}

int checkCodeIATA(Airport* pAirport,char IATA[SIZE])
{
	if(strcmp(pAirport->IATACode, IATA))
		return 1;
	return 0;
}

void fixNameAirport(char* nameAirport)
{
	trim(nameAirport, NULL);
	const char* space = " ";
	int lenName = strlen(nameAirport);
	int counter = 0;
	char* textResult = (char*)malloc((lenName+1)*sizeof(char));
	char* tempNameAirport = strdup(nameAirport);
	char* word = NULL;
	word = strtok(tempNameAirport,space);
	int countWords = counterwords(nameAirport);
	while(word != NULL){
		fixWord(word, nameAirport, counter, textResult, countWords);
		if(islower(*word))
			break;
		word = strtok(NULL,space);
		counter++;
	}
	strcpy(nameAirport, textResult);
	free(tempNameAirport); //---------------> check this shit
	free(textResult);
}

void freeAirport(Airport* air)
{
	free(air->nameAirport);
	free(air->IATACode);
	free(air->nameState);
	free(air);
}

