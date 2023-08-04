# vehicle_system
The Vehicle Control System project is a C programming project that simulates a vehicle's sensor readings and allows the user to control various aspects of the car. The user is prompted to choose from three options: turn on the vehicle engine, turn off the vehicle engine, or quit the system. If the user decides to turn off the engine, they will again be prompted to choose from the same three options. The design responds to traffic light colours and simulates the vehicle's speed and temperature. Additionally, a bonus requirement is to create a preprocessor directive that compiles and runs specific code related to the engine temperature controller.
/*************************************************************************************************************************************************************
*
*                                                                  Project Manual
*  
************************************************************************************************************************************************************/

# Vehicle Control System

## Description

This is a vehicle control system that simulates various functionalities of a vehicle and its sensors. The system allows the user to interact with different aspects of the vehicle, such as engine control, sensor readings, and temperature control. It provides options for turning the engine on/off, setting sensor values, and monitoring the vehicle's state.

## Features

- Turn on the vehicle engine.
- Turn off the vehicle engine.
- Quit the system.
- Simulate vehicle sensor readings.
- Control engine temperature.
- Control room temperature (AC).
- Set vehicle speed based on traffic light colour.
- Display current vehicle state.

## Instructions

1. Run the program.
2. Choose from the following options:
   a. Turn on the vehicle engine
   b. Turn off the vehicle engine
   c. Quit the system

3. If you choose to quit the system, the program will exit.

4. If you choose to turn off the vehicle engine, you will be prompted again with the options mentioned in Step 2.

5. After each choice, the current system state will be displayed.

6. If you choose to turn on the vehicle engine, you will enter the "Sensors Set Menu":

   a. Turn off the engine
   b. Set the traffic light colour
   c. Set the room temperature (Temperature Sensor)
   d. Set the engine temperature (Engine Temperature Sensor)

7. While the engine is ON, the "Sensors Set Menu" will be continuously displayed, waiting for your input.

8. Based on your inputs in the "Sensors Set Menu":

   a. Traffic light data:
      - If the traffic light is 'G', the vehicle speed is set to 100 km/hr
      - If the traffic light is 'O', the vehicle speed is set to 30 km/hr
      - If the traffic light is 'R', the vehicle speed is set to 0 km/hr

   b. Room temperature data:
      - If temperature < 10 or > 30, AC is turned ON and temperature is set to 20
      - If the temperature is within range, AC is turned OFF

   c. Engine temperature data:
      - If the temperature < 100 or > 150, the Engine Temperature Controller is turned ON and the temperature is set to 125
      - If the temperature is within range, the Engine Temperature Controller is turned OFF

   d. If the vehicle speed is 30 km/hr:
      - AC is turned ON if it was OFF, and room temperature is adjusted
      - Engine Temperature Controller is turned ON if it was OFF, and engine temperature is adjusted

9. The current vehicle state is displayed, including:
   - Engine state: ON/OFF
   - AC: ON/OFF
   - Vehicle speed
   - Room temperature
   - Engine Temperature Controller state
   - Engine temperature

10. If you choose to turn off the engine in the "Sensors Set Menu", you will be taken back to the options mentioned in Step 2.

## Usage

1. Compile and run the code.
2. Follow the on-screen instructions to interact with the vehicle control system.
3. Use the input prompts to set sensor values and control the vehicle's functionalities.

## Note

- Define `WITH_ENGINE_TEMP_CONTROLLER` as 1 to include the code related to the "Engine Temperature Controller," or set it to 0 to exclude that code.
- This README provides an overview of the system's features and usage. For detailed implementation, refer to the source code.
