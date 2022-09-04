/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*if we don't pressed any button*/
#define TR_NOT_PRESSED 0xff

/*the values returned when pressed*/
#define ARRAY_VALUE  { {'1','2','3','4'},{'5','6','7','8'},{'9','i','d','0'},{'r','0','0','0'} }

/*The port will be connected to KEYPAD*/
#define KEYPAD_PORT PORTD

/*the configuration of columns and rows*/
#define KEYPAD_COULUMN0 PIN0
#define KEYPAD_COULUMN1 PIN1
#define KEYPAD_COULUMN2 PIN2
#define KEYPAD_COULUMN3 PIN3

#define KEYPAD_ROW0 PIN4
#define KEYPAD_ROW1 PIN5
#define KEYPAD_ROW2 PIN6
#define KEYPAD_ROW3 PIN7




#endif /* KEYPAD_CONFIG_H_ */
