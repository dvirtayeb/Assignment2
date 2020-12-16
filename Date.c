#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "Date.h"
#define MAX_STR 255
#define DATE_LENGTH 10
#define DAY_O_MONTH_LEN 2
#define YEAR_LEN 4


void userAddDate(Date* date,char* str){ // Check if the Date Format right and add the date -> Maimon
	int* day = (int*)malloc(sizeof(int));
	int* month = (int*)malloc(sizeof(int));
	int* year = (int*)malloc(sizeof(int));
	int* flag = (int*)malloc(sizeof(int)); // boolean-date format
	int* counter = (int*)malloc(sizeof(int)); // Counter[day]=0 ,Counter[month]=1, Counter[year] =2
	int lenDate = strlen(str);
	char* temp;
	char* strTemp = strdup(str);
	char* delimiter = "/";
	if(lenDate != DATE_LENGTH){
		puts("you did not insert date properly.");
//		free6Values(day,month,year,flag,counter,strTemp);
		return;
	}
	temp = strtok(strTemp, delimiter);
	while(temp != NULL && *(flag) ==0){
		checkDigit(temp, day, month, year, counter, flag);
		temp = strtok(NULL,delimiter);
	}
	if(*(flag) != 1)
		addDate(date,day,month,year);
	else{
		puts("you did not insert date properly.");
//		free6Values(day,month,year,flag,counter,strTemp);
		return;
	}
}

void checkDigit(char* temp,int* day, int* month, int* year, int* counter, int* flag){
	int lenTemp = strlen(temp);
	for (int i = 0; i < lenTemp; ++i) {
		if(lenTemp == DAY_O_MONTH_LEN){ // check for day/month
			if(!isdigit(temp[i])){
				*(flag) =1;
				return;
			}
		}
		else if(lenTemp == YEAR_LEN && *counter > 1){ // check for year
			if(!isdigit(temp[i])){
				*(flag) =1;
				return;
			}
		}
		else{
			*(flag) =1;
			return;
		}
	}
	insertCorrectInteger(temp, day, month, year, counter);
}

void insertCorrectInteger(char* temp, int* day, int* month, int* year,int* counter){
	if(*counter == 0){
				*day = atoi(temp);
				(*counter)++;
			}
			else if(*counter == 1){
				*month = atoi(temp);
				(*counter)++;
			}
			else if(*counter > 1){
				*year = atoi(temp);
			}
			else{
				return;
			}
}

void addDate(Date *date, int* day, int* month, int* year) { // Insert the date
	int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (*month > 0 && *month <= 12) {
		date->month = *month;
		if (*day > 0 && *day <= monthLength[date->month -1]) {
			date->day = *day;
			if (*year > 999 && *year <= 2050){
				date->year = *year;
			}else {
				setDefault(date); // 01/01/2021
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

	return str; // ----- remember to free it
}

void setDefault(Date *date){
	date->day=1;
	date->month=1;
	date->year=2021;
}

void freeDateValues(void* val1,void* val2, void* val3,void* val4, void* val5,void* val6){
	free(val1);
	free(val2);
	free(val3);
	free(val4);
	free(val5);
	free(val6);
}


