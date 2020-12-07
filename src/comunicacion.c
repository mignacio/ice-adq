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

int comm_enviar_string(char* cadena)
{
	if(0 == cadena)
	{
		return -1;
	}
	{
		uartWriteString( UART_USB, cadena );
		return 0;
	}

}
