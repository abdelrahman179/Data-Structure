#ifndef _Stack_Linked_H_
#define _Stack_Linked_H_

/* Pointer of struct that points to the value of node */
typedef void * StackItem;

/* Pointer that points on each created object of a struct */
typedef struct stack * Stack;

typedef struct stacknode StackNode;

/* Create an object size of stack struct in heap.
    i/p: address of the created object */
void CreateStack(Stack *pps);

void Push(StackItem item, Stack *pps);

void Pop(StackItem *ppitem, Stack *pps);

int IsStackFull(Stack *pps);

int IsStackEmpty(Stack *pps);

void ClearStack(Stack *pps);

int StackSize(Stack *pps);

void TraverseStack(Stack *pps, void (*)(StackItem));

#endif
