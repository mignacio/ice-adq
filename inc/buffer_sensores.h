/*
 * buffer_circular.h
 *
 *  Created on: Dec 7, 2020
 *      Author: freesbee
 */

#ifndef PRE_CESE_ICE_ADQ_INC_BUFFER_SENSORES_H_
#define PRE_CESE_ICE_ADQ_INC_BUFFER_SENSORES_H_

#define SIZE_BUFFER 20
#define LONG_CADENA 128

char * buffer_escribir_string();

char * buffer_leer_string();

void buffer_init();

#endif /* PRE_CESE_ICE_ADQ_INC_BUFFER_SENSORES_H_ */
