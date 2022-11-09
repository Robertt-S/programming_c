#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 98

typedef struct{
  int number;
  char operator;
} typeItem;

typedef struct node {
  typeItem item;
  struct node *next;
} typeNode;

typedef struct {
  typeNode *top;
} typeStack;


int stackNode(typeStack*, typeItem);
int unstackNode(typeStack*);
int postfixResult(typeStack*, typeStack*, char postfixExpression[MAX]);
int resultStack(typeStack*, typeStack*, int);