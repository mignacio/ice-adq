/*
 * sensores.c
 *
 *  Created on: Dec 7, 2020
 *      Author: freesbee
 */
#include "../inc/sensores.h"
#include "../inc/buffer_sensores.h"
#include "sapi.h"
#include <stdio.h>

const uint8_t size_sensores = (uint8_t)(sizeof(sensores) / sizeof(sensor_t)) - 1;
sensor_t temp_admision;
sensor_t temp_escape;
sensor_t presion_aceite;
sensor_t sensor_oxigeno;

const sensor_t *sensores[4] =
			{&temp_admision, &temp_escape, &presion_aceite, &sensor_oxigeno};

int temp_adm_to_string(char *cadena, uint8_t size)
{
	if(0 == cadena)
	{
		return -1;
	}
	int resultado =
			snprintf(cadena, size, "Temp Adm: %u °C\r\n", temp_admision.valor_crudo);
	return resultado;
}

void temp_adm_conv()
{
	temp_admision.valor_crudo = adcRead(CH1);
	temp_adm_to_string(buffer_escribir_string(), LONG_CADENA);
}

int temp_esc_to_string(char *cadena, uint8_t size)
{
	if(0 == cadena)
	{
		return -1;
	}
	int resultado =
			snprintf(cadena, size, "Temp Esc: %u °C\r\n", temp_escape.valor_crudo);
	return resultado;
}

void temp_esc_conv()
{
	temp_escape.valor_crudo = adcRead(CH1);
	temp_esc_to_string(buffer_escribir_string(), LONG_CADENA);
}

int presion_aceite_to_string(char *cadena, uint8_t size)
{
	if(0 == cadena)
	{
		return -1;
	}
	int resultado =
			snprintf(cadena, size, "Presion Aceite: %u PSI\r\n", presion_aceite.valor_crudo);
	return resultado;
}

void presion_aceite_conv()
{
	presion_aceite.valor_crudo = adcRead(CH2);
	presion_aceite_to_string(buffer_escribir_string(), LONG_CADENA);
}

int sensor_oxigeno_to_string(char *cadena, uint8_t size)
{
	if(0 == cadena)
	{
		return -1;
	}
	int resultado =
			snprintf(cadena, size, "Oxigeno: %u\r\n", sensor_oxigeno.valor_crudo);
	return resultado;
}

void sensor_oxigeno_conv()
{
	sensor_oxigeno.valor_crudo = adcRead(CH3);
	sensor_oxigeno_to_string(buffer_escribir_string(), LONG_CADENA);
}



void sensores_init()
{
	/** Init sensor de temperatura de gases de admision */
	temp_admision.flag_listo = FALSE;
	temp_admision.tiempo_muestreo = 1000;
	temp_admision.tiempo_offset = 100;
	temp_admision.valor_crudo = 0;
	temp_admision.valor = 0;
	temp_admision.convertir = temp_adm_conv;
	temp_admision.to_string = temp_adm_to_string;

	/** Init sensor de temperatura de gases de escape */
	temp_escape.flag_listo = FALSE;
	temp_escape.tiempo_muestreo = 1000;
	temp_escape.tiempo_offset = 200;
	temp_escape.valor_crudo = 0;
	temp_escape.valor = 0;
	temp_escape.convertir = temp_esc_conv;
	temp_escape.to_string = temp_esc_to_string;

	/** Init sensor de presión de aceite*/
	presion_aceite.flag_listo = FALSE;
	presion_aceite.tiempo_muestreo = 2000;
	presion_aceite.tiempo_offset = 300;
	presion_aceite.valor_crudo = 0;
	presion_aceite.valor = 0;
	presion_aceite.convertir = presion_aceite_conv;
	presion_aceite.to_string = presion_aceite_to_string;

	/** Init sensor de oxigeno*/
	sensor_oxigeno.flag_listo = FALSE;
	sensor_oxigeno.tiempo_muestreo = 5000;
	sensor_oxigeno.tiempo_offset = 400;
	sensor_oxigeno.valor_crudo = 0;
	sensor_oxigeno.valor = 0;
	sensor_oxigeno.convertir = sensor_oxigeno_conv;
	sensor_oxigeno.to_string = sensor_oxigeno_to_string;

	adcConfig(ADC_ENABLE);
}


