#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int mergeSort(int*, int, int);
int merge(int*, int, int, int);




int main() {
  int i, arrayLength, *array;
  
  scanf("%d", &arrayLength);
  
  array = malloc(arrayLength * sizeof(int));
  
  for (i = 0; i < arrayLength; i++) {
    array[i] = arrayLength - i;
  }
  
  
  mergeSort(array, 0, arrayLength - 1);
  
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
  
  free(array);
  
  return 0;
}




int mergeSort(int *array, int arrayInit, int arrayEnd) {
  int arrayMid;
  
  if (arrayInit < arrayEnd) {
    arrayMid = (arrayInit + arrayEnd) / 2;
    
    printf("arrayMid = %d\n", arrayMid);
    
    mergeSort(array, arrayInit, arrayMid);
    mergeSort(array, arrayMid + 1, arrayEnd);
    
    merge(array, arrayInit, arrayMid, arrayEnd);
  }
  
  return 0;
}


int merge(int *array, int arrayInit, int arrayMid, int arrayEnd) {
  int i, arrayLength1 = (arrayMid - arrayInit) + 1,
      arrayLength2 = arrayEnd - arrayMid,
      
      *array1, *array2;
      
  array1 = malloc((arrayLength1 - 1) * sizeof(int));
  array2 = malloc((arrayLength2 - 1) * sizeof(int));
  
  for (i = 0; i < arrayLength1; i++) {
    array1[i] = array[arrayInit + i];
  }
  
  for (i = 0; i < arrayLength2; i++) {
    array2[i] = array[arrayMid + i + 1];
  }
  
  i = 0;
  int j = 0;
  int k = arrayInit;
  
  
  while (i < arrayLength1 && j < arrayLength2) {
    if (array1[i] <= array2[j]) {
      array[k] = array1[i];
      i++;
    } else {
      array[k] = array2[j];
      j++;
    }
    k++;
  }
  
  while (i < arrayLength1) {
    array[k] = array1[i];
    i++;
    k++;
  }
  
  while (j < arrayLength2) {
    array[k] = array2[j];
    j++;
    k++;
  }
  
  
  free(array1);
  free(array2);
  
  return 0;
}