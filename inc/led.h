#ifndef _LED_H
#define _LED_H
#include <stdint.h>

/**
 * @brief Set the led object
 *
 * @param led to set
 * @param state on or off
 */
void set_led(uint32_t led, uint8_t state);

#endif