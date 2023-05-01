#include <stdio.h>
#include <stdlib.h>


int countingSort(int*, int*, int, int);
int findLargest(int*, int);

int radixSort(int**, int**, int, int);
int countingSortRadix(int**, int**, int, int, int);
int findLargestRadix(int**, int, int);




int main() {
  int i, j, largestValue, numberLength, arrayLength, *array1, *array2, **pArray1, **pArray2;
  
  scanf("%d", &arrayLength);
  scanf("%d", &numberLength);
  
  pArray1 = (int**) malloc((arrayLength + 1) * sizeof(int*));
  pArray2 = (int**) malloc((arrayLength + 1) * sizeof(int*));
  
  for (i = 0; i <= arrayLength; i++) {
    pArray1[i] = (int*) malloc(numberLength * sizeof(int));
    pArray2[i] = (int*) malloc(numberLength * sizeof(int));
  }
  
  array1 = (int*) malloc((arrayLength + 1) * sizeof(int));
  array2 = (int*) malloc((arrayLength + 1) * sizeof(int));
  
  
  for (i = 1; i <= arrayLength; i++) {
    for (j = 0; j < numberLength; j++) {
      scanf("%d", &pArray1[i][j]);
    }
  }
  
  printf("main1\n");
  
  radixSort(pArray1, pArray2, arrayLength, numberLength);
  
  printf("main2\n");
  
  for (i = 1; i <= arrayLength; i++) {
    for (j = 0; j < numberLength; j++) {
      printf("%d ", pArray2[i][j]);
    }
    
    printf("\n");
  }
  
  /*
  for (i = 1; i <= arrayLength; i++) {
    scanf("%d", &array1[i]);
  }
  
  largestValue = findLargest(array1, arrayLength);
  
  countingSort(array1, array2, largestValue, arrayLength);
  
  for (i = 1; i <= arrayLength; i++) {
    printf("%d ", array2[i]);
  }
  */
  printf("\n");
  
  free(array1);
  free(array2);
  
  return 0;
}




int countingSort(int *array1, int *array2, int largestValue, int array1Length) {
  int i, j, *array3;
  
  array3 = (int*) malloc(largestValue * sizeof(int));
  
  for (i = 0; i < largestValue; i++) {
    array3[i] = 0;
  }
  
  for (j = 1; j <= array1Length; j++) {
    array3[array1[j]] += 1;
  }
  
  for (i = 1; i <= largestValue; i++) {
    array3[i] = array3[i] + array3[i - 1];
  }
  
  for (j = array1Length; j >= 1; j--) {
    array2[array3[array1[j]]] = array1[j];
    array3[array1[j]] = array3[array1[j]] - 1;
  }
  
  free(array3);
  
  return 0;
}


int findLargest(int *array, int arrayLength) {
  int i, largestValue;
  
  largestValue = array[1];
  
  for (i = 1; i <= arrayLength; i++) {
    if (largestValue < array[i]) {
      largestValue = array[i];
    }
  }
  
  return largestValue;
}




// Radix sort implementation.
int radixSort(int **pArray1, int **pArray2, int pArray1Length, int numberLength) {
  int k, largestValue;
  
  printf("radix1\n");
  for (k = 0; k < numberLength; k++) {
    largestValue = findLargestRadix(pArray1, pArray1Length, k);
    printf("%d radix2\n", largestValue);
    countingSortRadix(pArray1, pArray2, largestValue, pArray1Length, k);
  }
  
  return 0;
}


int countingSortRadix(int **pArray1, int **pArray2, int largestValue, int pArray1Length, int z) {
  int i, j, *array3;
  
  array3 = (int*) malloc(largestValue * sizeof(int));
  printf("counting1\n");
  for (i = 0; i < largestValue; i++) {
    array3[i] = 0;
  }
  
  for (j = 1; j <= pArray1Length; j++) {
    array3[pArray1[j][z]] += 1;
  }
  printf("counting2\n");
  for (i = 1; i <= largestValue; i++) {
    array3[i] = array3[i] + array3[i - 1];
  }
  printf("counting3\n");
  for (j = pArray1Length; j >= 1; j--) {
    printf("aqui1\n");
    pArray2[array3[pArray1[j][z]]] = pArray1[j];
    printf("aqui2\n");
    array3[pArray1[j][z]] = array3[pArray1[j][z]] - 1;
  }
  
  free(array3);
  
  return 0;
}


int findLargestRadix(int **pArray, int pArrayLength, int z) {
  int i, largestValue;
  
  largestValue = pArray[1][z];
  
  for (i = 1; i <= pArrayLength; i++) {
    if (largestValue < pArray[i][z]) {
      largestValue = pArray[i][z];
    }
  }
  
  return largestValue;
}