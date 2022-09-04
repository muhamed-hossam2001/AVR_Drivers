/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_


/*you can select the direction of pins   0 for input  or 1  for output*/
/*

//for choose output or input
 INIT_OUTPUT 1
 INIT_INPUT  0

 */
#define PORTA_PIN0_DIR   INIT_INPUT
#define PORTA_PIN1_DIR   INIT_INPUT
#define PORTA_PIN2_DIR   INIT_INPUT
#define PORTA_PIN3_DIR   INIT_INPUT
#define PORTA_PIN4_DIR   INIT_OUTPUT
#define PORTA_PIN5_DIR   INIT_OUTPUT
#define PORTA_PIN6_DIR   INIT_OUTPUT
#define PORTA_PIN7_DIR   INIT_OUTPUT


#define PORTB_PIN0_DIR   INIT_OUTPUT
#define PORTB_PIN1_DIR   INIT_OUTPUT
#define PORTB_PIN2_DIR   INIT_OUTPUT
#define PORTB_PIN3_DIR   INIT_OUTPUT
#define PORTB_PIN4_DIR   INIT_OUTPUT
#define PORTB_PIN5_DIR   INIT_OUTPUT
#define PORTB_PIN6_DIR   INIT_OUTPUT
#define PORTB_PIN7_DIR   INIT_OUTPUT


#define PORTC_PIN0_DIR   INIT_OUTPUT
#define PORTC_PIN1_DIR   INIT_OUTPUT
#define PORTC_PIN2_DIR   INIT_OUTPUT
#define PORTC_PIN3_DIR   INIT_OUTPUT
#define PORTC_PIN4_DIR   INIT_OUTPUT
#define PORTC_PIN5_DIR   INIT_OUTPUT
#define PORTC_PIN6_DIR   INIT_OUTPUT
#define PORTC_PIN7_DIR   INIT_OUTPUT


#define PORTD_PIN0_DIR    INIT_OUTPUT
#define PORTD_PIN1_DIR    INIT_OUTPUT
#define PORTD_PIN2_DIR    INIT_INPUT
#define PORTD_PIN3_DIR    INIT_OUTPUT
#define PORTD_PIN4_DIR    INIT_OUTPUT
#define PORTD_PIN5_DIR    INIT_OUTPUT
#define PORTD_PIN6_DIR    INIT_INPUT
#define PORTD_PIN7_DIR    INIT_OUTPUT

/*you can select the Initial Value of pins 0 or 1 */

/*
 * //for output Configuration
 INIT_LOW  0
 INIT_HIGH 1

//for input Configuration
 INIT_PULL_UP   1
 INIT_NORMAL_IN 0
 *
 */
#define PORTA_PIN0_INITAIL_VALUE  INIT_PULL_UP
#define PORTA_PIN1_INITAIL_VALUE  INIT_NORMAL_IN
#define PORTA_PIN2_INITAIL_VALUE  INIT_NORMAL_IN
#define PORTA_PIN3_INITAIL_VALUE  INIT_NORMAL_IN
#define PORTA_PIN4_INITAIL_VALUE  INIT_LOW
#define PORTA_PIN5_INITAIL_VALUE  INIT_LOW
#define PORTA_PIN6_INITAIL_VALUE  INIT_LOW
#define PORTA_PIN7_INITAIL_VALUE  INIT_LOW


#define PORTB_PIN0_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN1_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN2_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN3_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN4_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN5_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN6_INITAIL_VALUE  INIT_LOW
#define PORTB_PIN7_INITAIL_VALUE  INIT_LOW


#define PORTC_PIN0_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN1_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN2_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN3_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN4_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN5_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN6_INITAIL_VALUE  INIT_LOW
#define PORTC_PIN7_INITAIL_VALUE  INIT_LOW


#define PORTD_PIN0_INITAIL_VALUE  INIT_LOW
#define PORTD_PIN1_INITAIL_VALUE  INIT_LOW
#define PORTD_PIN2_INITAIL_VALUE  INIT_NORMAL_IN
#define PORTD_PIN3_INITAIL_VALUE  INIT_LOW
#define PORTD_PIN4_INITAIL_VALUE  INIT_LOW
#define PORTD_PIN5_INITAIL_VALUE  INIT_LOW
#define PORTD_PIN6_INITAIL_VALUE  INIT_NORMAL_IN
#define PORTD_PIN7_INITAIL_VALUE  INIT_LOW


#endif /* PORT_CONFIG_H_ */
