#include "Airport.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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
	return nameAirport;
}

void fixWord(char* word, char* tempNameAirport, int counter, char* textResult, int countWords){
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

void changeDoubleSumOfLetters(char* word, int lenWord){
	for (int i = 0; i < lenWord; ++i) {
		if(i%2 == 0)
			*(word + i) = toupper(*(word+i));
		else
			*(word + i) = tolower(*(word+i));
	}
}

int counterwords(char* nameAirport){
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
void fixLastWord(int isEvenAmountWord, int countWords, char* word, char* textResult){
//	rtrim(word, " ");
	if(isEvenAmountWord != 0 && countWords>1){ // the word not even
		*(word) = tolower(*word);
		strcat(textResult, word);
	}
	else
		strcat(textResult, word);
}

char* rtrim(char *word, const char *seps)
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
