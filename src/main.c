/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "rgb_led.h"
#include "potenciometro.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LED_TOGGLE_DELAY_MS 1500

/*****************************************
 * Main Function
 *****************************************/

uint16_t pot[POT_AMOUNT] = {0};

int main(void) {
    mcu_init();
    rgb_led_init();
    potenciometro_init();

    for (;;) {
        pot[RED] = get_color_value(RED);
        pot[GREEN] = get_color_value(GREEN);
        pot[BLUE] = get_color_value(BLUE);
        rgb_led_set(get_color_value(RED), get_color_value(GREEN), get_color_value(BLUE));
        mcu_sleep(100);
    }

    // rgb_led_set(0,0,0);
    // uint8_t r = 0;
    // uint8_t g = 0;
    // uint8_t b = 0;

    // for (;;) {
    // for (r = 0; r < 100; r++) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }
    // for (r = 100; r > 0; r--) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }

    // for (g = 0; g < 100; g++) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }
    // for (g = 100; g > 0; g--) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }

    // for (b = 0; b < 100; b++) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }
    // for (b = 100; b > 0; b--) {
    // rgb_led_set(r,g,b);
    // mcu_sleep(10);
    // }

    // led_toggle();
    //// mcu_sleep(LED_TOGGLE_DELAY_MS);
    // }
}
