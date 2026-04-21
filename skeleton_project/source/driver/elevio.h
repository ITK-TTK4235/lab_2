#pragma once

/**
 * @file elevio.h
 * @brief Elevator I/O driver interface.
 *
 * Provides functions for communicating with the elevator hardware server
 * over a TCP socket. Call elevio_init() before any other function.
 */

 /** @brief Number of floors in the elevator system. */
#define N_FLOORS 4

/**
 * @brief Direction commands for the elevator motor.
 */
typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;

/** @brief Number of button types per floor. */
#define N_BUTTONS 3

/**
 * @brief Types of buttons available in the elevator system.
 */
typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;

/**
 * @brief Initializes the elevator I/O driver.
 *
 * Reads connection parameters from the config file, establishes a TCP
 * connection to the elevator server, and sends an initialization message.
 * Must be called before any other elevio function.
 */
void elevio_init(void);

/**
 * @brief Sets the motor direction.
 *
 * @param dirn Desired motor direction (DIRN_UP, DIRN_DOWN, or DIRN_STOP).
 */
void elevio_motorDirection(MotorDirection dirn);

/**
 * @brief Sets a button lamp on or off.
 *
 * @param floor  Floor index (0 to N_FLOORS-1).
 * @param button Button type to control.
 * @param value  1 to turn the lamp on, 0 to turn it off.
 */
void elevio_buttonLamp(int floor, ButtonType button, int value);

/**
 * @brief Sets the floor indicator light.
 *
 * @param floor Floor index to display (0 to N_FLOORS-1).
 */
void elevio_floorIndicator(int floor);

/**
 * @brief Sets the door open lamp on or off.
 *
 * @param value 1 to turn the lamp on, 0 to turn it off.
 */
void elevio_doorOpenLamp(int value);

/**
 * @brief Sets the stop lamp on or off.
 *
 * @param value 1 to turn the lamp on, 0 to turn it off.
 */
void elevio_stopLamp(int value);

/**
 * @brief Reads the state of a call button.
 *
 * @param floor  Floor index (0 to N_FLOORS-1).
 * @param button Button type to read.
 * @return 1 if the button is currently pressed, 0 otherwise.
 */
int elevio_callButton(int floor, ButtonType button);

/**
 * @brief Reads the floor sensor.
 *
 * @return The current floor index (0 to N_FLOORS-1) if the elevator is
 *         at a floor, or -1 if it is between floors.
 */
int elevio_floorSensor(void);

/**
 * @brief Reads the stop button state.
 *
 * @return 1 if the stop button is pressed, 0 otherwise.
 */
int elevio_stopButton(void);

/**
 * @brief Reads the obstruction switch state.
 *
 * @return 1 if the obstruction switch is active, 0 otherwise.
 */
int elevio_obstruction(void);

