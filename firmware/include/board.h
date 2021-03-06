/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32F4_DISCOVERY
#define BOARD_NAME              "ST STM32F4-Discovery"

/*
 * Board frequencies.
 * NOTE: The LSE crystal is not fitted by default on the board.
 */
#define STM32_LSECLK            0
#define STM32_HSECLK            8000000

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD               300

/*
 * MCU type as defined in the ST header file stm32f4xx.h.
 */
#define STM32F4XX

/*
 * IO pins assignments.
 */
#define GPIOA_PA0_TIM5_CH1      0		/* timer for the WEST sonar PWM out */
#define GPIOA_PA2_USART2_TX		 2		/* connection to the zigbee at 19600bps (TX) */
#define GPIOA_PA3_USART2_RX     3  		/* connection to the zigbee at 19600bps (RX) */
#define GPIOA_LRCK              4
#define GPIOA_SDO               6
#define GPIOA_SDI               7
#define GPIOA_PA8_TIM1_CH1      8  		/* timer for the NORTH sonar PWM out */
#define GPIOA_VBUS_FS           9
#define GPIOA_OTG_FS_ID         10
#define GPIOA_OTG_FS_DM         11
#define GPIOA_OTG_FS_DP         12
#define GPIOA_SWDIO             13
#define GPIOA_SWCLK             14

#define GPIOB_SWO               3
#define GPIOB_PB4_TIM3_CH1      4 		/* timer for the SOUTH sonar PWM out */
#define GPIOB_SCL               6
#define GPIOB_SDA               9
#define GPIOB_PB10_USART3_TX    10
#define GPIOB_PB11_USART3_RX    11		/* USART interface to the RFID reader */

#define GPIOC_OTG_FS_POWER_ON   0
#define GPIOC_IR3               1
#define GPIOC_IR2               2
#define GPIOC_DOUT              3
#define GPIOC_IR0               4
#define GPIOC_IR1               5
#define GPIOC_PC6_TIM8_CH1      6 		/* timer for the EAST sonar PWM out */
#define GPIOC_MCLK              7
#define GPIOC_SCLK              10
#define GPIOC_SDIN              12

/* GPIO4 PD0 - PD1 - PD2 for the factories, PD3 for the tower */
#define GPIOD_RESET             4
#define GPIOD_OVER_CURRENT      5
#define GPIOD_IRLED             11      /* Infrared LEDs */
#define GPIOD_LED4              12      /* Green LED.   */
#define GPIOD_LED3              13      /* Orange LED.  */
#define GPIOD_LED5              14      /* Red LED.     */
#define GPIOD_LED6              15      /* Blue LED.    */

#define GPIOE_INT1              0
#define GPIOE_INT2              1
#define GPIOE_CS_SPI            3
#define GPIOE_REDLED0           7    	/* the red leds on the robot */
#define GPIOE_REDLED1           8
#define GPIOE_REDLED2           9
#define GPIOE_REDLED3           10
#define GPIOE_YELLOWLED0        11   	/* the yellow leds on the robot */
#define GPIOE_YELLOWLED1        12
#define GPIOE_YELLOWLED2        13
#define GPIOE_YELLOWLED3        14
#define GPIOE_GREENLED0         15   	/* the green led on the robot */

#define GPIOH_OSC_IN            0
#define GPIOH_OSC_OUT           1

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2))
#define PIN_PUDR_FLOATING(n)        (0U << ((n) * 2))
#define PIN_PUDR_PULLUP(n)          (1U << ((n) * 2))
#define PIN_PUDR_PULLDOWN(n)        (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << ((n % 8) * 4))

/*
 * Port A setup.
 * All input with pull-up except:
 * PA0  - GPIOA_PA0_TIM5_CH1    (alternate 2).
 * PA2  - GPIOA_PA2_USART2_TX   (alternate 7).
 * PA3  - GPIOA_PA3_USART2_RX   (alternate 7).
 * PA4  - GPIOA_LRCK            (alternate 6).
 * PA6  - GPIOA_SDO             (alternate 5).
 * PA7  - GPIOA_SDI             (alternate 5).
 * PA8  - GPIOA_PA8_TIM1_CH1    (alternate 1).
 * PA9  - GPIOA_VBUS_FS         (input floating).
 * PA10 - GPIOA_OTG_FS_ID       (alternate 10).
 * PA11 - GPIOA_OTG_FS_DM       (alternate 10).
 * PA12 - GPIOA_OTG_FS_DP       (alternate 10).
 * PA13 - GPIOA_SWDIO           (alternate 0).
 * PA14 - GPIOA_SWCLK           (alternate 0).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ALTERNATE(GPIOA_PA0_TIM5_CH1) |  \
                                     PIN_MODE_INPUT(1)                       |  \
                                     PIN_MODE_ALTERNATE(GPIOA_PA2_USART2_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_PA3_USART2_RX) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_LRCK)          |  \
                                     PIN_MODE_INPUT(5)                       |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SDO)           |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SDI)           |  \
                                     PIN_MODE_ALTERNATE(GPIOA_PA8_TIM1_CH1)  |  \
                                     PIN_MODE_INPUT(GPIOA_VBUS_FS)     |        \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_ID)     |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DM)     |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DP)     |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO)     |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK)     |      \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOA_OTYPER            0x00000000
#define VAL_GPIOA_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOA_PUPDR             (PIN_PUDR_PULLDOWN(GPIOA_PA0_TIM5_CH1) | \
                                     PIN_PUDR_PULLUP(1) |                   \
                                     PIN_PUDR_PULLUP(GPIOA_PA2_USART2_TX) | \
                                     PIN_PUDR_PULLUP(GPIOA_PA3_USART2_RX) | \
                                     PIN_PUDR_FLOATING(GPIOA_LRCK) |        \
                                     PIN_PUDR_PULLUP(5)            |        \
                                     PIN_PUDR_FLOATING(GPIOA_SDO) |         \
                                     PIN_PUDR_FLOATING(GPIOA_SDI) |         \
                                     PIN_PUDR_PULLDOWN(GPIOA_PA8_TIM1_CH1) |\
                                     PIN_PUDR_FLOATING(GPIOA_VBUS_FS) |     \
                                     PIN_PUDR_FLOATING(GPIOA_OTG_FS_ID) |   \
                                     PIN_PUDR_FLOATING(GPIOA_OTG_FS_DM) |   \
                                     PIN_PUDR_FLOATING(GPIOA_OTG_FS_DP) |   \
                                     PIN_PUDR_PULLUP(GPIOA_SWDIO) |         \
                                     PIN_PUDR_PULLDOWN(GPIOA_SWCLK) |       \
                                     PIN_PUDR_PULLUP(15))
#define VAL_GPIOA_ODR               0xFFFFFFFF
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_PA0_TIM5_CH1, 2) |  \
                                     PIN_AFIO_AF(GPIOA_PA2_USART2_TX, 7) |  \
                                     PIN_AFIO_AF(GPIOA_PA3_USART2_RX, 7) |  \
                                     PIN_AFIO_AF(GPIOA_LRCK, 6) |           \
                                     PIN_AFIO_AF(GPIOA_SDO, 5) |            \
                                     PIN_AFIO_AF(GPIOA_SDI, 5))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_PA8_TIM1_CH1, 1) |  \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_ID, 10) |     \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DM, 10) |     \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DP, 10) |     \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0) |          \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0))

/*
 * Port B setup.
 * All input with pull-up except:
 * PB3  - GPIOB_SWO             (alternate 0).
 * PB4  - GPIOB_PB4_TIM3_CH1    (alternate 2).
 * PB6  - GPIOB_SCL             (alternate 4).
 * PB9  - GPIOB_SDA             (alternate 4).
 * PB10 - GPIOB_PB10_USART3_TX  (alternate xx).
 * PB11 - GPIOB_PB11_USART3_RX  (alternate xx).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(0) |                    \
                                     PIN_MODE_INPUT(1) |                    \
                                     PIN_MODE_INPUT(2) |                    \
                                     PIN_MODE_ALTERNATE(GPIOB_SWO) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_PB4_TIM3_CH1) |                    \
                                     PIN_MODE_INPUT(5) |                    \
                                     PIN_MODE_ALTERNATE(GPIOB_SCL) |        \
                                     PIN_MODE_INPUT(7) |                    \
                                     PIN_MODE_INPUT(8) |                    \
                                     PIN_MODE_ALTERNATE(GPIOB_SDA) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_PB10_USART3_TX) |                   \
                                     PIN_MODE_ALTERNATE(GPIOB_PB11_USART3_RX) |                   \
                                     PIN_MODE_INPUT(12) |                   \
                                     PIN_MODE_INPUT(13) |                   \
                                     PIN_MODE_INPUT(14) |                   \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_OPENDRAIN(GPIOB_SCL) |       \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_SDA))
#define VAL_GPIOB_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOB_PUPDR             (PIN_PUDR_PULLUP(0) |                   \
                                     PIN_PUDR_PULLUP(1) |                   \
                                     PIN_PUDR_PULLUP(2) |                   \
                                     PIN_PUDR_FLOATING(GPIOB_SWO) |         \
                                     PIN_PUDR_PULLDOWN(GPIOB_PB4_TIM3_CH1) | \
                                     PIN_PUDR_PULLUP(5) |                   \
                                     PIN_PUDR_FLOATING(GPIOB_SCL) |         \
                                     PIN_PUDR_PULLUP(7) |                   \
                                     PIN_PUDR_PULLUP(8) |                   \
                                     PIN_PUDR_FLOATING(GPIOB_SDA) |         \
                                     PIN_PUDR_PULLUP(GPIOB_PB10_USART3_TX) |  \
                                     PIN_PUDR_PULLUP(GPIOB_PB11_USART3_RX) |  \
                                     PIN_PUDR_PULLUP(12) |                  \
                                     PIN_PUDR_PULLUP(13) |                  \
                                     PIN_PUDR_PULLUP(14) |                  \
                                     PIN_PUDR_PULLUP(15))
#define VAL_GPIOB_ODR               0xFFFFFFFF
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_SWO, 0) |           \
                                      PIN_AFIO_AF(GPIOB_PB4_TIM3_CH1,2) |   \
                                      PIN_AFIO_AF(GPIOB_SCL, 4))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_SDA, 4) |           \
		                              PIN_AFIO_AF(GPIOB_PB10_USART3_TX, 7) |\
		                              PIN_AFIO_AF(GPIOB_PB11_USART3_RX, 7))

/*
 * Port C setup.
 * All input with pull-up except:
 * PC0  - GPIOC_OTG_FS_POWER_ON (output push-pull).
 * PC6  - GPIOB_PC6_TIM8_CH1    (alternate 3).
 * PC7  - GPIOC_MCLK            (alternate 6).
 * PC10 - GPIOC_SCLK            (alternate 6).
 * PC12 - GPIOC_SDIN            (alternate 6).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_OUTPUT(GPIOC_OTG_FS_POWER_ON) |\
                                     PIN_MODE_ANALOG(1) |                    \
                                     PIN_MODE_ANALOG(2) |                    \
                                     PIN_MODE_INPUT(3) |                    \
                                     PIN_MODE_ANALOG(4) |                    \
                                     PIN_MODE_ANALOG(5) |                    \
                                     PIN_MODE_ALTERNATE(GPIOC_PC6_TIM8_CH1) | \
                                     PIN_MODE_ALTERNATE(GPIOC_MCLK) |       \
                                     PIN_MODE_INPUT(8) |                    \
                                     PIN_MODE_INPUT(9) |                    \
                                     PIN_MODE_ALTERNATE(GPIOC_SCLK) |       \
                                     PIN_MODE_INPUT(11) |                   \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIN) |       \
                                     PIN_MODE_INPUT(13) |                   \
                                     PIN_MODE_INPUT(14) |                   \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOC_OTYPER            0x00000000
#define VAL_GPIOC_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOC_PUPDR             (PIN_PUDR_FLOATING(GPIOC_OTG_FS_POWER_ON) |\
                                     PIN_PUDR_PULLUP(1) |                   \
                                     PIN_PUDR_PULLUP(2) |                   \
                                     PIN_PUDR_PULLUP(3) |                   \
                                     PIN_PUDR_PULLUP(4) |                   \
                                     PIN_PUDR_PULLUP(5) |                   \
                                     PIN_PUDR_PULLDOWN(GPIOC_PC6_TIM8_CH1) | \
                                     PIN_PUDR_FLOATING(GPIOC_MCLK)  |       \
                                     PIN_PUDR_PULLUP(8) |                   \
                                     PIN_PUDR_PULLUP(9) |                   \
                                     PIN_PUDR_FLOATING(GPIOC_SCLK)  |       \
                                     PIN_PUDR_PULLUP(11) |                  \
                                     PIN_PUDR_FLOATING(GPIOC_SDIN)  |       \
                                     PIN_PUDR_PULLUP(13) |                  \
                                     PIN_PUDR_PULLUP(14) |                  \
                                     PIN_PUDR_PULLUP(15))
#define VAL_GPIOC_ODR               0xFFFFFFFF
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_PC6_TIM8_CH1, 3) |  	\
		                             PIN_AFIO_AF(GPIOC_MCLK, 6))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_SCLK, 6) |           \
                                     PIN_AFIO_AF(GPIOC_SDIN, 6))

/*
 * Port D setup.
 * All input with pull-up except:
 * PD4  - GPIOD_RESET           (output push-pull).
 * PD5  - GPIOD_OVER_CURRENT    (input floating).
 * PD11 - GPIOD_IRLED			(output push-pull).
 * PD12 - GPIOD_LED4            (output push-pull).
 * PD13 - GPIOD_LED3            (output push-pull).
 * PD14 - GPIOD_LED5            (output push-pull).
 * PD15 - GPIOD_LED6            (output push-pull).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(0) |                    \
                                     PIN_MODE_INPUT(1) |                    \
                                     PIN_MODE_INPUT(2) |                    \
                                     PIN_MODE_INPUT(3) |                    \
                                     PIN_MODE_OUTPUT(GPIOD_RESET) |         \
                                     PIN_MODE_INPUT(GPIOD_OVER_CURRENT) |   \
                                     PIN_MODE_INPUT(6) |                    \
                                     PIN_MODE_INPUT(7) |                    \
                                     PIN_MODE_INPUT(8) |                    \
                                     PIN_MODE_INPUT(9) |                    \
                                     PIN_MODE_INPUT(10) |                   \
                                     PIN_MODE_OUTPUT(GPIOD_IRLED) |                   \
                                     PIN_MODE_OUTPUT(GPIOD_LED4) |          \
                                     PIN_MODE_OUTPUT(GPIOD_LED3) |          \
                                     PIN_MODE_OUTPUT(GPIOD_LED5) |          \
                                     PIN_MODE_OUTPUT(GPIOD_LED6))
#define VAL_GPIOD_OTYPER            0x00000000
#define VAL_GPIOD_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOD_PUPDR             (PIN_PUDR_PULLUP(0) |                   \
                                     PIN_PUDR_PULLUP(1) |                   \
                                     PIN_PUDR_PULLUP(2) |                   \
                                     PIN_PUDR_PULLUP(3) |                   \
                                     PIN_PUDR_FLOATING(GPIOD_RESET) |       \
                                     PIN_PUDR_FLOATING(GPIOD_OVER_CURRENT) |\
                                     PIN_PUDR_PULLUP(6) |                   \
                                     PIN_PUDR_PULLUP(7) |                   \
                                     PIN_PUDR_PULLUP(8) |                   \
                                     PIN_PUDR_PULLUP(9) |                   \
                                     PIN_PUDR_PULLUP(10) |                  \
                                     PIN_PUDR_FLOATING(GPIOD_IRLED) |                  \
                                     PIN_PUDR_FLOATING(GPIOD_LED4) |        \
                                     PIN_PUDR_FLOATING(GPIOD_LED3) |        \
                                     PIN_PUDR_FLOATING(GPIOD_LED5) |        \
                                     PIN_PUDR_FLOATING(GPIOD_LED6))
#define VAL_GPIOD_ODR               0x00000FCF
#define VAL_GPIOD_AFRL              0x00000000
#define VAL_GPIOD_AFRH              0x00000000

/*
 * Port E setup.
 * All input with pull-up except:
 * PE0  - GPIOE_INT1                (input floating).
 * PE1  - GPIOE_INT2                (input floating).
 * PE3  - GPIOE_CS_SPI              (output push-pull).
 * from PE7 to PE15 output push-pull.
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_INT1) |           \
                                     PIN_MODE_INPUT(GPIOE_INT2) |           \
                                     PIN_MODE_INPUT(2) |                    \
                                     PIN_MODE_OUTPUT(GPIOE_CS_SPI) |        \
                                     PIN_MODE_INPUT(4) |                    \
                                     PIN_MODE_INPUT(5) |                    \
                                     PIN_MODE_INPUT(6) |                    \
                                     PIN_MODE_OUTPUT(7) |                    \
                                     PIN_MODE_OUTPUT(8) |                    \
                                     PIN_MODE_OUTPUT(9) |                    \
                                     PIN_MODE_OUTPUT(10) |                   \
                                     PIN_MODE_OUTPUT(11) |                   \
                                     PIN_MODE_OUTPUT(12) |                   \
                                     PIN_MODE_OUTPUT(13) |                   \
                                     PIN_MODE_OUTPUT(14) |                   \
                                     PIN_MODE_OUTPUT(15))
#define VAL_GPIOE_OTYPER            0x00000000
#define VAL_GPIOE_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOE_PUPDR             (PIN_PUDR_FLOATING(GPIOE_INT1) |        \
                                     PIN_PUDR_FLOATING(GPIOE_INT2) |        \
                                     PIN_PUDR_PULLUP(2) |                   \
                                     PIN_PUDR_FLOATING(GPIOE_CS_SPI) |      \
                                     PIN_PUDR_PULLUP(4) |                   \
                                     PIN_PUDR_PULLUP(5) |                   \
                                     PIN_PUDR_PULLUP(6) |                   \
                                     PIN_PUDR_FLOATING(7) |                   \
                                     PIN_PUDR_FLOATING(8) |                   \
                                     PIN_PUDR_FLOATING(9) |                   \
                                     PIN_PUDR_FLOATING(10) |                  \
                                     PIN_PUDR_FLOATING(11) |                  \
                                     PIN_PUDR_FLOATING(12) |                  \
                                     PIN_PUDR_FLOATING(13) |                  \
                                     PIN_PUDR_FLOATING(14) |                  \
                                     PIN_PUDR_FLOATING(15))
#define VAL_GPIOE_ODR               0xFFFFFFFF
#define VAL_GPIOE_AFRL              0x00000000
#define VAL_GPIOE_AFRH              0x00000000

/*
 * Port F setup.
 * All input with pull-up.
 */
#define VAL_GPIOF_MODER             0x00000000
#define VAL_GPIOF_OTYPER            0x00000000
#define VAL_GPIOF_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOF_PUPDR             0xFFFFFFFF
#define VAL_GPIOF_ODR               0xFFFFFFFF
#define VAL_GPIOF_AFRL              0x00000000
#define VAL_GPIOF_AFRH              0x00000000

/*
 * Port G setup.
 * All input with pull-up.
 */
#define VAL_GPIOG_MODER             0x00000000
#define VAL_GPIOG_OTYPER            0x00000000
#define VAL_GPIOG_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOG_PUPDR             0xFFFFFFFF
#define VAL_GPIOG_ODR               0xFFFFFFFF
#define VAL_GPIOG_AFRL              0x00000000
#define VAL_GPIOG_AFRH              0x00000000

/*
 * Port H setup.
 * All input with pull-up except:
 * PH0  - GPIOH_OSC_IN          (input floating).
 * PH1  - GPIOH_OSC_OUT         (input floating).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(2) |                    \
                                     PIN_MODE_INPUT(3) |                    \
                                     PIN_MODE_INPUT(4) |                    \
                                     PIN_MODE_INPUT(5) |                    \
                                     PIN_MODE_INPUT(6) |                    \
                                     PIN_MODE_INPUT(7) |                    \
                                     PIN_MODE_INPUT(8) |                    \
                                     PIN_MODE_INPUT(9) |                    \
                                     PIN_MODE_INPUT(10) |                   \
                                     PIN_MODE_INPUT(11) |                   \
                                     PIN_MODE_INPUT(12) |                   \
                                     PIN_MODE_INPUT(13) |                   \
                                     PIN_MODE_INPUT(14) |                   \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOH_OTYPER            0x00000000
#define VAL_GPIOH_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOH_PUPDR             (PIN_PUDR_FLOATING(GPIOH_OSC_IN) |      \
                                     PIN_PUDR_FLOATING(GPIOH_OSC_OUT) |     \
                                     PIN_PUDR_PULLUP(2) |                   \
                                     PIN_PUDR_PULLUP(3) |                   \
                                     PIN_PUDR_PULLUP(4) |                   \
                                     PIN_PUDR_PULLUP(5) |                   \
                                     PIN_PUDR_PULLUP(6) |                   \
                                     PIN_PUDR_PULLUP(7) |                   \
                                     PIN_PUDR_PULLUP(8) |                   \
                                     PIN_PUDR_PULLUP(9) |                   \
                                     PIN_PUDR_PULLUP(10) |                  \
                                     PIN_PUDR_PULLUP(11) |                  \
                                     PIN_PUDR_PULLUP(12) |                  \
                                     PIN_PUDR_PULLUP(13) |                  \
                                     PIN_PUDR_PULLUP(14) |                  \
                                     PIN_PUDR_PULLUP(15))
#define VAL_GPIOH_ODR               0xFFFFFFFF
#define VAL_GPIOH_AFRL              0x00000000
#define VAL_GPIOH_AFRH              0x00000000

/*
 * Port I setup.
 * All input with pull-up.
 */
#define VAL_GPIOI_MODER             0x00000000
#define VAL_GPIOI_OTYPER            0x00000000
#define VAL_GPIOI_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOI_PUPDR             0xFFFFFFFF
#define VAL_GPIOI_ODR               0xFFFFFFFF
#define VAL_GPIOI_AFRL              0x00000000
#define VAL_GPIOI_AFRH              0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
