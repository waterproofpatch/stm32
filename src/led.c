#include "stm32f4.h"
#include "gpio.h"
#include "led.h"

/*
 * Set or reset the state of a GPIO pin. This is done
 * using the BSRRL/BSRRH registers which effectively do
 * a read/modify/write to change the bits.
 */
void set_led(uint32_t led, uint8_t state)
{
    if (state)
    {
        GPIOD->BSRRL = led;
    }
    else
    {
        GPIOD->BSRRH = led;
    }
}
