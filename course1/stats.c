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

void find_mean(unsigned char array[], int size){
  
  int avg = 0;
  for(int i = 0; i < size; i++){
    avg += array[i];
  }
  avg = avg / size;
  printf("Mean = %d", avg);
}

void find_median(unsigned char array[], int size){
  
  int median = 0;
  sort_array(array, size);
  
  if (SIZE % 2 == 0){
  median = (array[(size) / 2] + array[(size+1) / 2]) / 2;
  }

  else {
    median = array[(size) / 2];
  }
  
  printf("\nMedian = %d", median);

}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  printarray(test, SIZE);
  printf("\n ");
  printf("After sorting :\n ");
  sort_array(test, SIZE);
  printarray(test, SIZE);


  /* Statistics and Printing Functions Go Here */
  
  find_mean(test,SIZE);
  find_median(test,SIZE);



  return 0;
}

/* Add other Implementation File Code Here */
