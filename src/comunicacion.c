/*
 * comunicacion.c
 *
 *  Created on: Dec 7, 2020
 *      Author: freesbee
 */
#include "../inc/comunicacion.h"
#include "sapi.h"

void comm_init()
{
	uartConfig( UART_USB, 115200 );
}

#define COMM_FREQ 1
#define COMM_OFFSET 0

int comm_enviar_string(char* cadena)
{
	static uint32_t tiempo = 0;
	if(tiempo < COMM_FREQ + COMM_OFFSET)
	{
		tiempo++;
		return 0;
	}
	else
	{
		tiempo = COMM_OFFSET;
	}

	if(0 == cadena)
	{
		return -1;
	}
	else
	{
		uartWriteString(UART_USB, cadena);
		return 0;
	}

}
