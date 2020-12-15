/*
 * Date.h
 *
 *  Created on: 5 Dec 2020
 *      Author: dvirtayeb
 */

#ifndef DATE_H_
#define DATE_H_

typedef struct {
	int day;
	int month;
	int year;
	char* dateStr;
}Date;

void addDate(Date* date,int* day, int* month, int* year);
char* toString(Date* date);
void setDefault(Date *date);
void userAddDate(Date* date,char* str);
void checkDigit(char* temp, int* day, int* month, int* year, int* counter,int* flag);
void insertCorrectInteger(char* temp, int* day, int* month, int* year,int* counter);
void freeDateValues(void* val1,void* val2, void* val3,void* val4, void* val5,void* val6);

#endif /* DATE_H_ */
