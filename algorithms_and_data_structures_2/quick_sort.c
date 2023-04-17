#include <stdio.h>
#include <stdlib.h>

int partition(int*, int, int);
int quickSort(int*, int, int, int*, int*, int);
int medianPartition(int*, int, int);
int medianQuickSort(int*, int, int, int*, int*, int);

int medianIndex(int*, int, int);




int main() {
  int i, arrayLength, median, maxDepth = 0, minDepth, deltaDepth, *array1, *array2;
  
  scanf("%d", &arrayLength);
  
  array1 = (int*) malloc(arrayLength * sizeof(int));
  array2 = (int*) malloc(arrayLength * sizeof(int));
  
  for (i = 0; i < arrayLength; i++) {
    scanf("%d", &array1[i]);
    array2[i] = array1[i];
  }
  
  
  minDepth = arrayLength;
  
  quickSort(array1, 0, arrayLength - 1, &minDepth, &maxDepth, 0);
  
  deltaDepth = maxDepth - minDepth;
  printf("%d\n", deltaDepth);
  
  
  minDepth = arrayLength;
  maxDepth = 0;
  
  medianQuickSort(array2, 0, arrayLength - 1, &minDepth, &maxDepth, 0);
  deltaDepth = maxDepth - minDepth;
  
  printf("%d\n", deltaDepth);
  
  /*  Seeing if the quicksort ran properly.
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array1[i]);
  }
  
  printf("\n");
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array2[i]);
  }
  
  printf("\n");
  */
  
  free(array1);
  free(array2);
  
  return 0;
}




int quickSort(int *array, int arrayInitial, int arrayEnd, int *minDepth, int *maxDepth, int currentDepth) {
  if (arrayInitial < arrayEnd) {
    int arrayPartition = partition(array, arrayInitial, arrayEnd);
    
    quickSort(array, arrayInitial, arrayPartition - 1, minDepth, maxDepth, currentDepth + 1);
    quickSort(array, arrayPartition + 1, arrayEnd, minDepth, maxDepth, currentDepth + 1);
    
  } else {
    if (currentDepth > (*maxDepth)) {
    (*maxDepth) = currentDepth;
    }
    
    if (currentDepth < (*minDepth)) {
    (*minDepth) = currentDepth;
    }
  }
  
}


int partition(int *array, int arrayInitial, int arrayEnd) {
  int pivot = array[arrayEnd], 
      i = arrayInitial - 1,
      j, swap;
  
  for (j = arrayInitial; j < arrayEnd; j++) {
    if (array[j] <= pivot) {
      i++;
      
      swap = array[j];
      array[j] = array[i];
      array[i] = swap;
    }
  }
  
  swap = array[i + 1];
  array[i + 1] = array[arrayEnd];
  array[arrayEnd] = swap;
  
  return (i + 1);
}


// Quick sort using the median of array[beggining], array[mid] and array[end].
int medianQuickSort(int *array, int arrayInitial, int arrayEnd, int *minDepth, int *maxDepth, int currentDepth) {
  if (arrayInitial < arrayEnd) {
    int arrayPartition = medianPartition(array, arrayInitial, arrayEnd);
    
    medianQuickSort(array, arrayInitial, arrayPartition - 1, minDepth, maxDepth, currentDepth + 1);
    medianQuickSort(array, arrayPartition + 1, arrayEnd, minDepth, maxDepth, currentDepth + 1);
    
  } else {
    if (currentDepth > (*maxDepth)) {
    (*maxDepth) = currentDepth;
    }
    
    if (currentDepth < (*minDepth)) {
    (*minDepth) = currentDepth;
    }
  }
  
}

int medianPartition(int *array, int arrayInitial, int arrayEnd) {
  int pivotIndex = medianIndex(array, arrayInitial, arrayEnd),
      swap;
  
  swap = array[arrayEnd];
  array[arrayEnd] = array[pivotIndex];
  array[pivotIndex] = swap;
  
  return partition(array, arrayInitial, arrayEnd);
}


int medianIndex(int *array, int arrayInitial, int arrayEnd) {
  int midIndex = (arrayInitial + arrayEnd) / 2;
  
  if ((midIndex <= array[arrayInitial] && array[arrayInitial] <= array[arrayEnd]) || 
      (midIndex >= array[arrayInitial] && array[arrayInitial] >= array[arrayEnd])) {
  
    return arrayInitial;
  } else if ((midIndex <= array[arrayEnd] && array[arrayEnd] <= array[arrayInitial]) || 
             (midIndex >= array[arrayEnd] && array[arrayEnd] >= array[arrayInitial])) {
    
    return arrayEnd;
  } else {
    
    return midIndex;
  }
}