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

#endif /* DATE_H_ */
