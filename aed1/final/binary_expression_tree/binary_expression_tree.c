#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 202


// infix to postfix structure.
typedef struct node {
  char info;
  struct node *next;
} typeInfixToPostfixNode;

typedef struct {
  typeInfixToPostfixNode *top;
} typeInfixToPostfixStack;


void initializeInfixToPostfixStack(typeInfixToPostfixStack*);
int emptyInfixToPostfixStack(typeInfixToPostfixStack*);
int pushToInfixToPostfixStack(typeInfixToPostfixStack*, char);
char unstackInfixToPostfixNode(typeInfixToPostfixStack*);
void destroyInfixToPostfixStack(typeInfixToPostfixStack*);

int isOperator(char);
int operatorPrecedence(char);
void InfixToPostfix(typeInfixToPostfixStack*, char array1[], char array2[]);




// tree on a stack structured.
struct treeNode {
  char info;
  struct treeNode* leftTree;
  struct treeNode* rightTree;
  struct treeNode* next;
};

struct treeNode *root = NULL;

struct treeNode* createNewNode(char);
struct treeNode* unstackTreeNode();
void stackTreeNode(struct treeNode*);
void printInorder(struct treeNode*);
void buildExpressionTree(char array[]);
struct treeNode* destroyTree(struct treeNode* root);
int emptyTree(struct treeNode* root);
int findTreeHeight(struct treeNode*);
void printTreeLevel(struct treeNode*, int);

int z;




int main() {
  typeInfixToPostfixStack infixToPostfixStack;
  char infixExpression[MAX], postfixExpression[MAX];
  int treeHeight, k;
  
  initializeInfixToPostfixStack(&infixToPostfixStack);
  
  while (gets(infixExpression) != EOF) {
    
    InfixToPostfix(&infixToPostfixStack, infixExpression, postfixExpression);
    
    buildExpressionTree(postfixExpression);
    
    treeHeight = findTreeHeight(root);
    
    for (k = 0; k < treeHeight; k++) {
      z = 1;
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




//--- Functions to handle the infix to postfix expression. ---//
void initializeInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  stack->top = NULL;
  return;
}


int emptyInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  return stack->top == NULL;
}


int pushToInfixToPostfixStack(typeInfixToPostfixStack *stack, char info) {
  typeInfixToPostfixNode *newNode;
  
  newNode = (typeInfixToPostfixNode*) malloc(sizeof(typeInfixToPostfixNode));
  
  if (newNode != NULL) {
    newNode->info = info;
    newNode->next = stack->top;
    stack->top = newNode;
    
    return 1;
  }
  
  return 0;
}


char unstackInfixToPostfixNode(typeInfixToPostfixStack *stack) {
  typeInfixToPostfixNode *pAux;
  
  if (!emptyInfixToPostfixStack(stack)) {
    pAux = stack->top;
    stack->top = pAux->next;
    
    free(pAux);
    
    return pAux->info;
  }
  
  return 0;
}


void destroyInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  typeInfixToPostfixNode *pAux;
  
  if (!emptyInfixToPostfixStack(stack)) {
    pAux = stack->top;
    while (pAux != NULL) {
      stack->top = pAux->next;
      free(pAux);
      pAux = stack->top;
    }
  }
  
  return;
}


int isOperator(char symbol) {
  if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
    return 1;
  } else {
    return 0;
  }
}


int operatorPrecedence(char symbol) {
  if (symbol == '^') {
    return 3;
  } else if (symbol == '*' || symbol == '/') {
    return 2;
  } else if (symbol == '+' || symbol == '-') {
    return 1;
  } else {
    return 0;
  }
}


void InfixToPostfix(typeInfixToPostfixStack *stack, char infixExpression[], char postfixExpression[]) { 
  int i = 0, j = 0;
  char item, auxUnstack;
  
  pushToInfixToPostfixStack(stack, '(');
  strcat(infixExpression, " )");
  
  item = infixExpression[i];
  
  while (item != '\0') {
    if (item == '(') {
      pushToInfixToPostfixStack(stack, item);
      
    } else if (item != '+' && item != '-' && item != '*' && item != '/' && item != '^' && item != ')') {
      postfixExpression[j] = item;
      j++;
      
    } else if (isOperator(item) == 1) {
      auxUnstack = unstackInfixToPostfixNode(stack);
      
      while (isOperator(auxUnstack) == 1 && operatorPrecedence(auxUnstack) >= operatorPrecedence(item)) {
        postfixExpression[j] = auxUnstack;
        j++;
        auxUnstack = unstackInfixToPostfixNode(stack);
      }
      
      pushToInfixToPostfixStack(stack, auxUnstack);
      pushToInfixToPostfixStack(stack, item);
      
    } else if (item == ')') {
      auxUnstack = unstackInfixToPostfixNode(stack);
      
      while (auxUnstack != '(') {
        postfixExpression[j] = auxUnstack;
        j++;
        auxUnstack = unstackInfixToPostfixNode(stack);
      }
      
    }
    
    i += 2;
    item = infixExpression[i];
  }
  
  postfixExpression[j] = '\0';
}




//--- Functions to handle the stack/tree structure.
struct treeNode* createNewNode(char info) {
  struct treeNode* newNode;
  newNode = (struct treeNode*) malloc(sizeof(struct treeNode));
  newNode->info = info;
  newNode->leftTree = NULL;
  newNode->rightTree = NULL;
  newNode->next = NULL;
  
  return newNode;
}


void stackTreeNode(struct treeNode* nodeToAdd) {
  if (root == NULL) {
    root = nodeToAdd;
  } else {
    nodeToAdd->next = root;
    root  = nodeToAdd;
  }
  return;
}


struct treeNode* unstackTreeNode() {
  struct treeNode *nodeToRemove;
  nodeToRemove = root;
  root = root->next;
  return nodeToRemove;
}


int emptyTree(struct treeNode *root){
  return root == NULL;
}


struct treeNode* destroyTree(struct treeNode *root) {
  if(!emptyTree(root)){
    destroyTree(root->leftTree);
    destroyTree(root->rightTree);
    free(root);
  }
  return NULL;
}


void buildExpressionTree(char postfixExpression[]) {
  struct treeNode *auxRightTree, *auxLeftTree, *auxTree;
  int length = strlen(postfixExpression);
  
  for (int i = 0; i < length; i++) {
    if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/' || postfixExpression[i] == '^') {
      auxTree = createNewNode(postfixExpression[i]);
      auxRightTree = unstackTreeNode();
      auxLeftTree = unstackTreeNode();
      auxTree->leftTree = auxLeftTree;
      auxTree->rightTree = auxRightTree;
      stackTreeNode(auxTree);
    } else {
      auxTree = createNewNode(postfixExpression[i]);
      stackTreeNode(auxTree);
    }
  }
  return;
}


int findTreeHeight(struct treeNode* root) {
  int leftTreeHeight, rightTreeHeight;
  
  if (root == NULL) {
    return 0;
  } else {
    leftTreeHeight = findTreeHeight(root->leftTree);
    rightTreeHeight = findTreeHeight(root->rightTree);
    
    if (leftTreeHeight >= rightTreeHeight) {
      return leftTreeHeight + 1;
    } else {
      return rightTreeHeight + 1;
    }
  }
}


void printTreeLevel(struct treeNode* root, int treeLevel) {
  if (root != NULL && treeLevel == 0) {
    if (!z) {
      printf(" %c", root->info);
    } else {
      printf("%c", root->info);
      z = 0;
    }
  } else if (root != NULL) {
    printTreeLevel(root->leftTree, treeLevel - 1);
    printTreeLevel(root->rightTree, treeLevel - 1);
  }
}