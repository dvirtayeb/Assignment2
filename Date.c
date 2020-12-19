#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "Date.h"
#include "StringFuncHelper.h"


int userAddDate(Date* date, char* str)
{ // Check if the Date Format right and add the date
	int flag = 1;
	int counterValidDate = 0; // Counter[day]=0 ,Counter[month]=1, Counter[year] =2
	int lenDate = strlen(str);
	char* temp;
	char* strTemp = strdup(str);
	char* delimiter = "/";
	if(lenDate != DATE_LENGTH){
		puts("you did not insert date properly.");
		return 0;
	}
	temp = strtok(strTemp, delimiter);
	while(temp != NULL && flag ==1){
		flag = checkDigit(date, temp, &counterValidDate, &flag);
		if(!flag)
			break;
		insertIntegerValues(date, temp, &counterValidDate);
		temp = strtok(NULL,delimiter);
	}
	if(flag){
		addDate(date);
		date->dateStr = str;
	}
	else{
		puts("you did not insert date properly.");
		return 0;
	}
	return 1;
}

int checkDigit(Date* date, char* temp, int* counterValidDate, int* flag)
{
	int lenTemp = strlen(temp);
	for (int i = 0; i < lenTemp; ++i) {
		if(lenTemp == DAY_O_MONTH_LEN){ // check for day/month
			if(!isdigit(temp[i]))
				return 0;
		}
		else if(lenTemp == YEAR_LEN && *counterValidDate > 1){ // check for year
			if(!isdigit(temp[i]))
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

void insertIntegerValues(Date* date, char* temp, int* counterValidDate)
{
	if(*counterValidDate == 0){
		date->day = atoi(temp);
		(*counterValidDate)++;
	}
	else if(*counterValidDate == 1){
		date->month = atoi(temp);
		(*counterValidDate)++;
	}
	else if(*counterValidDate > 1){
		date->year = atoi(temp);
	}
	else{
		return;
	}
}

void addDate(Date *date) { // check if not valid insert default date
	int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date->month > 0 && date->month <= 12) {
		if (date->day > 0 && date->day <= monthLength[date->month -1]) {
			if (date->year > 999 && date->year <= 2050)
				return;
			else
				setDefault(date); // 01/01/2021
		}else
			setDefault(date);
	} else
		setDefault(date);
}

void setDefault(Date* date)
{
	date->day=1;
	date->month=1;
	date->year=2021;
	puts("You didn't insert correct date so we inserted a default date");
}
void printDate(Date* date)
{
	printf("Date: %d/%d/%d \n", date->day, date->month, date->year);
}


