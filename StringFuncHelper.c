#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "StringFuncHelper.h"

void fixWord(char *word, char *tempNameAirport, const int counter,
		char *textResult, const int countWords) {
	*word = toupper(*word); // term 1
	char *tempWord = strdup(word);
	int length = strlen(tempWord);
	int isEvenAmountWord = (length) % 2;
	if ((isEvenAmountWord) == 0) { // term 4
		changeDoubleSumOfLetters(word, strlen(word));
	}
	if (counter != countWords) {
		strcat(textResult, word);
		textResult = strcat(textResult, "  "); // term 2
	} else // Last word:
	{
		fixLastWord(isEvenAmountWord, countWords, word, textResult);
	}
	free(tempWord);
}

void changeDoubleSumOfLetters(char *word, const int lenWord) {
	for (int i = 0; i < lenWord; ++i) {
		if (i % 2 == 0)
			*(word + i) = toupper(*(word + i));
		else
			*(word + i) = tolower(*(word + i));
	}
}

int counterwords(char *nameAirport) {
	char *str = strdup(nameAirport);
	if (str == NULL)
		return 0;
	int counter = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if ((str[i] == ' ' && str[i + 1] != ' '))
			counter++;
	}
	free(str);
	return counter;
}

void fixLastWord(const int isEvenAmountWord, const int countWords, char *word,
		char *textResult) {
	if (isEvenAmountWord != 0 && countWords > 0) { // the word not even
		*(word) = tolower(*word);
		strcat(textResult, word);
	} else
		strcat(textResult, word);
}

int checkIfIATACorrect(const char IATACode[IATA_SIZE]) {
	if (strlen(IATACode) != 3)
		return 0;
	for (int i = 0; i < IATA_SIZE - 1; i++) {
		if (!isupper(IATACode[i])) {
			return 0;
		}
	}
	return 1;
}

void scanIATACode(char *code) {
	int flag = 0;
	while (!flag) {

		scanf("%[^\n]%*c", code);
		flag = checkIfIATACorrect(code);
		if (!flag)
			puts("Wrong IATA input, enter exactly 3 UPPERCASE characters");
	}
}

char* rtrim(char *str, const char *seps) {
	int i;
	if (seps == NULL)
		seps = "\t\n\v\f\r ";
	i = strlen(str) - 1;
	while (i >= 0 && strchr(seps, str[i]) != NULL) {
		str[i] = '\0';
		i--;
	}
	return str;
}

char* ltrim(char *str, const char *seps) {
	size_t totrim;
	if (seps == NULL) {
		seps = "\t\n\v\f\r ";
	}
	totrim = strspn(str, seps);
	if (totrim > 0) {
		size_t len = strlen(str);
		if (totrim == len) {
			str[0] = '\0';
		} else {
			memmove(str, str + totrim, len + 1 - totrim);
		}
	}
	return str;
}

void trim(char *str, const char *seps) {
	ltrim(rtrim(str, seps), seps);
}
