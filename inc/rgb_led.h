/**
 * @file rgb_led.h
 *
 * @brief RGB LED control
 */

#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#include <stdint.h>

/*****************************************
 * Public Function Prototypes
 *****************************************/

void rgb_led_init(void);

void rgb_led_set(uint16_t red, uint16_t green, uint16_t blue);

#endif // __MCU_H__
