/*
 * INT_interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */

#ifndef MCAL_INTERRUPTS_INT_INTERFACE_H_
#define MCAL_INTERRUPTS_INT_INTERFACE_H_

/** OPTIONS for
 * 2-Interrupts
 *
 *   1-EXT_INT_SC_INT0 0
 *   2-EXT_INT_SC_INT1 1
 *   3-EXT_INT_SC_INT2 2
 *
 * 2- events
 * INT0,INT1 UESD :
 * ENABLE
 *    1-EXT_INT_SC_LOW_LEVEL
 *    2-EXT_INT_SC_ANY_CHANGE
 *    3-EXT_INT_SC_FALLING_EDGE
 *    4-EXT_INT_SC_RISING_EDGE
 *
 * DISABLE
 *    5-EXT_INT_SC_DISABLE
 *
 * INT2 UESD :
 * ENABLE
 *    1-EXT_INT2_SC_RISING_EDGE
 *    2-EXT_INT2_SC_FALLING_EDGE
 *
 * DISABLE
 *    3-EXT_INT_SC_DISABLE
 */

/* ------------ DATA TYPES ------------*/

/*func to ptr to save ISR*/
typedef struct {
	FUNC_PTR EXT_ISR_INT0;
	FUNC_PTR EXT_ISR_INT1;
	FUNC_PTR EXT_ISR_INT2;
} EXT_INT_func;

/*struct to save data from user*/
typedef struct {
	u8 EXT_INT_SC_INT0_;
	u8 EXT_INT_SC_INT1_;
	u8 EXT_INT_SC_INT2_;
	u8 EXT_INT_SC_STATE0;
	u8 EXT_INT_SC_STATE1;
	u8 EXT_INT_SC_STATE2;

} EXT_INT;

/* ------------ Macros Declaration ------------*/

/*FOR INT1 AND INT0*/
#define EXT_INT_SC_LOW_LEVEL     0x00
#define EXT_INT_SC_ANY_CHANGE    0x01
#define EXT_INT_SC_FALLING_EDGE  0x02
#define EXT_INT_SC_RISING_EDGE   0x03
#define EXT_INT_SC_DISABLE       0xFF

/*FOR INT2*/
#define EXT_INT2_SC_FALLING_EDGE 0x00
#define EXT_INT2_SC_RISING_EDGE  0x40


#define EXT_INT_SC_INT0 0
#define EXT_INT_SC_INT1 1
#define EXT_INT_SC_INT2 2
/* ------------ software interface Declaration ------------*/
void EXT_INT_initial(EXT_INT *copy_inter, EXT_INT_func *copy_func);

#endif /* MCAL_INTERRUPTS_INT_INTERFACE_H_ */
