#include <stdint.h>

#include "stm32f4.h"
#include "gpio.h"
#include "led.h"

// defines for [G]reeen, [O]range, [R]ed, and [B]lue LEDs
#define LED_G (uint32_t)(1 << 12)
#define LED_O (uint32_t)(1 << 13)
#define LED_R (uint32_t)(1 << 14)
#define LED_B (uint32_t)(1 << 15)

/**
 * @brief Main program
 *
 */
void main(void);

/**
 * @brief Start function, resolved by default
 *
 */
void _start(void)
{
    main();   // just get on with it.
}

void _exit(int f)
{
    while (1)
        ;   // spin forever
}

void main(void)
{
    uint8_t  red, blue, orange, green;
    uint32_t i, j;

    red    = 1;
    green  = 1;
    blue   = 0;
    orange = 0;

    /* set up GPIO pins for leds */

    // enable PD0-15
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // Configure PD12 - PD15 as "high speed" digital I/Os
    GPIOD->MODER |= (GPIO_MODER_MODER12_0 | GPIO_MODER_MODER13_0 |
                     GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0);
    GPIOD->OTYPER &= ~(GPIO_OTYPER_OT_12 | GPIO_OTYPER_OT_13 |
                       GPIO_OTYPER_OT_14 | GPIO_OTYPER_OT_15);
    GPIOD->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR12 | GPIO_OSPEEDER_OSPEEDR13 |
                       GPIO_OSPEEDER_OSPEEDR14 | GPIO_OSPEEDER_OSPEEDR15);
    GPIOD->PUPDR &= ~(GPIO_PUPDR_PUPDR12 | GPIO_PUPDR_PUPDR13 |
                      GPIO_PUPDR_PUPDR14 | GPIO_PUPDR_PUPDR15);

    while (1)
    {
        set_led(LED_R, red);
        set_led(LED_G, green);
        set_led(LED_B, blue);
        set_led(LED_O, orange);
        red ^= 1;
        green ^= 1;
        blue ^= 1;
        orange ^= 1;
        j = 0;
        /* spin for a while, otherwise things happen too fast to see */
        for (i = 0; i < 800000; i++)
        {
            j++;
        }
    }
}
