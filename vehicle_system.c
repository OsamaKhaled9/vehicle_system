/*
 * vehicle_system.c
 *
 *  Created on: Jul 21, 2023
 *      Author: lenovo
 */
#include "vehicle_system.h"
#include <stdio.h>

// Global variables
bool shouldTerminate = false;
int Speed = INITAL_SPEED;
int Roomtemp = INITIAL_ROOM_TEMPERATURE;
int Enginetemp = INITIAL_ENGINE_TEMPERATURE;

State AC = OFF;
State Engine = OFF; // Initialize the variable to OFF
State ET = OFF;

// Function to print the current status of the vehicle system
void print()
{
	printf("The engine is %s\n", (Engine == ON ? "ON" : "OFF"));
	fflush(stdout);fflush(stdin);
	printf("The AC is %s\n", (AC == ON ? "ON" : "OFF"));
	fflush(stdout);fflush(stdin);
	printf("Vehicle speed is %d Km/Hr\n", Speed);
	fflush(stdout);fflush(stdin);
	printf("Room Temperature is %d \n", Roomtemp);
	fflush(stdout);fflush(stdin);

#if (WITH_ENGINE_TEMP_CONTROLLER)
	printf("The Engine Temperature controller is %s\n", (ET == ON ? "ON" : "OFF"));
	fflush(stdout);fflush(stdin);
	printf("Engine Temperature is %d\n", Enginetemp);
	fflush(stdout);fflush(stdin);
#endif
}

// Main menu function

void optionzero(void)
{
    char input;
    while (!shouldTerminate) // Use the flag to control the loop
    {
        printf("a. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n\n");
        printf("Enter your choice: ");
        fflush(stdout);
        scanf(" %c", &input);
        getchar(); // Consume the newline character from the input buffer

        switch (input)
        {
        case 'a':
            optionone();
            break;
        case 'b':
            optiontwo();
            break;
        case 'c':
            shouldTerminate = true; // Set the flag to true to terminate the program
            break;
        default:
            printf("Invalid option. Please choose a, b, or c.\n");
            break;
        }
    }
}


// Function to handle options when the engine is turned on
void optionone(void)
{
	char input;
	Engine = ON;
	while (1)
	{
		printf("a. Turn off the engine\n");
		fflush(stdout);fflush(stdin);
		printf("b. Set the traffic light color.\n");
		fflush(stdout);fflush(stdin);
		printf("c. Set the room temperature (Temperature Sensor)\n");
		fflush(stdout);fflush(stdin);
#if (WITH_ENGINE_TEMP_CONTROLLER)
		printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
		fflush(stdout);fflush(stdin);
#endif
		scanf(" %c", &input);
		getchar();
		switch (input)
		{
		case 'a':
			return optionzero(); // Exit the current function (optionone(), returning to the caller function optionzero ()).
		case 'b':
			printf("g. for speed to equal 100km/hr \n");
			fflush(stdout);fflush(stdin);
			printf("o. for speed to equal 30km/hr \n");
			fflush(stdout);fflush(stdin);
			printf("r. for speed to equal 0km/hr \n");
			fflush(stdout);fflush(stdin);

			scanf(" %c", &input);
			getchar();
			switch (input)
			{
			case 'g':
				Speed = 100;
				Engine = ON;
				print();
				return optionone();
			case 'o':
				Speed = 30;
				Engine = ON;
				AC= ON;
				Roomtemp = (Roomtemp*(1.25)) +1 ;
#if (WITH_ENGINE_TEMP_CONTROLLER)
				ET = ON;
				Enginetemp = (Enginetemp*(1.25)) +1 ;
#endif
				print();
				return optionone();
			case 'r':
				Speed = 0;
				Engine = ON;
				print();
				return optionone();
			default:
				printf("Invalid option. Please choose g, o, or r.\n");
				break;
			}

			// When exiting the 'while' loop, go back to the main menu (optionone()).
			break;
			case 'c':

				printf("Enter the required room temp:");
				fflush(stdout); fflush(stdin);
				scanf(" %d", &Roomtemp);
				getchar();

				if (Roomtemp < 30)
				{
					AC = ON;
					Roomtemp = 20;
					print();
					return optionone();

				}
				else if (Roomtemp > 30)
				{
					AC = ON;
					Roomtemp = 20;
					print();
					return optionone();

				}
				else
				{
					AC = OFF;
					print();
					return optionone();
				}

			case 'd':
			#if (WITH_ENGINE_TEMP_CONTROLLER)
				printf("Enter the required Engine temp:");
				fflush(stdout);fflush(stdin);
				scanf(" %d", &Enginetemp);
				getchar();

				if (Enginetemp >= 0 && Enginetemp <= 99)
				{
					ET = ON;
					Enginetemp = 125;
					print();
					return optionone();

				}
				else if (Enginetemp >= 100 && Enginetemp <= 150)
				{
					ET = OFF;
					print();
					return optionone();

				}
				else if (Enginetemp >= 151)
				{
					ET = ON;
					Enginetemp = 125;
					print();
					return optionone();

				}
#endif


		}

	}
}


// Function to turn off the vehicle engine

void optiontwo()
{
	Engine = OFF;
	printf("Turn off the vehicle engine\n");
	fflush(stdout);fflush(stdin);
	optionzero();
}


