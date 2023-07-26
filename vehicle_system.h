/*
 * vehicle_system.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Osama Khaled Gamal
 */

#ifndef VEHICLE_SYSTEM_H_
#define VEHICLE_SYSTEM_H_

#include <stdbool.h>


//Defines
/**************************************************************
 *
 * You can change the values of the defines to change the values that you want
 * to start the compiling process with before getting any input from the user
 *
 * ***********************************************************/
#define WITH_ENGINE_TEMP_CONTROLLER 1
#define INITAL_SPEED 0
#define INITIAL_ROOM_TEMPERATURE 0
#define INITIAL_ENGINE_TEMPERATURE 0

// Global variables
extern bool shouldTerminate;
extern int Speed;
extern int Roomtemp;
extern int Enginetemp;

typedef enum {
    OFF,
    ON
} State;

extern State AC;
extern State Engine;
extern State ET;

// Function prototypes

/********************************************************************************************************************************
 *
 * Function : optionzero()
 * Return type : Void
 * Parameters : Void
 * This function display the main menu of the vehicle control system where it has 3 options
 * a:proceeds to optionone menu
 * b:turn off the engine
 * c:Quit the system ( terminating the program )
 *
 * *******************************************************************************************************************************/

void optionzero(void);


/********************************************************************************************************************************
 *
 * Function : optionone()
 * Return type : Void
 * Parameters : Void
 * The optionone function is a menu-driven function that provides various options for the user to interact with the vehicle system when the engine is turned on.
 * It allows the user to control different aspects of the system, such as turning off the engine, setting the traffic light color (which affects the vehicle's speed),
 * adjusting the room temperature, and controlling the engine temperature.
 *
 *	It sets the state of the engine (variable Engine) to ON, indicating that the engine is running.
 *
 *
 *	It enters a while loop to continuously present the user with a menu of options until the user decides to turn off the engine and return to the main menu (optionzero) by choosing the appropriate option.
 *
 *	Within the while loop, it presents the following options to the user:
 *	a. Turn off the engine (return to optionzero).
 *	b. Set the traffic light color (which affects the vehicle's speed). The user can choose from different options to set the speed to a specific value (100km/hr, 30km/hr, or 0km/hr).
 *	c. Set the room temperature (Temperature Sensor).
 *	d. Set the engine temperature (Engine Temperature Sensor).
 *
 * *******************************************************************************************************************************/


void optionone(void);


/********************************************************************************************************************************
 *
 * Function : optiontwo()
 * Return type : Void
 * Parameters : Void
 *	It sets the state of the engine (variable Engine) to OFF, indicating that the engine is turned off.
 *	It prints a message notifying the user that the vehicle engine has been turned off.
 *	It returns to the optionzero function, which is the main menu of the system, allowing the user to choose other options or quit the system.
 *
 * *******************************************************************************************************************************/


void optiontwo(void);


/********************************************************************************************************************************
 *
 * Function : print()
 * Return type : Void
 * Parameters : Void
 * This function display the current status of the vehicle control system where it is used at any-time to provide a complete overview
 * of the current status of the system making it easier to monitor and control the system..
 *  It prints whether the engine is ON or OFF.
 *	It prints whether the AC (air conditioning) is ON or OFF.
 *	It prints the vehicle's current speed in kilometers per hour (Km/Hr).
 *	It prints the current room temperature.
 *	It prints whether the engine temperature controller is ON or OFF.
 *	It prints the current engine temperature.
 *
 * *******************************************************************************************************************************/


void print(void);




#endif /* VEHICLE_SYSTEM_H_ */
