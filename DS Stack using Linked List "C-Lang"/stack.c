#include "stack.h"
#include <stdlib.h>

struct stacknode
{
    StackItem item;
    /* pNext holds two variables item and pNext */
    struct stacknode *pNext;
};
struct stack
{
    int Size;
    StackNode *pTop;
};

/* Create an object size of stack struct in heap, set top to zero as an entry element
    i/p: address of the created object */
void CreateStack(Stack *pps)
{
    /* allocate space in heap size of struct */
    *pps = (Stack) malloc(sizeof(struct stack));
    /* initial value of pTop equal NULL as it points to nothing */
    (*pps)-> pTop = NULL;
    /* initial value size equal zero as nothing is created yet */
    (*pps)-> Size = 0;
}

void Push(StackItem Item, Stack *pps)
{
    /* allocate a new node in heap size of StackNode */
    StackNode * pn = (StackNode*) malloc(sizeof(StackNode));
    /* assign the value passed to the function to variable "item" */
    pn -> item = Item;
    /* pNext is equal to pTop previous value */
    pn -> pNext = (*pps) -> pTop;
    /* pTop value is the recently pushed node value */
    (*pps)-> pTop = pn;
     /* increment the size of stack nodes by one */
    (*pps) -> Size++;
}


void Pop(StackItem *ppItem, Stack *pps)
{
    /* pointer of stuct points to the value of object passed pTop  */
    StackNode *pn = (*pps) -> pTop;
    /* assign the item value of referred object to ppItem */
    *ppItem = pn -> item;
    /* next of popped node equal ptop */
    (*pps) -> pTop = pn -> pNext;
    /* clear heap space of popped node */
    free(pn);
    /* decrement size */
    (*pps) -> Size--;
}

/* size variable hold the number of nodes created */
int StackSize(Stack *pps)
{
    return (*pps) -> Size;
}


void TraverseStack(Stack *pps, void (*pf)(StackItem))
{
    StackNode *pn = (*pps) -> pTop;
    while(pn)
    {
      (*pf)(pn -> item);
       pn = pn -> pNext;
    }
}


/* check if the size is zero  */
int IsStackEmpty(Stack *pps)
{
    return (*pps) -> Size == 0;
}

/* no limitation */
int IsStackFull(Stack *pps)
{
    return 0;
}


void ClearStack(Stack *pps)
{
   StackNode * pn = (*pps)->pTop;
   StackNode *pCurrent = pn;
   while(pn)
    {
        pn = pn -> pNext;
        free(pCurrent);
        pCurrent = pn;
   }
   (*pps) -> pTop = NULL;
   (*pps) -> Size = 0;
}
