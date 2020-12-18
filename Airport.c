#include "Airport.h"
#include "StringFuncHelper.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void initAirport(Airport *newAirport) {
	addAirportName(newAirport);
	addAirportState(newAirport);
	addIATACode(newAirport);
}
void addAirportName(Airport *newAirport) {
	puts("Enter The Airport Name:");
//	newAirport->nameAirport = (char*)realloc(newAirport->nameAirport,sizeof(char));
	newAirport->nameAirport = (char*) malloc(sizeof(char));
	do{
//		fgets(newAirport->nameAirport,MAX_STR, stdin);
		scanf("%[^\n]%*c",newAirport->nameAirport);
		if(strlen(newAirport->nameAirport) == 0)
			puts("you didn't insert probably");
	}while(strlen(newAirport->nameAirport) == 0);
	fixNameAirport(newAirport->nameAirport);
}
void addAirportState(Airport *newAirport) {
	puts("Enter The Airport State's Name:");
	newAirport->nameState = (char*) malloc(sizeof(char));
	scanf("%[^\n]%*c", newAirport->nameState);
}
void addIATACode(Airport *newAirport) // check this shit
{
	char temp[MAX_STR] ="";
	createCodeHelper(newAirport, temp);
	for (int i = 0; i < SIZE-1; ++i) {
		newAirport->IATACode[i] = temp[i];
	}
}

int isEqualAirports(Airport *pAirport1, Airport *pAirport2) {
	if (strcmp(pAirport1->IATACode, pAirport2->IATACode))
		return 1;
	return 0;
}

int checkCodeIATA(Airport *pAirport, char IATA[SIZE]) {
	if (strcmp(pAirport->IATACode, IATA))
		return 1;
	return 0;
}

void createCodeHelper(Airport* newAirport, char* code)
{
	do{
			puts("Enter The Airport's IATA Name in 3 uppercase characters exactly:");
			scanf("%[^\n]%*c", code);
			if(!checkIfIATACorrect(code)){
				puts("You've entered a wrong IATA Code!");
			}
		}while (!checkIfIATACorrect(code));
}

void fixNameAirport(char *nameAirport) {
	trim(nameAirport, NULL);
	const char *space = " ";
//	int lenName = strlen(nameAirport);
	int counter = 0;
	char textResult[MAX_STR] = "";
	char tempNameAirport[MAX_STR] = "";
	strcpy(tempNameAirport, nameAirport);
//	char* textResult = (char*) malloc((lenName + 1));
//	char *tempNameAirport = strdup(nameAirport);
	char *word = NULL;
	word = strtok(tempNameAirport, space);
	int countWords = counterwords(nameAirport);
	while (word != NULL) {
		fixWord(word, nameAirport, counter, textResult, countWords);
		if (islower(*word))
			break;
		word = strtok(NULL, space);
		counter++;
	}
	strcpy(nameAirport, textResult);
}
void printAirport(Airport *airport) {
	printf("%s Airport, Located in %s State \n and its IATA is : %s",
			airport->nameAirport, airport->nameState, airport->IATACode);
}

void freeAirport(Airport *air) {
	free(air->nameAirport);
	free(air->IATACode);
	free(air->nameState);
	free(air);
}

