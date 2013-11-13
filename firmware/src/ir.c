/*
 * Firmware for the robot Spykee, for the STM32F4xx board
 *
 * Copyright (C) 2012 Politecnico di Milano
 * Copyright (C) 2012 Marcello Pogliani, Davide Tateo
 * Versione 1.0
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "FirmwareSpykee.h"

#define ADC_NUM_CHANNELS 4
#define ADC_BUF_DEPTH 1

typedef struct {
	adcsample_t north;
	adcsample_t south;
	adcsample_t west;
	adcsample_t east;
} IrData;

/* ADC buffer. */
static IrData ir_data = { 0, 0, 0, 0 };

/*
 * ADC conversion group.
 * Mode:        Continuous, 1 samples of 4 channels.
 * Channels:    IN11, IN12, IN14, IN15.
 */
static const ADCConversionGroup adc_grpcfg = {
		TRUE,
		ADC_NUM_CHANNELS,
		NULL,
		NULL,
		0, /* CR1 */
		ADC_CR2_SWSTART, /* CR2 */
		ADC_SMPR1_SMP_AN15(ADC_SAMPLE_144) | ADC_SMPR1_SMP_AN14(ADC_SAMPLE_144)
				| ADC_SMPR1_SMP_AN12(ADC_SAMPLE_144)
				| ADC_SMPR1_SMP_AN11(ADC_SAMPLE_144),  /* SMPR1 */
		0, /* SMPR2 */
		ADC_SQR1_NUM_CH(ADC_NUM_CHANNELS),
		0, /* SQR2 */
		ADC_SQR3_SQ4_N(ADC_CHANNEL_IN15) | ADC_SQR3_SQ3_N(ADC_CHANNEL_IN14)
				| ADC_SQR3_SQ2_N(ADC_CHANNEL_IN12)
				| ADC_SQR3_SQ1_N(ADC_CHANNEL_IN11) };

static WORKING_AREA(irWorkingArea, 1024);

/* ICU callbacks and data to be used with sonars */

/* Thread used for read data from sonar */
static msg_t irThread(void *arg) {
	(void) arg;
	char buf[40];

	/*
	 * Activates the ADC1 driver.
	 */
	adcStart(&ADCD1, NULL);
	adcStartConversion(&ADCD1, &adc_grpcfg, (adcsample_t *)&ir_data, ADC_BUF_DEPTH);

	while (TRUE) {
		chsprintf(buf, "[IR] N:%d,S:%d,W:%d,E:%d", ir_data.north, ir_data.south,
				ir_data.west, ir_data.east);

		bufferPutString(&outputBuffer, buf);
		chThdSleepMilliseconds(50);
	}

	return 0;
}

void startIrThread(void) {
	chThdCreateStatic(irWorkingArea, sizeof(irWorkingArea), NORMALPRIO,
			irThread, NULL);
}

