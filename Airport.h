/*
 * Airport.h
 *
 *  Created on: 30 Nov 2020
 *      Author: dvirtayeb
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_

#define SIZE 3

typedef struct {
	char* nameAirport;
	char* nameState;
	char nameCode[SIZE];
}Airport;

int isEqualAirports(Airport* pAirport1, Airport* pAriport2);
int checkCodeIATA(Airport* pAirport,char* code);


#endif /* AIRPORT_H_ */
