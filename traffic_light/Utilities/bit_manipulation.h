/*
 * bit_manipulation.h
 *
 * Created: 11/12/2022 02:54:49
 *  Author: es-HusseinMourad2024
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(REG, BIT)  (REG |=  (1<<BIT) )
#define CLR_BIT(REG, BIT)  (REG &= ~(1<<BIT) )
#define READ_BIT(REG, BIT)  ((REG>>BIT) & 0x01)
#define TOGGLE_BIT(REG, BIT)  (REG ^=  (1<<BIT) )

#endif /* BIT_MANIPULATION_H_ */