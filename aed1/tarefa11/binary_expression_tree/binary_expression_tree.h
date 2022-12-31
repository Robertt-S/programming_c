#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 102


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


struct treeNode* createNewNode(char);
struct treeNode* unstackTreeNode(struct treeNode*);
void stackTreeNode(struct treeNode*, struct treeNode*);
void printInorder(struct treeNode*);
void buildExpressionTree(struct treeNode*, char array[]);
struct treeNode* destroyTree(struct treeNode* root);
int emptyTree(struct treeNode* root);
int findTreeHeight(struct treeNode*);
void printTreeLevel(struct treeNode*, int);