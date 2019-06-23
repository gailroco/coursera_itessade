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
 * @file <Week 1 Assignment> 
 * @brief <My solution to Week 1 assignment>
 *
 * <I am taking "Introduction to Embedded Systems Software and development environments"
 * course and this is my solution to "Peer-graded Assignment: Week 1 Application Assignment">
 *
 * @author <Frida Rojas>
 * @date <Sunday, June 23th 2019>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  char * aux = (unsigned char *) malloc(SIZE);
  memcpy(aux, test, SIZE) ;
  /* Statistics and Printing Functions Go Here */
  print_array(aux, SIZE);
  sort_array(aux, SIZE);
  find_median(aux, SIZE);
  find_mean(aux, SIZE);
  find_maximum(aux, SIZE);
  find_minimum(aux, SIZE);
  print_statistics(aux, SIZE);
  
  //printf
}

/* Add other Implementation File Code Here */
void print_array(unsigned char * ptr, unsigned int n){
  for(int index=0; index<n;index++)
  {
    printf("%d ,",&ptr[index]);
  }
}

void sort_array(unsigned char * ptr, unsigned int n){
  quickSort(ptr, 0, n-1);
  print_array(ptr, n);
}

unsigned char find_median(unsigned char * arr, unsigned int n){
  unsigned char result = 0;
  return result;
}

unsigned char find_mean(unsigned char * arr, unsigned int n){
  unsigned char result = 0;
  return result;
}

unsigned char find_maximum(unsigned char * arr, unsigned int n){
  unsigned char result = 0;
  return result;
}

unsigned char find_minimum(unsigned char * arr, unsigned int n){
  unsigned char result = 0;
  return result;
}

void print_statistics(unsigned char * arr, unsigned int n){
  unsigned char result = 0;
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (unsigned char arr[], int low, int high) 
{ 
    unsigned char pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(unsigned char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

