#include <stdio.h>
#include "ControllerMenu.h"

void menu(AirportManager *airportM)
{
	int choose = 0;
	do {
		do {
			puts("Please choose one of the following option:\n"
						"1. ADD flight\n"
						"2. ADD Airport\n"
						"3. Print details about airport\n"
						"4. Print details about airline\n"
						"5. Print amount airports between two airports\n"
						"6. Exit");
			puts("Choose a number: ");
			scanf("%d", &choose);
			if(choose <= 0 || choose > 6)
				puts("Please choose again, ");
		} while (choose <= 0 || choose > 6);

		switch (choose) {
		case ADD_FLIGHT_TO_AIRLINE:
			puts("You choose to add Flight:\n"
					"--------------------------\n");
			//
			//
			puts("Please choose again, if you want to exit press 6");
			break;
		case ADD_AIRPORT_TO_AIRLINE:
			puts("You choose to add Airport:\n"
								"--------------------------\n");
			//userAddAirport(airportM);
			puts("Please choose again, if you want to exit press 6");
			break;
		case PRINT_DETAILS_ABOUT_AIRPORT:
			puts("You choose to get details about airport:\n"
					"--------------------------\n");
			//
			//
			puts("Please choose again, if you want to exit press 6");
			break;
		case PRINT_DETAILS_ABOUT_AIRLINE:
			puts("You choose to get details about airline:\n"
					"--------------------------\n");
			//
			//
			puts("Please choose again, if you want to exit press 6");
			break;
		case PRINT_AMOUNT_FLIGHT_BETWEEN_AIRPORTS:
			puts("You choose to get amount flight between two airports:\n"
					"--------------------------\n");
			//
			//
			puts("Please choose again, if you want to exit press 6");
			break;
		case EXIT:
			// -----------> free all
			// -----------> free all
			puts("You choose to exit, Bye Bye.");
			break;
		default:
			puts("Something went wrong.");
			break;
		}
	} while (choose != EXIT);
}
