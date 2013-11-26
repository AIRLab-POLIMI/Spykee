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

static WORKING_AREA(rfidWorkingArea, 1024);

/* Thread used to manage rfid Reader*/
static msg_t rfidThread(void *arg)
{
	(void) arg;
	const int rfidMessageSize = 16;
	const int rfidBitrate = 9600;

	SerialConfig config =
	{ rfidBitrate, 0, USART_CR2_STOP1_BITS | USART_CR2_LINEN, 0 };
	char buf[rfidMessageSize + 2]; //This buffer's size is too big, just for safety
	char buf2[rfidMessageSize + 10]; //This buffer's size is too big, just for safety

	sdStart(&SD3, &config);
	while (TRUE)
	{
		sdRead(&SD3, (uint8_t*) buf, sizeof(buf)-2);
		/* Specification of the ID-12 output data format (ASCII):
		 * STX (0x02) | DATA (10 ASCII chars) | CHECKSUM (2 ASCII) | CR | LF | ETX (0x03)
		 * We transmit from here only the data and the checksum. The checksum is not checked
		 * on board, but will be checked on the computer. The checksum is the xor of
		 * the 5 hex bytes (10 ascii) DATA characters.
		 */
		/* this is rather ugly (using two buffers...) but for now it works as expected */

		int stxIndex, crIndex;

		// Search for the STX character
		for (stxIndex = 0; buf[stxIndex] != '\x02'; stxIndex++);

		//Search for the CR character
		for (crIndex = stxIndex; buf[crIndex] != '\r'; crIndex++);

		if (crIndex - stxIndex == 13)
		{
			buf[crIndex] = '\0'; // strip the trailing CR, LF, ETX
			chsprintf(buf2, "[RFID] %s", buf + stxIndex + 1); // +1 to strip the leading STX char

			bufferPutString(&outputBuffer, buf2);
		}
		//flush the buffers
		buf[0] = '\0';
		buf2[0] = '\0';
	}
	return 0;
}

void startRfidThread(void)
{
	chThdCreateStatic(rfidWorkingArea, sizeof(rfidWorkingArea), NORMALPRIO,
			rfidThread, NULL );
}
