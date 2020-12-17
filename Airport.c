#include "Airport.h"
#include "StringFuncHelper.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_STR 255

void initAirport(Airport *newAirport) {
	addAirportName(newAirport);
	addAirportState(newAirport);
	addIATACode(newAirport);
}
void addAirportName(Airport *newAirport) {
	puts("Enter The Airport Name:");
	newAirport->nameAirport = (char*) malloc(sizeof(char));
	fgets(newAirport->nameAirport, 255, stdin);
	fixNameAirport(newAirport->nameAirport);
}
void addAirportState(Airport *newAirport) {
	puts("Enter The Airport State's Name:");
	newAirport->nameState = (char*) malloc(sizeof(char));
	fgets(newAirport->nameState, 255, stdin);
}
void addIATACode(Airport *newAirport) // check this shit
{
	char temp[SIZE];
	puts("Enter The Airport's IATA Name in 3 uppercase characters exactly:");
	fgets(temp, SIZE, stdin);
	while (!checkIfIATACorrect(temp)) //From here
	{
		puts(
				"You've entered a wrong IATA Code ! Please Try Again with 3 Exactly Uppercase Letters");
		fgets(temp, SIZE, stdin);
	} // Until here -> will be a function
	newAirport->IATACode = &temp; // check shiet
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

void fixNameAirport(char *nameAirport) {
	trim(nameAirport, NULL);
	const char *space = " ";
	int lenName = strlen(nameAirport);
	int counter = 0;
	char *textResult = (char*) malloc((lenName + 1) * sizeof(char));
	char *tempNameAirport = strdup(nameAirport);
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
	//free(tempNameAirport); //---------------> check this shit
	free(textResult);
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

