#ifndef __STM32F4xx_H
#define __STM32F4xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
  
#define STM32F4XX

#define HSE_VALUE    ((uint32_t)8000000)
#define HSE_STARTUP_TIMEOUT    ((uint16_t)0x0500)
#define HSI_VALUE    ((uint32_t)168000000)

#define __CM4_REV           0x0001
#define __MPU_PRESENT       1
#define __NVIC_PRIO_BITS    4
#define __FPU_PRESENT       1

/* memory map for the STM32F4 series */
#define FLASH_BASE ((uint32_t)0x08000000)       // 1MB Flash FLASH
#define CCMDATARAM_BASE ((uint32_t)0x10000000)  // 64K CCM(core coupled memory)
#define SRAM1_BASE ((uint32_t)0x20000000)       // 112K SRAM1
#define SRAM2_BASE ((uint32_t)0x2001C000)       // 16K SRAM2 
#define PERIPH_BASE ((uint32_t)0x40000000)      // Peripherals
#define BKPSRAM_BASE ((uint32_t)0x40024000)     // 4K  Backup SRAM
#define FSMC_R_BASE ((uint32_t)0xA0000000)      // FSMC registers base address

#define CCMDATARAM_BB_BASE ((uint32_t)0x12000000) // CCM bit banding base
#define SRAM1_BB_BASE ((uint32_t)0x22000000)    // SRAM1 bit banding base
#define SRAM2_BB_BASE ((uint32_t)0x2201C000)    // SRAM2 bit banding base
#define PERIPH_BB_BASE ((uint32_t)0x42000000)   // Peripheral bit banding base
#define BKPSRAM_BB_BASE ((uint32_t)0x42024000)  // Backup SRAM bit banding base

#define SCS_BASE ((uint32_t) 0xE000E000UL)      // System Control Space

/* Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)

typedef enum IRQn
{
    /* Generic Cortex-M4 Exceptions */
    NonMaskableInt_IRQn = -14,   // 2 Non Maskable Interrupt 
    MemoryManagement_IRQn = -12, // 4 Cortex-M4 Memory Management Interrupt 
    BusFault_IRQn = -11,         // 5 Cortex-M4 Bus Fault Interrupt
    UsageFault_IRQn = -10,       // 6 Cortex-M4 Usage Fault Interrupt
    SVCall_IRQn = -5,            // 11 Cortex-M4 SV Call Interrupt  
    DebugMonitor_IRQn = -4,      // 12 Cortex-M4 Debug Monitor Interrupt
    PendSV_IRQn = -2,            // 14 Cortex-M4 Pend SV Interrupt
    SysTick_IRQn = -1,           // 15 Cortex-M4 System Tick Interrupt
    /* STM32 specific Interrupt Numbers */
    WWDG_IRQn                   = 0,
    PVD_IRQn                    = 1,
    TAMP_STAMP_IRQn             = 2,
    RTC_WKUP_IRQn               = 3,
    FLASH_IRQn                  = 4, 
    RCC_IRQn                    = 5,
    EXTI0_IRQn                  = 6,
    EXTI1_IRQn                  = 7,
    EXTI2_IRQn                  = 8,
    EXTI3_IRQn                  = 9,
    EXTI4_IRQn                  = 10,
    DMA1_Stream0_IRQn           = 11,
    DMA1_Stream1_IRQn           = 12,
    DMA1_Stream2_IRQn           = 13,
    DMA1_Stream3_IRQn           = 14,
    DMA1_Stream4_IRQn           = 15,
    DMA1_Stream5_IRQn           = 16,
    DMA1_Stream6_IRQn           = 17,
    ADC_IRQn                    = 18,
    CAN1_TX_IRQn                = 19,
    CAN1_RX0_IRQn               = 20,
    CAN1_RX1_IRQn               = 21,
    CAN1_SCE_IRQn               = 22,
    EXTI9_5_IRQn                = 23,
    TIM1_BRK_TIM9_IRQn          = 24,
    TIM1_UP_TIM10_IRQn          = 25,  
    TIM1_TRG_COM_TIM11_IRQn     = 26, 
    TIM1_CC_IRQn                = 27,
    TIM2_IRQn                   = 28,
    TIM3_IRQn                   = 29,
    TIM4_IRQn                   = 30,
    I2C1_EV_IRQn                = 31,
    I2C1_ER_IRQn                = 32,
    I2C2_EV_IRQn                = 33,
    I2C2_ER_IRQn                = 34,
    SPI1_IRQn                   = 35,
    SPI2_IRQn                   = 36,
    USART1_IRQn                 = 37,
    USART2_IRQn                 = 38,
    USART3_IRQn                 = 39,
    EXTI15_10_IRQn              = 40,
    RTC_Alarm_IRQn              = 41,
    OTG_FS_WKUP_IRQn            = 42,
    TIM8_BRK_TIM12_IRQn         = 43,
    TIM8_UP_TIM13_IRQn          = 44,
    TIM8_TRG_COM_TIM14_IRQn     = 45,
    TIM8_CC_IRQn                = 46,
    DMA1_Stream7_IRQn           = 47,
    FSMC_IRQn                   = 48,
    SDIO_IRQn                   = 49,
    TIM5_IRQn                   = 50,
    SPI3_IRQn                   = 51,
    UART4_IRQn                  = 52,
    UART5_IRQn                  = 53,
    TIM6_DAC_IRQn               = 54,
    TIM7_IRQn                   = 55,
    DMA2_Stream0_IRQn           = 56,
    DMA2_Stream1_IRQn           = 57,
    DMA2_Stream2_IRQn           = 58,
    DMA2_Stream3_IRQn           = 59,
    DMA2_Stream4_IRQn           = 60,
    ETH_IRQn                    = 61,
    ETH_WKUP_IRQn               = 62,
    CAN2_TX_IRQn                = 63,
    CAN2_RX0_IRQn               = 64,
    CAN2_RX1_IRQn               = 65,
    CAN2_SCE_IRQn               = 66,
    OTG_FS_IRQn                 = 67,
    DMA2_Stream5_IRQn           = 68,
    DMA2_Stream6_IRQn           = 69,
    DMA2_Stream7_IRQn           = 70,
    USART6_IRQn                 = 71,
    I2C3_EV_IRQn                = 72,
    I2C3_ER_IRQn                = 73,
    OTG_HS_EP1_OUT_IRQn         = 74,
    OTG_HS_EP1_IN_IRQn          = 75,
    OTG_HS_WKUP_IRQn            = 76,
    OTG_HS_IRQn                 = 77,
    DCMI_IRQn                   = 78,
    CRYP_IRQn                   = 79,
    HASH_RNG_IRQn               = 80,
    FPU_IRQn                    = 81 
} IRQn_Type;

#include <stdint.h>

/*** System Control Block ***/
typedef struct
{
                                // Off  Acc Register Description
    volatile uint32_t CPUID;    // 0x00 r   CPUID Base
    volatile uint32_t ICSR;     // 0x04 rw  Interrupt Control and State 
    volatile uint32_t VTOR;     // 0x08 rw  Vector Table Offset
    volatile uint32_t AIRCR;    // 0x0C rw  Application Interrupt and Reset Control 
    volatile uint32_t SCR;      // 0x10 rw  System Control
    volatile uint32_t CCR;      // 0x14 rw  Configuration Control
    volatile uint8_t  SHP[12];  // 0x18 rw  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    volatile uint32_t SHCSR;    // 0x24 rw  System Handler Control and State
    volatile uint32_t CFSR;     // 0x28 rw  Configurable Fault Status
    volatile uint32_t HFSR;     // 0x2C rw  HardFault Status
    volatile uint32_t DFSR;     // 0x30 rw  Debug Fault Status
    volatile uint32_t MMFAR;    // 0x34 rw  MemManage Fault Address
    volatile uint32_t BFAR;     // 0x38 rw  BusFault Address
    volatile uint32_t AFSR;     // 0x3C rw  Auxiliary Fault Status
    volatile  uint32_t PFR[2];  // 0x40 r  Processor Feature
    volatile  uint32_t DFR;     // 0x48 r  Debug Feature
    volatile  uint32_t ADR;     // 0x4C r  Auxiliary Feature
    volatile  uint32_t MMFR[4]; // 0x50 r  Memory Model Feature
    volatile  uint32_t ISAR[5]; // 0x60 r  Instruction Set Attributes
    uint32_t RESERVED0[5];
    volatile uint32_t CPACR;    // 0x88 rw Coprocessor Access Control
} SCB_Type;

/*** SysTick ***/
typedef struct
{
  volatile uint32_t CTRL;       // 0x00 rw  SysTick Control and Status
  volatile uint32_t LOAD;       // 0x04 rw  SysTick Reload Value
  volatile uint32_t VAL;        // 0x08 rw  SysTick Current Value
  volatile  uint32_t CALIB;     // 0x0C r   SysTick Calibration
} SysTick_Type;

#define SysTick_BASE ((uint32_t) SCS_BASE+0x0010UL) // SysTick Base Address
#define NVIC_BASE    ((uint32_t) SCS_BASE+0x0100UL) // NVIC Base Address
#define SCB_BASE     ((uint32_t) SCS_BASE+0x0D00UL) // System Control Block

#define SCB ((SCB_Type *) SCB_BASE)   // SCB configuration 
#define SysTick ((SysTick_Type *) SysTick_BASE) // SysTick configuration

typedef struct
{
                                // offset   Register Description
    volatile uint32_t CR;       // 0x00     RCC clock control
    volatile uint32_t PLLCFGR;  // 0x04     RCC PLL configuration
    volatile uint32_t CFGR;     // 0x08     RCC clock configuration
    volatile uint32_t CIR;      // 0x0c     RCC clock interrupt
    volatile uint32_t AHB1RSTR; // 0x10     RCC AHB1 peripheral reset
    volatile uint32_t AHB2RSTR; // 0x14     RCC AHB2 peripheral reset
    volatile uint32_t AHB3RSTR; // 0x18     RCC AHB3 peripheral reset
    uint32_t RESERVED0;         // 0x1c     Reserved
    volatile uint32_t APB1RSTR; // 0x20     RCC APB1 peripheral reset
    volatile uint32_t APB2RSTR; // 0x24     RCC APB2 peripheral reset
    uint32_t RESERVED1[2];      // 0x28-0x2C    Reserved
    volatile uint32_t AHB1ENR;  // 0x30     RCC AHB1 peripheral clock
    volatile uint32_t AHB2ENR;  // 0x34     RCC AHB2 peripheral clock
    volatile uint32_t AHB3ENR;  // 0x38     RCC AHB3 peripheral clock
    uint32_t RESERVED2;         // 0x3c     Reserved
    volatile uint32_t APB1ENR;  // 0x40     RCC APB1 peripheral clock enable
    volatile uint32_t APB2ENR;  // 0x44     RCC APB2 peripheral clock enable
    uint32_t RESERVED3[2];      // 0x48-0x4c --Reserved--
    volatile uint32_t AHB1LPENR; // 0x50    RCC AHB1 p-clock enable in LP mode 
    volatile uint32_t AHB2LPENR; // 0x54    RCC AHB2 p-clock enable in LP mode
    volatile uint32_t AHB3LPENR; // 0x58    RCC AHB3 p-clock enable in LP mode
    uint32_t RESERVED4;         // 0x5c     --Reserved--
    volatile uint32_t APB1LPENR; // 0x60    RCC APB1 p-clock enable in LP mode
    volatile uint32_t APB2LPENR; // 0x64    RCC APB2 p-clock enable in LP mode
    uint32_t RESERVED5[2];      // 0x68-0x6c    Reserved
    volatile uint32_t BDCR;     // 0x70     RCC Backup domain control
    volatile uint32_t CSR;      // 0x74     RCC clock control & status
    uint32_t RESERVED6[2];      // 0x78-0x7c    Reserved
    volatile uint32_t SSCGR;    // 0x80     RCC spread spectrum clock generation
    volatile uint32_t PLLI2SCFGR; // 0x84   RCC PLLI2S configuration 
} RCC_TypeDef;

#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F4xx_H */

