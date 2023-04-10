#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} TypeNode;


typedef struct list {
  TypeNode *listInitial;
  int last;
} TypeList;

int mergeSort(int*, int, int);
int merge(int*, int, int, int);


int listIsEmpty(TypeList*);
int insertAtBeginning(TypeList*, int);
int insertAtEnd(TypeList*, int);
int insertByChoose(TypeList*, int, int);


int main() {
  int i, arrayLength, *array;
  
  scanf("%d", &arrayLength);
  
  array = malloc(arrayLength * sizeof(int));
  
  for (i = 0; i < arrayLength; i++) {
    array[i] = arrayLength - i;
  }
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
  
  mergeSort(array, 0, arrayLength - 1);
  
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
  
  free(array);
  
  return 0;
}




int mergeSort(int *array, int arrayInit, int arrayEnd) {
  
  if (arrayInit < arrayEnd) {
    int arrayMid = (arrayInit + arrayEnd) / 2;
    
    mergeSort(array, arrayInit, arrayMid);
    mergeSort(array, arrayMid + 1, arrayEnd);
    
    merge(array, arrayInit, arrayMid, arrayEnd);
  }
  
  return 0;
}


int merge(int *array, int arrayInit, int arrayMid, int arrayEnd) {
  int leftArrayLength = arrayMid - arrayInit + 1,
      rightArrayLength = arrayEnd - arrayMid,
      
      *leftArray, *rightArray,
      i, j, k;
   
  
  leftArray = malloc((leftArrayLength + 1) * sizeof(int));
  rightArray = malloc((rightArrayLength + 1) * sizeof(int));
  
  for (i = 0; i < leftArrayLength; i++) {
    leftArray[i] = array[arrayInit + i];
  }
  
  for (j = 0; j < rightArrayLength; j++) {
    rightArray[j] = array[arrayMid + j + 1];
  }
  
  
  leftArray[leftArrayLength] = 1215752192;
  rightArray[rightArrayLength] = 1215752192;
  
  i = 0;
  j = 0;
  
  for (k = arrayInit; k < arrayEnd + 1; k++) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
  }
  
  free(leftArray);
  free(rightArray);
  
  return 0;
}


int listIsEmpty(TypeList *list) {
  return list->last == 0;
}


int insertAtBeginning(TypeList *list, int item) {
  TypeNode *newNode;
  
  newNode = (TypeNode*) malloc(sizeof(TypeNode));
  
  if (newNode != NULL) {
    newNode->data = item;
    newNode->next = list->listInitial;
    list->listInitial = newNode;
    list->last++;
    
    return 1;
  }
  
  return 0;
}


int insertAtEnd(TypeList *list, int item) {
  TypeNode *newNode, *pAux;
  
  if (listIsEmpty(list)) {
    insertAtBeginning(list, item);
    
    return 1;
  }
  
  newNode = (TypeNode*) malloc(sizeof(TypeNode));
  
  if (newNode != NULL) {
    pAux = list->listInitial;
    
    while (pAux->next != NULL) {
      pAux = pAux->next;
    }
    
    newNode->data = item;
    newNode->next = NULL;
    pAux->next = newNode;
    
    list->last++;
    
    return 1;
  }
  
  return 0;
}


int insertByChoose(TypeList *list, int item, int position) {
  TypeNode *newNode, *pAux;
  int i;
  
  if (listIsEmpty(list)) {
    insertAtBeginning(list, item);
    
    return 1;
  } else if (position == list->last + 1) {
    insertAtEnd(list, item);
    
    return 1;
  } else {
    
    newNode = (TypeNode*) malloc(sizeof(TypeNode));
    
    pAux = list->listInitial;
    
    if (newNode != NULL) {
      for (i = 2; i < position; i++) {
        if (pAux->next != NULL) {
          pAux = pAux->next;
        }
      }
    }
    
    newNode->next = pAux->next;
    pAux->next = newNode;
    
    list->last++;
    
    return 1;
  }
  
  return 0;
}


















/*
int merge(int *array, int arrayInit, int arrayMid, int arrayEnd) {
  int i, leftArrayLength = (arrayMid - arrayInit) + 1,
      rightArrayLength = arrayEnd - arrayMid,
      
      *leftArray, *rightArray;
      
  leftArray = malloc((leftArrayLength - 1) * sizeof(int));
  rightArray = malloc((rightArrayLength - 1) * sizeof(int));
  
  for (i = 0; i < leftArrayLength; i++) {
    leftArray[i] = array[arrayInit + i];
  }
  
  for (i = 0; i < rightArrayLength; i++) {
    rightArray[i] = array[arrayMid + i + 1];
  }
  
  printf("1: ");
  for (i = 0; i < leftArrayLength; i++) {
    printf("%d ", leftArray[i]);
  }
  
  printf("\n");
  
  printf("2: ");
  for (i = 0; i < rightArrayLength; i++) {
    printf("%d ", rightArray[i]);
  }
  
  printf("\n");
  
  
  i = 0;
  int j = 0;
  int k = arrayInit;
  
  
  while (i < leftArrayLength && j < rightArrayLength) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }
  
  while (i < leftArrayLength) {
    array[k] = leftArray[i];
    i++;
    k++;
  }
  
  while (j < rightArrayLength) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
  
  
  free(leftArray);
  free(rightArray);
  
  return 0;
}  */