#include "binary_expression_tree.h"

int main() {
  struct treeNode *root;
  typeInfixToPostfixStack infixToPostfixStack;
  char infixExpression[MAX], postfixExpression[MAX];
  int treeHeight, k;
  
  initializeInfixToPostfixStack(&infixToPostfixStack);
  
  while (gets(infixExpression) != EOF) {
    
    InfixToPostfix(&infixToPostfixStack, infixExpression, postfixExpression);
    
    buildExpressionTree(root, postfixExpression);
    
    treeHeight = findTreeHeight(root);
    
    for (k = 0; k < treeHeight; k++) {
      printf("Nivel %d: ", k);
      printTreeLevel(root, k);
      printf("\n");
    }
    
    printf("\n");
    
    destroyInfixToPostfixStack(&infixToPostfixStack);
    root = destroyTree(root);
  }
  return 0;
}