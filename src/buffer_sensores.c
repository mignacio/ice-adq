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

int puntero_lect;
int puntero_escr;

void buffer_init()
{
	puntero_lect = 0;
	puntero_escr = 0;
}

char * buffer_escribir_string()
{

	char * buf = &buffer[puntero_escr][0];

	if(puntero_escr >= SIZE_BUFFER)
	{
		puntero_escr = 0;
	}
	else
	{
		puntero_escr++;
	}
	return buf;
}

char * buffer_leer_string()
{
	if(puntero_lect == puntero_escr)
	{
		return 0; //buffer vacio
	}

	char * buf = &buffer[puntero_lect][0];

	if(puntero_lect >= SIZE_BUFFER)
	{
		puntero_lect = 0;
	}
	else
	{
		puntero_lect++;
	}
	return buf;
}
