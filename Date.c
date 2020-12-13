#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "Date.h"
#define MAX_STR 255
#define DATE_LENGTH 10


void userAddDate(Date* date,char* str){ // Check if the Date Format right and add the date
	int day,month,year;




	addDate(date,day,month,year);
}


void addDate(Date *date, int day, int month, int year) { // Insert the date
	int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month > 0 && month <= 12) {
		date->month = month;
		if (day > 0 && day <= monthLength[date->month]) {
			date->day = day;
			if (year > 2000 && year <= 2021){
				date->year = year;
			}else {
				setDefault(date);
			}
		} else
			setDefault(date);
	} else
		setDefault(date);
	date->dateStr = toString(date);
}
char* toString(Date *date) {
	char* str = (char*)malloc(DATE_LENGTH*sizeof(char)); //
	int dayFirstDig,daySecDig,monthFirstDig,monthSecDig,years;
	dayFirstDig=date->day/10;
	daySecDig=date->day%10;
	monthFirstDig=date->month/10;
	monthSecDig=date->month%10;
	years=date->year;
	sprintf(str, "%d%d/%d%d/%d", dayFirstDig,daySecDig,monthFirstDig,monthSecDig,years);

	return str;
}
void setDefault(Date *date){
	date->day=1;
	date->month=1;
	date->year=2021;
}

