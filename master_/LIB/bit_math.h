/*
 * bit_math.h
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) (REG |= (1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM) (REG &= (~(1<<BIT_NUM)))
#define TOG_BIT(REG,BIT_NUM) (REG ^= (1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM) ((REG>>BIT_NUM)&1)

#endif /* LIB_BIT_MATH_H_ */
