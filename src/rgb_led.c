/**
 * @file rgb_led.c
 *
 * @brief RGB LED control
 */
#include "rgb_led.h"

#include "tim.h"
#include "utils.h"

#define TIM_PERIOD 1000

void rgb_led_init(void) {
    MX_TIM2_Init();

    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
}

void rgb_led_set(uint16_t red, uint16_t green, uint16_t blue) {
    red = constrain(red, 0, 1000);
    green = constrain(green, 0, 1000);
    blue = constrain(blue, 0, 1000);

    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, blue);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, green);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, red);

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
}
