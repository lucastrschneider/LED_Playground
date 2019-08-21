#include <stdbool.h>
#include <stdint.h>

#include "potenciometro.h"

#include "adc.h"
#include "dma.h"
#include "utils.h"

#define ADC_BUFFER_SIZE 360

#define ADC1_CHANNELS 3

static uint32_t potenciometro[POT_AMOUNT];
static uint32_t potenciometro_aux[POT_AMOUNT];

static uint32_t adc1_buffer[ADC_BUFFER_SIZE];

void potenciometro_init(void) {
    MX_DMA_Init();
    MX_ADC_Init();

    HAL_ADC_Start_DMA(&hadc, adc1_buffer, ADC_BUFFER_SIZE);
}

uint16_t get_color_value(pot_color_t color) {
    uint16_t reading = map(potenciometro[(int) color], 0, 4095, 0, 1000);

    if (reading < 100) {
        reading = 0;
    }

    return reading;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
    for (int i = 0; i < (ADC_BUFFER_SIZE / ADC1_CHANNELS); i++) {
        for (int j = 0; j < ADC1_CHANNELS; j++) {
            potenciometro_aux[j] += adc1_buffer[ADC1_CHANNELS * i + j];
        }
    }

    for (int i = 0; i < ADC1_CHANNELS; i++) {
        potenciometro_aux[i] /= (ADC_BUFFER_SIZE / ADC1_CHANNELS);
        potenciometro[i] = potenciometro_aux[i];
    }
}
