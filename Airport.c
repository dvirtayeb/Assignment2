/*
 * Airport.c
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */
#include "Airport.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define MAX_STR 255

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

char* fixNameAirport(char* nameAirport){
	int counter = 0;
	const char* space = " ";
	char textResult[MAX_STR] = "";
	char tempNameAirport[MAX_STR] = "";
	strcpy(tempNameAirport, nameAirport);
	char* word;
	word = strtok(tempNameAirport,space);
	while(word != NULL){
		fixWord(word, nameAirport, counter, textResult);
		if(islower(word[0]))
			break;
		word = strtok(NULL,space);
		counter++;
	}
	strcpy(nameAirport, textResult);
	return nameAirport;
}

void fixWord(char* word, char* nameAirport, int counter, char* textResult){
	word[0] = toupper(word[0]); // term 1
	if(strlen(word)%2 == 0 ){ // term 4
		changeDoubleSumOfLetters(word, strlen(word));
	}
	strcpy(textResult, word);
	textResult = strcat(textResult, "  ");// term 2
	if(counter == counterwords(nameAirport)) // term 1
	{
		if(strlen(word)%2 != 0) // not even
			word[0] = tolower(word[0]);
	}
//	return word;
}

void changeDoubleSumOfLetters(char* word, int lenWord){
	for (int i = 0; i < lenWord; ++i) {
		if(i%2 == 0)
			word[0] = toupper(word[0]);
		else
			word[0] = tolower(word[0]);
		word++;
	}

}

int counterwords(const char* nameAirport){
	int counter = 0;
	char strTemp[MAX_STR] = "";
	strcpy(strTemp, nameAirport);
	char* temp = strTemp;
	temp =strtok(strTemp, " ");

	while(temp != NULL){
		counter++;
		temp =strtok(NULL, " ");
	}
	return counter;
}
