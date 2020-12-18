#ifndef STRINGFUNCHELPER_H_
#define STRINGFUNCHELPER_H_

#define IATA_SIZE 4
#define MAX_STR 255

void fixWord(char* word, char* tempNameAirport, int counter, char* textResult, int countWords);
void changeDoubleSumOfLetters(char* word, int lenWord);
int counterwords(char* nameAirport);
void fixLastWord(int isEvenAmountWord, int countWords, char* word, char* textResult);
int checkIfIATACorrect(char IATA[IATA_SIZE]);
char *rtrim(char *str, const char *seps);
char *ltrim(char *str, const char *seps);
void trim(char *str, const char *seps);
#endif /* STRINGFUNCHELPER_H_ */
