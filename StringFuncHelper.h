

#ifndef STRINGFUNCHELPER_H_
#define STRINGFUNCHELPER_H_

#define IATASIZE 4

void fixWord(char* word, char* tempNameAirport, int counter, char* textResult, int countWords);
void changeDoubleSumOfLetters(char* word, int lenWord);
int counterwords(char* nameAirport);
void fixLastWord(int isEvenAmountWord, int countWords, char* word, char* textResult);
int checkIfIATACorrect(char IATA[IATASIZE]);
char *rtrim(char *str, const char *seps);
char *ltrim(char *str, const char *seps);
void trim(char *str, const char *seps);
#endif /* STRINGFUNCHELPER_H_ */
