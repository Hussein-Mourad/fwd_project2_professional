/*
 * Types.h
 *
 * Created: 11/12/2022 02:36:51
 *  Author: es-HusseinMourad2024
 */ 


#ifndef TYPES_H_
#define TYPES_H_

//Macros
#define  PORT_SIZE   8

#define   C          0
#define   Z          1
#define   N          2
#define   V          3
#define   S          4
#define   H          5
#define   T          6
#define   I          7

// Defined Types
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} EN_Port;

typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
} EN_Pin;

typedef enum
{
	LOW,
	HIGH
} BOOL;

typedef unsigned char        uint8_t;
typedef unsigned short int   uint16_t;
typedef unsigned long long   uint32_t;
typedef signed char          int8_t;
typedef signed short int     int16_t;
typedef signed long long    int32_t;

#endif /* TYPES_H_ */