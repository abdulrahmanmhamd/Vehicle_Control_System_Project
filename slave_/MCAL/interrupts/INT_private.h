/*
 * INT_private.h
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */

#ifndef MCAL_INTERRUPTS_INT_PRIVATE_H_
#define MCAL_INTERRUPTS_INT_PRIVATE_H_

#define GICR_REG  (*(volatile u8*)0x5B)

#define EXT_INT_GICR_INT2_BIT 5
#define EXT_INT_GICR_INT0_BIT 6
#define EXT_INT_GICR_INT1_BIT 7

#define GIFR_REG  (*(volatile u8*)0x5A)

#define EXT_INT_GIFR_INTF2_BIT 5
#define EXT_INT_GIFR_INTF0_BIT 6
#define EXT_INT_GIFR_INTF1_BIT 7

#define MCUCR_REG (*(volatile u8*)0x55)

#define EXT_INT_MCUCR_ISC00_BIT 0
#define EXT_INT_MCUCR_ISC01_BIT 1
#define EXT_INT_MCUCR_ISC10_BIT 2
#define EXT_INT_MCUCR_ISC11_BIT 3


#define MCUCSR_REG (*(volatile u8*)0x54)

#define EXT_INT_MCUCSR_ISC2_BIT 6



#endif /* MCAL_INTERRUPTS_INT_PRIVATE_H_ */
