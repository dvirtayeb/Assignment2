#ifndef DATE_H_
#define DATE_H_

#define DATE_LENGTH 10
#define DAY_O_MONTH_LEN 2
#define YEAR_LEN 4

typedef struct {
	int day;
	int month;
	int year;
	char *dateStr;
} Date;

void addDate(Date *date);
void setDefault(Date *date);
int userAddDate(Date *date, char *str);
int checkDigit(const char *temp, const int *counter);
void insertIntegerValues(Date *date, const char *temp, int *counter);
void printDate(const Date *date);

#endif /* DATE_H_ */
