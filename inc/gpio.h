/* GPIO device include file */
#ifndef __gpio_h__
#define __gpio_h__

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
  
#include <stdint.h>

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

/*** GPIO Registers ***/

typedef struct
{
                              // Offest     Description
                              // ------     -------------
  volatile uint32_t MODER;    // 0x00       mode register
  volatile uint32_t OTYPER;   // 0x04       output type register
  volatile uint32_t OSPEEDR;  // 0x08       output speed register
  volatile uint32_t PUPDR;    // 0x0c       pull-up/pull-down register
  volatile uint32_t IDR;      // 0x10       input data register
  volatile uint32_t ODR;      // 0x14       output data register
  volatile uint16_t BSRRL;    // 0x18       bit set/reset low register
  volatile uint16_t BSRRH;    // 0x1A       bit set/reset high register
  volatile uint32_t LCKR;     // 0x1C       configuration lock register
  volatile uint32_t AFR[2];   // 0x20-0x24  alternate function registers
} GPIO_TypeDef;

/* defined in stm32f4.h 
#define PERIPH_BASE    ((uint32_t)0x40000000) //  Peripheral base address
#define PERIPH_BB_BASE ((uint32_t)0x42000000) 

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)
*/

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)

/***  Bits definition for GPIO_MODER register  ***/
#define GPIO_MODER_MODER0       ((uint32_t)0x00000003)
#define GPIO_MODER_MODER0_0     ((uint32_t)0x00000001)
#define GPIO_MODER_MODER0_1     ((uint32_t)0x00000002)

#define GPIO_MODER_MODER1       ((uint32_t)0x0000000C)
#define GPIO_MODER_MODER1_0     ((uint32_t)0x00000004)
#define GPIO_MODER_MODER1_1     ((uint32_t)0x00000008)

#define GPIO_MODER_MODER2       ((uint32_t)0x00000030)
#define GPIO_MODER_MODER2_0     ((uint32_t)0x00000010)
#define GPIO_MODER_MODER2_1     ((uint32_t)0x00000020)

#define GPIO_MODER_MODER3       ((uint32_t)0x000000C0)
#define GPIO_MODER_MODER3_0     ((uint32_t)0x00000040)
#define GPIO_MODER_MODER3_1     ((uint32_t)0x00000080)

#define GPIO_MODER_MODER4       ((uint32_t)0x00000300)
#define GPIO_MODER_MODER4_0     ((uint32_t)0x00000100)
#define GPIO_MODER_MODER4_1     ((uint32_t)0x00000200)

#define GPIO_MODER_MODER5       ((uint32_t)0x00000C00)
#define GPIO_MODER_MODER5_0     ((uint32_t)0x00000400)
#define GPIO_MODER_MODER5_1     ((uint32_t)0x00000800)

#define GPIO_MODER_MODER6       ((uint32_t)0x00003000)
#define GPIO_MODER_MODER6_0     ((uint32_t)0x00001000)
#define GPIO_MODER_MODER6_1     ((uint32_t)0x00002000)

#define GPIO_MODER_MODER7       ((uint32_t)0x0000C000)
#define GPIO_MODER_MODER7_0     ((uint32_t)0x00004000)
#define GPIO_MODER_MODER7_1     ((uint32_t)0x00008000)

#define GPIO_MODER_MODER8       ((uint32_t)0x00030000)
#define GPIO_MODER_MODER8_0     ((uint32_t)0x00010000)
#define GPIO_MODER_MODER8_1     ((uint32_t)0x00020000)

#define GPIO_MODER_MODER9       ((uint32_t)0x000C0000)
#define GPIO_MODER_MODER9_0     ((uint32_t)0x00040000)
#define GPIO_MODER_MODER9_1     ((uint32_t)0x00080000)

#define GPIO_MODER_MODER10      ((uint32_t)0x00300000)
#define GPIO_MODER_MODER10_0    ((uint32_t)0x00100000)
#define GPIO_MODER_MODER10_1    ((uint32_t)0x00200000)

#define GPIO_MODER_MODER11      ((uint32_t)0x00C00000)
#define GPIO_MODER_MODER11_0    ((uint32_t)0x00400000)
#define GPIO_MODER_MODER11_1    ((uint32_t)0x00800000)

#define GPIO_MODER_MODER12      ((uint32_t)0x03000000)
#define GPIO_MODER_MODER12_0    ((uint32_t)0x01000000)
#define GPIO_MODER_MODER12_1    ((uint32_t)0x02000000)

#define GPIO_MODER_MODER13      ((uint32_t)0x0C000000)
#define GPIO_MODER_MODER13_0    ((uint32_t)0x04000000)
#define GPIO_MODER_MODER13_1    ((uint32_t)0x08000000)

#define GPIO_MODER_MODER14      ((uint32_t)0x30000000)
#define GPIO_MODER_MODER14_0    ((uint32_t)0x10000000)
#define GPIO_MODER_MODER14_1    ((uint32_t)0x20000000)

#define GPIO_MODER_MODER15      ((uint32_t)0xC0000000)
#define GPIO_MODER_MODER15_0    ((uint32_t)0x40000000)
#define GPIO_MODER_MODER15_1    ((uint32_t)0x80000000)

/***  GPIO_OTYPER register  ***/
#define GPIO_OTYPER_OT_0        ((uint32_t)0x00000001)
#define GPIO_OTYPER_OT_1        ((uint32_t)0x00000002)
#define GPIO_OTYPER_OT_2        ((uint32_t)0x00000004)
#define GPIO_OTYPER_OT_3        ((uint32_t)0x00000008)
#define GPIO_OTYPER_OT_4        ((uint32_t)0x00000010)
#define GPIO_OTYPER_OT_5        ((uint32_t)0x00000020)
#define GPIO_OTYPER_OT_6        ((uint32_t)0x00000040)
#define GPIO_OTYPER_OT_7        ((uint32_t)0x00000080)
#define GPIO_OTYPER_OT_8        ((uint32_t)0x00000100)
#define GPIO_OTYPER_OT_9        ((uint32_t)0x00000200)
#define GPIO_OTYPER_OT_10       ((uint32_t)0x00000400)
#define GPIO_OTYPER_OT_11       ((uint32_t)0x00000800)
#define GPIO_OTYPER_OT_12       ((uint32_t)0x00001000)
#define GPIO_OTYPER_OT_13       ((uint32_t)0x00002000)
#define GPIO_OTYPER_OT_14       ((uint32_t)0x00004000)
#define GPIO_OTYPER_OT_15       ((uint32_t)0x00008000)

/*** GPIO_OSPEEDR register  ***/
#define GPIO_OSPEEDER_OSPEEDR0   ((uint32_t)0x00000003)
#define GPIO_OSPEEDER_OSPEEDR0_0 ((uint32_t)0x00000001)
#define GPIO_OSPEEDER_OSPEEDR0_1 ((uint32_t)0x00000002)

#define GPIO_OSPEEDER_OSPEEDR1   ((uint32_t)0x0000000C)
#define GPIO_OSPEEDER_OSPEEDR1_0 ((uint32_t)0x00000004)
#define GPIO_OSPEEDER_OSPEEDR1_1 ((uint32_t)0x00000008)

#define GPIO_OSPEEDER_OSPEEDR2   ((uint32_t)0x00000030)
#define GPIO_OSPEEDER_OSPEEDR2_0 ((uint32_t)0x00000010)
#define GPIO_OSPEEDER_OSPEEDR2_1 ((uint32_t)0x00000020)

#define GPIO_OSPEEDER_OSPEEDR3   ((uint32_t)0x000000C0)
#define GPIO_OSPEEDER_OSPEEDR3_0 ((uint32_t)0x00000040)
#define GPIO_OSPEEDER_OSPEEDR3_1 ((uint32_t)0x00000080)

#define GPIO_OSPEEDER_OSPEEDR4   ((uint32_t)0x00000300)
#define GPIO_OSPEEDER_OSPEEDR4_0 ((uint32_t)0x00000100)
#define GPIO_OSPEEDER_OSPEEDR4_1 ((uint32_t)0x00000200)

#define GPIO_OSPEEDER_OSPEEDR5   ((uint32_t)0x00000C00)
#define GPIO_OSPEEDER_OSPEEDR5_0 ((uint32_t)0x00000400)
#define GPIO_OSPEEDER_OSPEEDR5_1 ((uint32_t)0x00000800)

#define GPIO_OSPEEDER_OSPEEDR6   ((uint32_t)0x00003000)
#define GPIO_OSPEEDER_OSPEEDR6_0 ((uint32_t)0x00001000)
#define GPIO_OSPEEDER_OSPEEDR6_1 ((uint32_t)0x00002000)

#define GPIO_OSPEEDER_OSPEEDR7   ((uint32_t)0x0000C000)
#define GPIO_OSPEEDER_OSPEEDR7_0 ((uint32_t)0x00004000)
#define GPIO_OSPEEDER_OSPEEDR7_1 ((uint32_t)0x00008000)

#define GPIO_OSPEEDER_OSPEEDR8   ((uint32_t)0x00030000)
#define GPIO_OSPEEDER_OSPEEDR8_0 ((uint32_t)0x00010000)
#define GPIO_OSPEEDER_OSPEEDR8_1 ((uint32_t)0x00020000)

#define GPIO_OSPEEDER_OSPEEDR9   ((uint32_t)0x000C0000)
#define GPIO_OSPEEDER_OSPEEDR9_0 ((uint32_t)0x00040000)
#define GPIO_OSPEEDER_OSPEEDR9_1 ((uint32_t)0x00080000)

#define GPIO_OSPEEDER_OSPEEDR10  ((uint32_t)0x00300000)
#define GPIO_OSPEEDER_OSPEEDR10_0 ((uint32_t)0x00100000)
#define GPIO_OSPEEDER_OSPEEDR10_1 ((uint32_t)0x00200000)

#define GPIO_OSPEEDER_OSPEEDR11  ((uint32_t)0x00C00000)
#define GPIO_OSPEEDER_OSPEEDR11_0 ((uint32_t)0x00400000)
#define GPIO_OSPEEDER_OSPEEDR11_1 ((uint32_t)0x00800000)

#define GPIO_OSPEEDER_OSPEEDR12  ((uint32_t)0x03000000)
#define GPIO_OSPEEDER_OSPEEDR12_0 ((uint32_t)0x01000000)
#define GPIO_OSPEEDER_OSPEEDR12_1 ((uint32_t)0x02000000)

#define GPIO_OSPEEDER_OSPEEDR13  ((uint32_t)0x0C000000)
#define GPIO_OSPEEDER_OSPEEDR13_0 ((uint32_t)0x04000000)
#define GPIO_OSPEEDER_OSPEEDR13_1 ((uint32_t)0x08000000)

#define GPIO_OSPEEDER_OSPEEDR14  ((uint32_t)0x30000000)
#define GPIO_OSPEEDER_OSPEEDR14_0 ((uint32_t)0x10000000)
#define GPIO_OSPEEDER_OSPEEDR14_1 ((uint32_t)0x20000000)

#define GPIO_OSPEEDER_OSPEEDR15  ((uint32_t)0xC0000000)
#define GPIO_OSPEEDER_OSPEEDR15_0 ((uint32_t)0x40000000)
#define GPIO_OSPEEDER_OSPEEDR15_1 ((uint32_t)0x80000000)

/***  GPIO_PUPDR register  ***/
#define GPIO_PUPDR_PUPDR0       ((uint32_t)0x00000003)
#define GPIO_PUPDR_PUPDR0_0     ((uint32_t)0x00000001)
#define GPIO_PUPDR_PUPDR0_1     ((uint32_t)0x00000002)

#define GPIO_PUPDR_PUPDR1       ((uint32_t)0x0000000C)
#define GPIO_PUPDR_PUPDR1_0     ((uint32_t)0x00000004)
#define GPIO_PUPDR_PUPDR1_1     ((uint32_t)0x00000008)

#define GPIO_PUPDR_PUPDR2       ((uint32_t)0x00000030)
#define GPIO_PUPDR_PUPDR2_0     ((uint32_t)0x00000010)
#define GPIO_PUPDR_PUPDR2_1     ((uint32_t)0x00000020)

#define GPIO_PUPDR_PUPDR3       ((uint32_t)0x000000C0)
#define GPIO_PUPDR_PUPDR3_0     ((uint32_t)0x00000040)
#define GPIO_PUPDR_PUPDR3_1     ((uint32_t)0x00000080)

#define GPIO_PUPDR_PUPDR4       ((uint32_t)0x00000300)
#define GPIO_PUPDR_PUPDR4_0     ((uint32_t)0x00000100)
#define GPIO_PUPDR_PUPDR4_1     ((uint32_t)0x00000200)

#define GPIO_PUPDR_PUPDR5       ((uint32_t)0x00000C00)
#define GPIO_PUPDR_PUPDR5_0     ((uint32_t)0x00000400)
#define GPIO_PUPDR_PUPDR5_1     ((uint32_t)0x00000800)

#define GPIO_PUPDR_PUPDR6       ((uint32_t)0x00003000)
#define GPIO_PUPDR_PUPDR6_0     ((uint32_t)0x00001000)
#define GPIO_PUPDR_PUPDR6_1     ((uint32_t)0x00002000)

#define GPIO_PUPDR_PUPDR7       ((uint32_t)0x0000C000)
#define GPIO_PUPDR_PUPDR7_0     ((uint32_t)0x00004000)
#define GPIO_PUPDR_PUPDR7_1     ((uint32_t)0x00008000)

#define GPIO_PUPDR_PUPDR8       ((uint32_t)0x00030000)
#define GPIO_PUPDR_PUPDR8_0     ((uint32_t)0x00010000)
#define GPIO_PUPDR_PUPDR8_1     ((uint32_t)0x00020000)

#define GPIO_PUPDR_PUPDR9       ((uint32_t)0x000C0000)
#define GPIO_PUPDR_PUPDR9_0     ((uint32_t)0x00040000)
#define GPIO_PUPDR_PUPDR9_1     ((uint32_t)0x00080000)

#define GPIO_PUPDR_PUPDR10      ((uint32_t)0x00300000)
#define GPIO_PUPDR_PUPDR10_0    ((uint32_t)0x00100000)
#define GPIO_PUPDR_PUPDR10_1    ((uint32_t)0x00200000)

#define GPIO_PUPDR_PUPDR11      ((uint32_t)0x00C00000)
#define GPIO_PUPDR_PUPDR11_0    ((uint32_t)0x00400000)
#define GPIO_PUPDR_PUPDR11_1    ((uint32_t)0x00800000)

#define GPIO_PUPDR_PUPDR12      ((uint32_t)0x03000000)
#define GPIO_PUPDR_PUPDR12_0    ((uint32_t)0x01000000)
#define GPIO_PUPDR_PUPDR12_1    ((uint32_t)0x02000000)

#define GPIO_PUPDR_PUPDR13      ((uint32_t)0x0C000000)
#define GPIO_PUPDR_PUPDR13_0    ((uint32_t)0x04000000)
#define GPIO_PUPDR_PUPDR13_1    ((uint32_t)0x08000000)

#define GPIO_PUPDR_PUPDR14      ((uint32_t)0x30000000)
#define GPIO_PUPDR_PUPDR14_0    ((uint32_t)0x10000000)
#define GPIO_PUPDR_PUPDR14_1    ((uint32_t)0x20000000)

#define GPIO_PUPDR_PUPDR15      ((uint32_t)0xC0000000)
#define GPIO_PUPDR_PUPDR15_0    ((uint32_t)0x40000000)
#define GPIO_PUPDR_PUPDR15_1    ((uint32_t)0x80000000)

/***  GPIO_IDR register  ***/
#define GPIO_IDR_IDR_0          ((uint32_t)0x00000001)
#define GPIO_IDR_IDR_1          ((uint32_t)0x00000002)
#define GPIO_IDR_IDR_2          ((uint32_t)0x00000004)
#define GPIO_IDR_IDR_3          ((uint32_t)0x00000008)
#define GPIO_IDR_IDR_4          ((uint32_t)0x00000010)
#define GPIO_IDR_IDR_5          ((uint32_t)0x00000020)
#define GPIO_IDR_IDR_6          ((uint32_t)0x00000040)
#define GPIO_IDR_IDR_7          ((uint32_t)0x00000080)
#define GPIO_IDR_IDR_8          ((uint32_t)0x00000100)
#define GPIO_IDR_IDR_9          ((uint32_t)0x00000200)
#define GPIO_IDR_IDR_10         ((uint32_t)0x00000400)
#define GPIO_IDR_IDR_11         ((uint32_t)0x00000800)
#define GPIO_IDR_IDR_12         ((uint32_t)0x00001000)
#define GPIO_IDR_IDR_13         ((uint32_t)0x00002000)
#define GPIO_IDR_IDR_14         ((uint32_t)0x00004000)
#define GPIO_IDR_IDR_15         ((uint32_t)0x00008000)

/***  Bits definition for GPIO_ODR register  ***/
#define GPIO_ODR_ODR_0          ((uint32_t)0x00000001)
#define GPIO_ODR_ODR_1          ((uint32_t)0x00000002)
#define GPIO_ODR_ODR_2          ((uint32_t)0x00000004)
#define GPIO_ODR_ODR_3          ((uint32_t)0x00000008)
#define GPIO_ODR_ODR_4          ((uint32_t)0x00000010)
#define GPIO_ODR_ODR_5          ((uint32_t)0x00000020)
#define GPIO_ODR_ODR_6          ((uint32_t)0x00000040)
#define GPIO_ODR_ODR_7          ((uint32_t)0x00000080)
#define GPIO_ODR_ODR_8          ((uint32_t)0x00000100)
#define GPIO_ODR_ODR_9          ((uint32_t)0x00000200)
#define GPIO_ODR_ODR_10         ((uint32_t)0x00000400)
#define GPIO_ODR_ODR_11         ((uint32_t)0x00000800)
#define GPIO_ODR_ODR_12         ((uint32_t)0x00001000)
#define GPIO_ODR_ODR_13         ((uint32_t)0x00002000)
#define GPIO_ODR_ODR_14         ((uint32_t)0x00004000)
#define GPIO_ODR_ODR_15         ((uint32_t)0x00008000)

/***  Bits definition for GPIO_BSRR register ***/
#define GPIO_BSRR_BS_0          ((uint32_t)0x00000001)
#define GPIO_BSRR_BS_1          ((uint32_t)0x00000002)
#define GPIO_BSRR_BS_2          ((uint32_t)0x00000004)
#define GPIO_BSRR_BS_3          ((uint32_t)0x00000008)
#define GPIO_BSRR_BS_4          ((uint32_t)0x00000010)
#define GPIO_BSRR_BS_5          ((uint32_t)0x00000020)
#define GPIO_BSRR_BS_6          ((uint32_t)0x00000040)
#define GPIO_BSRR_BS_7          ((uint32_t)0x00000080)
#define GPIO_BSRR_BS_8          ((uint32_t)0x00000100)
#define GPIO_BSRR_BS_9          ((uint32_t)0x00000200)
#define GPIO_BSRR_BS_10         ((uint32_t)0x00000400)
#define GPIO_BSRR_BS_11         ((uint32_t)0x00000800)
#define GPIO_BSRR_BS_12         ((uint32_t)0x00001000)
#define GPIO_BSRR_BS_13         ((uint32_t)0x00002000)
#define GPIO_BSRR_BS_14         ((uint32_t)0x00004000)
#define GPIO_BSRR_BS_15         ((uint32_t)0x00008000)
#define GPIO_BSRR_BR_0          ((uint32_t)0x00010000)
#define GPIO_BSRR_BR_1          ((uint32_t)0x00020000)
#define GPIO_BSRR_BR_2          ((uint32_t)0x00040000)
#define GPIO_BSRR_BR_3          ((uint32_t)0x00080000)
#define GPIO_BSRR_BR_4          ((uint32_t)0x00100000)
#define GPIO_BSRR_BR_5          ((uint32_t)0x00200000)
#define GPIO_BSRR_BR_6          ((uint32_t)0x00400000)
#define GPIO_BSRR_BR_7          ((uint32_t)0x00800000)
#define GPIO_BSRR_BR_8          ((uint32_t)0x01000000)
#define GPIO_BSRR_BR_9          ((uint32_t)0x02000000)
#define GPIO_BSRR_BR_10         ((uint32_t)0x04000000)
#define GPIO_BSRR_BR_11         ((uint32_t)0x08000000)
#define GPIO_BSRR_BR_12         ((uint32_t)0x10000000)
#define GPIO_BSRR_BR_13         ((uint32_t)0x20000000)
#define GPIO_BSRR_BR_14         ((uint32_t)0x40000000)
#define GPIO_BSRR_BR_15         ((uint32_t)0x80000000)

/***  RCC_AHB1ENR register  ***/
#define  RCC_AHB1ENR_GPIOAEN    ((uint32_t)0x00000001)
#define  RCC_AHB1ENR_GPIOBEN    ((uint32_t)0x00000002)
#define  RCC_AHB1ENR_GPIOCEN    ((uint32_t)0x00000004)
#define  RCC_AHB1ENR_GPIODEN    ((uint32_t)0x00000008)
#define  RCC_AHB1ENR_GPIOEEN    ((uint32_t)0x00000010)
#define  RCC_AHB1ENR_GPIOFEN    ((uint32_t)0x00000020)
#define  RCC_AHB1ENR_GPIOGEN    ((uint32_t)0x00000040)
#define  RCC_AHB1ENR_GPIOHEN    ((uint32_t)0x00000080)
#define  RCC_AHB1ENR_GPIOIEN    ((uint32_t)0x00000100)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __gpio_h__ */
