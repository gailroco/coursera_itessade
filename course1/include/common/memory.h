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

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h> // Include Integer pre-defined types: "uint8_t" and "int32_t"
#include <stdlib.h> // Include type "size_t"

/**
 * @brief My implementation of memory movement
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to move from the source location to the destination.
 * Overlap is considered.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Number of elements to be moved from source to destination.
 *
 * @return uint8_t *.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief My implementation of memory copy
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to copy from the source location to the destination.
 * Copy should occur despite overlap case.
 * 
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Number of elements to copy from src to dst.
 *
 * @return uint8_t *.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief My implementation of memory set
 *
 * This function sets a number of "length" bytes from a source memory location to a given value.
 * 
 * @param src Pointer to source memory location
 * @param length Number of elements to be set to a given value.
 * @param value Specific value to set
 *
 * @return uint8_t *.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief My implementation of memory zero
 *
 * This function sets a number of "length" bytes from a source memory location to zero.
 *
 * @param src Pointer to source memory location
 * @param length Number of elements to set to zero
 *
 * @return uint8_t *.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief My implementation of my reverse
 *
 * Reverses the order of a number of "length" elements from src memory location.
 *
 * @param src Pointer to source memory location
 * @param length Number of elements un source memory location.
 *
 * @return uint8_t *.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief My implementation of my reserve_words
 *
 * Allocate dinamically a number of "length" bytes and considering successful and non-succesfull case.
 *
 * @param length Number of bytes to allocate.
 *
 * @return int32_t *.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief My implementation of my free_words
 *
 * Function to free allocated pointers.
 *
 * @param src Pointer name to free.
 *
 * @return void.
 */
void free_words(uint32_t * src);

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */

