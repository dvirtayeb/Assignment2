#include <stdio.h>
#include "ControllerMenu.h"

void menu(AirportManager *airportM,Airline* airline)
{
	int choose = 0;
	do {
		do {
			puts("Please choose one of the following option:\n"
						"1. ADD flight\n"
						"2. ADD Airport\n"
						"3. Print details about airline\n"
						"4. Print details about airport\n"
						"5. Print amount airports between two airports\n"
						"6. Exit");
			puts("Choose a number: ");
			scanf("%d", &choose);
			//getchar();
			if(choose <= 0 || choose > 6)
				puts("Please choose again, ");
		} while (choose <= 0 || choose > 6);

		switch (choose) {
		case ADD_FLIGHT_TO_AIRLINE:
			puts("You chose to add Flight:\n"
					"--------------------------\n");
			userAddFlightToAirline(airline);
			break;
		case ADD_AIRPORT_TO_MANAGER:
			puts("You chose to add Airport:\n"
								"--------------------------\n");
			userAddAirportToManager(airportM);
			break;
		case PRINT_DETAILS_ABOUT_AIRLINE:
			puts("You chose to get details about airport:\n"
					"--------------------------\n");
			printAirline(airline);
			break;
		case PRINT_DETAILS_ABOUT_AIRPORT_MANAGER:
			puts("You chose to get details about airline:\n"
					"--------------------------\n");
			printAirportManager(airportM);
			break;
		case PRINT_AMOUNT_FLIGHT_BETWEEN_AIRPORTS:
			puts("You chose to get amount flight between two airports:\n"
					"--------------------------\n");
			getAndPrintFlightsBetween2Airports(airline);
			break;
		case EXIT:
			freeAirportManager(airportM);
			freeAirline(airline);
			puts("You chose to exit, Bye Bye.");
			break;
		default:
			puts("Something went wrong.");
			break;
		}
	} while (choose != EXIT);
}
