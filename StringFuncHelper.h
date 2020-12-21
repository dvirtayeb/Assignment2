#ifndef STRINGFUNCHELPER_H_
#define STRINGFUNCHELPER_H_

#define IATA_SIZE 4
#define MAX_STR 255

void fixWord(char *word, char *tempNameAirport, const int counter,
		char *textResult, const int countWords);
void changeDoubleSumOfLetters(char *word, const int lenWord);
int counterwords(char *nameAirport);
void fixLastWord(const int isEvenAmountWord, const int countWords, char *word,
		char *textResult);
int checkIfIATACorrect(const char IATA[IATA_SIZE]);
void scanIATACode(char *code);
char* rtrim(char *str, const char *seps);
char* ltrim(char *str, const char *seps);
void trim(char *str, const char *seps);
#endif /* STRINGFUNCHELPER_H_ */
