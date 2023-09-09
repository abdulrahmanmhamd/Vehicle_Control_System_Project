/*
 * INT_program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */

/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include "INT_private.h"
#include "INT_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\global_interrupt\GINT_interface.h"

void __vector_1(void)__attribute__((signal,used));
void __vector_2(void)__attribute__((signal,used));
void __vector_3(void)__attribute__((signal,used));

EXT_INT_func Global_ISR_fun;

/* ------------ software interface Declaration ------------*/

void EXT_INT_initial(EXT_INT *copy_inter, EXT_INT_func *copy_func) {



		if (copy_inter->EXT_INT_SC_INT0_ == EXT_INT_SC_INT0) {
			if (copy_inter->EXT_INT_SC_STATE0 != EXT_INT_SC_DISABLE) {

				/*make global enable*/
				G_INT_Enable();

				/*set PIE GICR set INT0 bit*/
				SET_BIT(GICR_REG, EXT_INT_GICR_INT0_BIT);

				/*config ISC*/
				MCUCR_REG |= copy_inter->EXT_INT_SC_STATE0;


				/*GENRATE ISR*/
				Global_ISR_fun.EXT_ISR_INT0 = copy_func->EXT_ISR_INT0;
			}
			else {
				/*no operation*/
			}

		} else {
			/*no operation*/
		}

		if (copy_inter->EXT_INT_SC_INT1_ == EXT_INT_SC_INT1) {
			if (copy_inter->EXT_INT_SC_STATE1 != EXT_INT_SC_DISABLE) {

				/*make global enable*/
				G_INT_Enable();

				/*set PIE GICR set INT0 bit*/
				SET_BIT(GICR_REG, EXT_INT_GICR_INT1_BIT);

				/*config ISC*/
				MCUCR_REG |= copy_inter->EXT_INT_SC_STATE1;


				/*GENRATE ISR*/
				Global_ISR_fun.EXT_ISR_INT1 = copy_func->EXT_ISR_INT1;
			} else {
				/*no operation*/
			}
		} else {
			/*no operation*/
		}

		if (copy_inter->EXT_INT_SC_INT2_ == EXT_INT_SC_INT2) {
			if (copy_inter->EXT_INT_SC_STATE2 != EXT_INT_SC_DISABLE) {

				/*make global enable*/
				G_INT_Enable();

				/*set PIE GICR set INT0 bit*/
				SET_BIT(GICR_REG, EXT_INT_GICR_INT2_BIT);

				/*config ISC*/
				MCUCSR_REG |= copy_inter->EXT_INT_SC_STATE2;

				/*GENRATE ISR*/
				Global_ISR_fun.EXT_ISR_INT2 = copy_func->EXT_ISR_INT2;

			}
			else {
				/*no operation*/
			}
		}
		else {
			/*no operation*/
		}
	}



/*ISR0*/
void __vector_1(void) {
	Global_ISR_fun.EXT_ISR_INT0();
}

/*ISR1*/
void __vector_2(void) {
	Global_ISR_fun.EXT_ISR_INT1();
}

/*ISR2*/
void __vector_3(void){
	Global_ISR_fun.EXT_ISR_INT2();
}

