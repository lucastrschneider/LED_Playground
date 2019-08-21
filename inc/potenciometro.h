#ifndef __POTENCIOMETRO_H__
#define __POTENCIOMETRO_H__

#include <stdint.h>

#define POT_AMOUNT 3

typedef enum _pot_color {
    RED,
    GREEN,
    BLUE,
} pot_color_t;

void potenciometro_init(void);

uint16_t get_color_value(pot_color_t color);

#endif
