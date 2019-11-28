/*
 * drvLED.h
 *
 *  Created on: 7 лист. 2019 р.
 *      Author: SilkT
 */

#ifndef DRVLED_H_
#define DRVLED_H_

#include "main.h"

typedef struct
{ //declare structure type for LEDs containing Ports and Pins for each LED
    GPIO_TypeDef *LED_port;
    uint16_t LED_pin;
} led_t;

typedef enum
{ //declare a special type for LEDs
    LED_Blue,
    LED_Red,
    LED_Orange,
    LED_Green,
    LED_Count
} ledlist_t;

void drvLED_on(ledlist_t LED_num); // turn on the LED according to it's name

void drvLED_off(ledlist_t LED_num); // turn off the LED according to it's name

#endif /* DRVLED_H_ */
