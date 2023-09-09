/*
 * GINT_program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */
/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include"GINT_private.h"
#include"GINT_interface.h"

/* ------------ software interface Declaration ------------*/
void G_INT_Enable()
{
	SET_BIT(G_SREG_INT, G_INT_PIN);
}

void G_INT_Disble()
{
	CLR_BIT(G_SREG_INT, G_INT_PIN);
}

