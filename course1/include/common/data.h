/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Week 4 Assignment> 
 * @brief <My solution to Week 4 assignment>
 *
 * <I am taking "Introduction to Embedded Systems Software and development environments"
 * course and this is my solution to "Peer-graded Assignment: Week 4 Application Assignment">
 *
 * @author <Frida Rojas>
 * @date <Mar 14th 2021>
 *
 */

#ifndef __STATS_H__
#define __STATS_H__
#endif /* __STATS_H__ */

#define BASE_16 (16)
#define BASE_10 (10)
#define BASE_2  (2)

#include <stdint.h> // Include Integer pre-defined types: "uint8_t", "int32_t" and "uint32_t"
#include "memory.h"

/**
 * @brief My implementation of itoa
 *
 * Function to convert signed integer numbers of any base to ASCII representation and returns number of digits.
 * For example,
 * > input = -4096 to ASCII base 16 is output = "-1000\0"_(16). ASCII representation has 4 digits.
 * > input = 123456 to ASCII base 16 is output = "123456\0"_(16). ASCII representation has 6 digits.
 *
 * @param data The number you wish to convert to ASCII.
 * @param ptr Pointer that stores the converted character string.
 * @param base The number base to support.
 *
 * @return uint8_t.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief My implementation of atoi
 *
 * Function to convert signed numbers in ASCII representation to signed integer numbers of a given base
 * and return as a 32-bit signed integer.
 * For example,
 * > input = -4096 to ASCII base 16 is output = "-1000\0"_(16). ASCII representation has 4 digits.
 * > input = 123456 to ASCII base 16 is output = "123456\0"_(16). ASCII representation has 6 digits.
 *
 * @param ptr The ASCII representation number you wish to convert to integer number.
 * @param digits The number of digits within the ASCII representation.
 * @param base The number base to support.
 *
 * @return int32_t.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);