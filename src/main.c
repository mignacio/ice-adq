/*=============================================================================
 * Copyright (c) 2019, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE file)
 * Date: 2019/05/03
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"
#include "sensores.h"
#include "buffer_sensores.h"
#include "comunicacion.h"

int main(void)
{
   // ----- Setup -----------------------------------
	boardInit();

	delay_t sys_clock;
	delayInit(&sys_clock, 10);
	sensores_init();
	comm_init();
	buffer_init();

	uartWriteString(UART_USB, "init listo\r\n");
   // ----- Repeat for ever -------------------------

   while(TRUE)
   {
	   if(delayRead(&sys_clock))
	   {
		   comm_enviar_string(buffer_leer_string());

		   for(int indx = 0; indx < CANT_SENSORES; indx++)
		   {
			   sensores[indx]->convertir();
		   }
	   }
   }
   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

