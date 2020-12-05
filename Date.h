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
}Date;

void addDate(int day, int month, int year);

#endif /* DATE_H_ */
