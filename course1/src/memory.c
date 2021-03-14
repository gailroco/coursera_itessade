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

#include <stdbool.h> // Include Boolean pre-defined type.
#include <stdint.h> // Include Integer pre-defined types: "uint8_t", "int32_t" and "uint32_t"
#include "platform.h"
#include "memory.h"
#include "stats.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  bool COND = src > dst;
  if(COND){ // Need to move values by moving pointers forward.
    // Case: test_memove3() - OVERLAP END OF DEST BEGINNING OF SRC
    PRINTF("DBG: ptra > ptrb\n");
    for(int k = 0; k < length ; k++){
      *(dst + k) = *(src + k);
    }
  }else{ // Need to move values by moving pointers backwards.
    // Case: test_memmove1() -NO OVERLAP
    // Case: test_memmove2() -OVERLAP END OF SRC BEGINNING OF DST
    for(int k = length - 1; k >= 0 ; k--){
      *(dst + k) = *(src + k);
    }
    PRINTF("DBG: ptra < ptrb\n");
  }
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  for(int k = 0; k < length ; k++){
    *(dst + k) = *(src + k);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for(int i = 0; i < length; i++){
    *(src + i) = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  for(int i = 0; i < length; i++){
    *(src + i) = 0;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t tmp = 0, N = length - 1;
  uint8_t half = (length + 1) / 2;
  for (int i = 0; i < half; i++){
    tmp = *(src + (N - i));
    *(src + (N - i)) = *(src + i);
    *(src + i) = tmp;
  }
  return src;
}

int32_t * reserve_words(size_t length){
  return (int32_t *) malloc(length * sizeof(int32_t));
}

void free_words(uint32_t * src){
  free(src);
}

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

