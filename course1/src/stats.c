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
 * @date <Mar 3rd 2021>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stats.h"
#include "platform.h"

/**
 * @brief Method that prints an array
 *
 * @param <ptr> Pointer to the data array, 
 * @param <n>   Array length
 * 
 * @return N/A
*/
void print_array(unsigned char * ptr, unsigned int n){
  for(int i = 0; i < n; i++)
  {
    PRINTF("%d, ",ptr[i]);
    if(i == n - 1)
      PRINTF("%d",ptr[i]);
  }
  PRINTF("\n");
}

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
void sort_array(unsigned char * ptr, unsigned int n, char ORD, char PRINT){
  bubbleSort(ptr, n, ORD);
  if(PRINT == 'Y')
  {
    print_array(ptr, n);
  }
}

/**
 * @brief Function that computes the median of the data array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> Median statistic
*/
unsigned char find_median(unsigned char * ptr, unsigned int n){
  unsigned char result = 0;
  sort_array(ptr, n, 'A', 'N');
  unsigned char m = n / 2;
  if(n % 2 == 0)
  {
    result = (ptr[(m - 1)] + ptr[(m + 1)])/2;
  }else
  {
    int aux = (int)m / 1;
    result = ptr[(unsigned char)aux + 1];
  }
  return result;
}

/**
 * @brief Function that computes the mean of the data array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> Mean statistic
*/
unsigned char find_mean(unsigned char * ptr, unsigned int n){
  long result = sum(ptr, n);
  float res = result / n;
  int aux = (int) res / 1;
  return (unsigned char)aux;
}

/**
 * @brief Function that sums the elements of the array
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return <result> Sum
*/
long sum(unsigned char * ptr, unsigned int n){
  long result = 0;
  for(int i = 0; i < n; i++)
  {
    result = result + ptr[i];
  }
  return result;
}

/**
 * @brief Function that finds the maximum of the array
 *
 * @param <ptr>         Pointer to the data array, 
 * @param <n>           Array length
 * 
 * @return <ptr[n - 1]> Get maximum
*/
unsigned char find_maximum(unsigned char * ptr, unsigned int n){
  sort_array(ptr, n, 'A', 'N');
  return ptr[n - 1];
}

/**
 * @brief Function that finds the minimum of the array
 *
 * @param <ptr>         Pointer to the data array, 
 * @param <n>           Array length
 * 
 * @return <ptr[n - 1]> Get minimum
*/
unsigned char find_minimum(unsigned char * ptr, unsigned int n){
  sort_array(ptr, n, 'A', 'N');
  return ptr[0];
}

/**
 * @brief Method that computes and prints data statistics
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * 
 * @return N/A
*/
void print_statistics(unsigned char * ptr, unsigned int n){
  PRINTF("Median = %d \n", find_median(ptr, n));
  PRINTF("Mean = %d \n", find_mean(ptr, n));
  PRINTF("Min = %d \n", find_minimum(ptr, n));
  PRINTF("Max = %d \n", find_maximum(ptr, n));
}

/**
 * @brief Function that sorts an array in ascending or descending order
 *
 * @param <ptr>   Pointer to the data array, 
 * @param <n>     Array length
 * @param <ORD>   Order mode (ascending - 'A' or descending - else)
 * 
 * @return N/A
*/
void bubbleSort(unsigned char * ptr, int n, char ORD) 
{
    for(int k = 0; k < (n - 1); ++k){
    for(int j = 0; j < (n - k - 1); ++j){
      // Sort in ASC (>) & DSC order (<)
      bool cond = (ORD ==  'A') ? (ptr[j] > ptr[j + 1]) : (ptr[j] < ptr[j + 1]);
      if (cond){
        int aux = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = aux;
      }
    }
  }
}
