/*
 * sensores.h
 *
 *  Created on: Dec 7, 2020
 *      Author: Ignacio Moya
 */

#ifndef PRE_CESE_ICE_ADQ_INC_SENSORES_H_
#define PRE_CESE_ICE_ADQ_INC_SENSORES_H_

#include "sapi.h"

#define CANT_SENSORES 4

typedef struct sensor_t
{
	bool flag_listo;
	uint16_t tiempo_muestreo; //en decenas de milisegundos
	uint16_t tiempo_offset; //en decenas de milisegundos
	uint16_t valor_crudo;
	double valor;
	void (* convertir)();
	int (* to_string)(char *cadena, uint8_t size);
}sensor_t;

const sensor_t *sensores[4];
const uint8_t size_sensores;

void sensores_init();

#endif /* PRE_CESE_ICE_ADQ_INC_SENSORES_H_ */
