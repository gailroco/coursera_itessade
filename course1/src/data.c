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

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "platform.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint8_t ctr_char = 0;
    my_memzero(ptr, 8);
    if (data != 0){ // Nothing to do in any base if data = 0.
        if (data < 0){ // If negative number, reserve 1 character for minus sign.
            data *= -1;
            *ptr = '-';
            ptr++;
        }

        int32_t aux = data;
        while(aux / base != 0 || aux % base != 0){ // Convert each digit in base X to a char.
            *(ptr + ctr_char) = (aux % base) + '0';            
            aux /= base;
            ctr_char++;
        }
        
        // Above loop performs representation conversion but the digits are backwards, therefore, we need to sort onwards disregarding sign.
        my_reverse(ptr, ctr_char);

        //  Add null aracter at the end.
        *(ptr + ctr_char) = '\0';
    }
    return ctr_char;
}

int32_t my_pow(uint8_t x, uint8_t y){
    int32_t ans = -1;
    if(y != 0){
        ans = x;
        if(y > 1){
            for(int i = 2; i <= y; i++){
                ans *= x;
            }
        }
    }else{
        ans = 1;
    }
    //PRINTF("  Dbg1: x = %d \t y = %d \t pow = %d\n", x, y, ans);
    return ans;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int32_t sum = 0, num;
    int8_t sign = 1;
    int8_t ctr = 0;
    if(*ptr == '-'){
        sign = -1;
        ptr++;
    }
    while (ctr < digits)
    {
        num = *(ptr + ctr) - '0';
        sum+= num * my_pow(base, (digits -1) - ctr);
        //PRINTF("  Dbg2: ctr=%d\tnum=%d\tpow=%d\tsum=%d\n", ctr, num, my_pow(base, (digits -1) - ctr), sum);
        ctr++;
    }
    return sum * sign;
}