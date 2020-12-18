#ifndef AIRPORT_H_
#define AIRPORT_H_

#define SIZE 4

typedef struct {
	char* nameAirport;
	char* nameState;
	char IATACode[SIZE];
}Airport;
void initAirport(Airport* newAirport);
void addAirportName(Airport* newAirport);
void addAirportState(Airport* newAirport);
void addIATACode(Airport* newAirport);
int isEqualAirports(Airport* pAirport1, Airport* pAriport2);
int checkCodeIATAisEqual(Airport* pAirport,char IATA[SIZE]);
void createCodeHelper(Airport* newAirport, char* code);
void fixNameAirport(char* nameAirport);
void printAirport(Airport *airport);
void freeAirport(Airport* newAirport);
#endif /* AIRPORT_H_ */
