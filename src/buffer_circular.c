/*
 * buffer_circular.c
 *
 *  Created on: Dec 7, 2020
 *      Author: Ignacio Moya
 */
#include "buffer_circular.h"


uint16_t puntero_lectura;
uint16_t puntero_escritura;

char * escribir_string();

char * leer_string();

void init_buffer();
