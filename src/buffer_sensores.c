/*
 * buffer_circular.c
 *
 *  Created on: Dec 7, 2020
 *      Author: Ignacio Moya
 */
#include "../inc/buffer_sensores.h"
#include "sapi.h"

char buffer[SIZE_BUFFER][LONG_CADENA] = {0};

void buffer_init();

int puntero_buf;
void buffer_init()
{
	puntero_buf = 0;
}

char * buffer_escribir_string()
{
	if(SIZE_BUFFER == puntero_buf)
	{
		return 0; //Error buffer lleno.
	}
	char * buf = buffer[puntero_buf];
	puntero_buf++;
	return buf;
}

char * buffer_leer_string()
{
	if(0 == puntero_buf)
	{
		return 0; //buffer vacío.
	}
	char * buf = buffer[puntero_buf];
	puntero_buf--;
	return buf;
}
