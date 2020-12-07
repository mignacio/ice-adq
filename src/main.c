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
	sensores_init();
	comm_init();
	buffer_init();
	schedulerInit();

	uint32_t contador = 0;
   // ----- Repeat for ever -------------------------
   while(true)
   {
	   delay(1);
	   contador++;
   }
   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

