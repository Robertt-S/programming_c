#include "postfix_expression.h"

int startStack(typeStack *stack) {
  stack->top == NULL;
  
  return 1;
}


int emptyStack(typeStack *stack) {
  return stack->top == NULL;
}


int stackNode(typeStack *stack, typeItem item) {
  typeNode *newNode;
  
  newNode = (typeNode*) malloc(sizeof(typeNode));
  
  if (newNode != NULL) {
    newNode->item = item;
    newNode->next = stack->top;
    stack->top = newNode;
    
    return 1;
  }
  
  return 0;
}


int unstackNode(typeStack *stack) {
  typeNode *pAux;
  
  if (!emptyStack(stack)) {
    pAux = stack->top;
    stack->top = stack->top->next;
    
    free(pAux);
    
    return 1;
  }
  
  return 0;
}

// Organizando as pilhas e retornando a quantidade de operadores!
int organizeStack(typeStack *numberStack, typeStack *operatorStack, char expression[MAX]) {
  typeItem item;
  int i, count = 0;
  
  if (!emptyStack(numberStack) && !emptyStack(operatorStack)) {
    for (i = 0; i < strlen(expression) - 1; i++) {
      if ((expression[i] != '+') && (expression[i] != '-') && (expression[i] != '*') && (expression[i] != '/')) {
        item.number = expression[i];
        stackNode(numberStack, item);
      } else {
        item.operator = expression[i];
        stackNode(operatorStack, item);
        
        count++;
      }
    }
    
    return count;
  }
  
  return 0;
}

/* 
 Desempilhando dois números e um operador,
 depois empilha o resultado e volta a desempilhar como no início
*/
int resultStack(typeStack *numberStack, typeStack *operatorStack, int operatorNum) {
  typeItem item;
  int i;
  
  for (i = 0; i < operatorNum; i++) {
    if (operatorStack->top->item.operator == '+') {
      item.number = numberStack->top->item.number + numberStack->top->next->item.number;
     
      unstackNode(operatorStack);
      unstackNode(numberStack);
      unstackNode(numberStack);
      
      stackNode(numberStack, item);
    } else if (operatorStack->top->item.operator == '-') {
      item.number = numberStack->top->item.number - numberStack->top->next->item.number;
      
      unstackNode(operatorStack);
      unstackNode(numberStack);
      unstackNode(numberStack);
      
      stackNode(numberStack, item);
    } else if (operatorStack->top->item.operator == '*') {
      item.number = numberStack->top->item.number * numberStack->top->next->item.number;
      
      unstackNode(operatorStack);
      unstackNode(numberStack);
      unstackNode(numberStack);
      
      stackNode(numberStack, item);
    } else if (operatorStack->top->item.operator == '/') {
      item.number = numberStack->top->item.number / numberStack->top->next->item.number;
      
      unstackNode(operatorStack);
      unstackNode(numberStack);
      unstackNode(numberStack);
      
      stackNode(numberStack, item);
    }
  }
  
  
  
  //1234++* = 1 * 2 + 3 + 4
  return 0;
}