#include "Airport.h"
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
	newAirport->IATACode = (char*)malloc(sizeof(char));
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
	const char* space = " ";
	int lenName = strlen(nameAirport);
	int counter = 0;
	char* textResult = (char*)malloc((lenName+1)*sizeof(char));
	char* tempNameAirport = strdup(nameAirport);
	char* word = NULL;
	word = strtok(tempNameAirport,space);
	int countWords = counterwords(nameAirport); // ----> check this shit
	while(word != NULL){
		fixWord(word, nameAirport, counter, textResult, countWords);
		if(islower(*word))
			break;
		word = strtok(NULL,space);
		counter++;
	}
	strcpy(nameAirport, textResult);
//	free(tempNameAirport); ---------------> check this shit
	free(textResult);
}

void fixWord(char* word, char* tempNameAirport, int counter, char* textResult, int countWords)
{
	*word = toupper(*word); // term 1
	char* tempWord = strdup(word);
	int length = strlen(tempWord);
	if(counter == countWords)
			length = length-1;
	int isEvenAmountWord = (length) % 2;
	if((isEvenAmountWord) == 0 ){ // term 4
		changeDoubleSumOfLetters(word, strlen(word));
	}
	if(counter != countWords){
		strcat(textResult, word);
		textResult = strcat(textResult, "  ");// term 2
	}
	else // Last word:
	{
		fixLastWord(isEvenAmountWord, countWords, word, textResult);
	}
	free(tempWord);
}

void changeDoubleSumOfLetters(char* word, int lenWord)
{
	for (int i = 0; i < lenWord; ++i) {
		if(i%2 == 0)
			*(word + i) = toupper(*(word+i));
		else
			*(word + i) = tolower(*(word+i));
	}
}

int counterwords(char* nameAirport)
{
//	rtrim(nameAirport, " ");
	char* str = strdup(nameAirport);
	if(str == NULL)
		return 0;
	int counter = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if((str[i] == ' ' && str[i+1] != ' ') && str[0] != ' ')
			counter++;
	}
	free(str);
	return counter;
}
void fixLastWord(int isEvenAmountWord, int countWords, char* word, char* textResult)
{
//	rtrim(word, " ");
	if(isEvenAmountWord != 0 && countWords>1){ // the word not even
		*(word) = tolower(*word);
		strcat(textResult, word);
	}
	else
		strcat(textResult, word);
}

char* rtrim(char *word, const char *seps) // MAYBE WE WILL NEED MAYBE NOT
{
	int i;
	if (seps == NULL)
		seps = "\t\n\v\f\r";
	i = strlen(word) -1;
	while (i >= 0 && strchr(seps, word[i] != '\0')){
		word[i] = '\0';
		i--;
	}
	return word;
}
void freeAirport(Airport* air)
{
	free(air->nameAirport);
	free(air->IATACode);
	free(air->nameState);
	free(air);
}

