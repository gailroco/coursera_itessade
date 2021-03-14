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


/* Functions: Array handling */
/**
 * @brief Method that prints an array
 *
 * @param <ptr> Pointer to the data array, 
 * @param <n>   Array length
 * 
 * @return N/A
*/
void print_array(unsigned char * ptr, unsigned int n);

/**
 * @brief Method that sorts and prints an array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * @param <ORD>   Order ascending - 'A' or descending - else
 * @param <PRINT> Print or not the ordered array
 * 
 * @return N/A
*/
void sort_array(unsigned char * ptr, unsigned int n, char ORD, char PRINT);

/* Functions: Compute statistics */
/**
 * @brief Function that computes the median of the data array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> Median statistic
*/
unsigned char find_median(unsigned char * arr, unsigned int n);

/**
 * @brief Function that computes the mean of the data array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> mean statistic
*/
unsigned char find_mean(unsigned char * arr, unsigned int n);

/**
 * @brief Function that finds the maximum of the array
 *
 * @param <ptr>         Pointer to the data array, 
 * @param <n>           Array length
 * 
 * @return <ptr[n - 1]> Get maximum
*/
unsigned char find_maximum(unsigned char * arr, unsigned int n);

/**
 * @brief Function that finds the minimum of the array
 *
 * @param <ptr>         Pointer to the data array, 
 * @param <n>           Array length
 * 
 * @return <ptr[n - 1]> Get minimum
*/
unsigned char find_minimum(unsigned char * arr, unsigned int n);

/**
 * @brief Method that computes and prints data statistics
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return N/A
*/
void print_statistics(unsigned char * arr, unsigned int n);

/* Functions: Utilities */

/**
 * @brief Function that sums the elements of the array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> Sum
*/
long sum(unsigned char * ptr, unsigned int n);

/**
 * @brief Function that sorts an array in ascending or descending order
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * @param <ORD>   Order mode (ascending - 'A' or descending - else)
 * 
 * @return N/A
*/
void bubbleSort(unsigned char * ptr, int n, char ORD);
