#ifndef DATE_H_
#define DATE_H_

#define DATE_LENGTH 10
#define DAY_O_MONTH_LEN 2
#define YEAR_LEN 4

typedef struct {
	int day;
	int month;
	int year;
	char* dateStr;
}Date;

void addDate(Date* date);
char* toString(Date* date, char* str);
void setDefault(Date *date);
void userAddDate(Date* date,char* str);
int checkDigit(Date* date, char* temp, int* counter,int* flag);
void insertIntegerValues(Date* date, char* temp, int* counter);
void printDate(Date* date);

#endif /* DATE_H_ */
