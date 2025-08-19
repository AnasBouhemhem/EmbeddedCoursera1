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
 * @file stats.c
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Anas Bouhemhem
 * @date <17-08-2025>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void printarray(unsigned char array[], int size){
  
  for (int i = 0; i < size; i++){
      printf("%d ", array[i]);
  }
}

void sort_array(unsigned char array[], int size){
  /* Bubble-Sorting first */
  
  for (int i = 0; i < size - 1; i++){ 
    for (int j = 0; j < size - 1; j++)
    {
      if (array[j] < array[j+1])
      {
        char temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

unsigned char find_mean(unsigned char array[], int size){
  
  int avg = 0;
  for(int i = 0; i < size; i++){
    avg += array[i];
  }
  avg = avg / size;
  return avg;
}

unsigned char find_median(unsigned char array[], int size){
  
  int median = 0;
  sort_array(array, size);
  
  if (SIZE % 2 == 0){
  median = (array[(size) / 2] + array[(size+1) / 2]) / 2;
  }
  else {
    median = array[(size) / 2];
  }
  
  return median;

}

unsigned char find_maximum(unsigned char array[], int size){
  
  sort_array(array, size);
  return array[0];
}

unsigned char find_minimum(unsigned char array[], int size){
  
  sort_array(array, size);
  return array[size-1];
}

void print_statistics(unsigned char array[], int size){
  
  unsigned char min = 0;
  unsigned char max = 0;
  int avg = 0;
  int median = 0;

  sort_array(array, size);
  
  min = array[size-1];
  max = array[0];

  
  for(int i = 0; i < size; i++){
    avg += array[i];
  }
  avg = avg / size;
  
  if (SIZE % 2 == 0){
  median = (array[(size) / 2] + array[(size+1) / 2]) / 2;
  }
  else {
    median = array[(size) / 2];
  }
  
  printf("\nMin = %d\n", min);
  printf("Max = %d\n", max);
  printf("Mean = %d", avg);
  printf("\nMedian = %d\n", median);

}


void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */


  /* Statistics and Printing Functions Go Here */
  
  unsigned char med = find_median(test,SIZE);
  unsigned char avg = find_mean(test,SIZE);
  unsigned char max = find_maximum(test,SIZE);
  unsigned char min = find_minimum(test,SIZE);

  printf("\n%d", med);
  printf("\n%d", avg);
  printf("\n%d", max);
  printf("\n%d", min);

  print_statistics(test,SIZE);

  return 0;
}

/* Add other Implementation File Code Here */
