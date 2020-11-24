
#include "stack.h"
#include "stdlib.h"

#ifndef STACKMAX

#undef  STACKMAX
#define STACKMAX 5

#endif


struct stack
{
    /* Newly inserted element */
    int top;
    /* Create a an array type of struct */
    StackItem items[STACKMAX];
};

/* Create an object size of stack struct in heap, set top to zero as an entry element
    i/p: address of the created object */
void createStack(Obj_Stack *pps)
{
    *pps = (Obj_Stack)malloc(sizeof(struct stack));
    (*pps) -> top = 0;
}

/* Push an element to stack
    i/p: - pointer of struct that points to the item to be pushed
         - pointer to the object   */
void push(StackItem item, Obj_Stack *pps)
{
    /* insert element to stack after the recent one */
    (*pps) -> items[(*pps) -> top++] = item;

}

/* Pop the recent inserted element from stack and save to the variable
        created type of array of struct
    i/p: - pointer of struct that points to the item to be popped
         - pointer to the object   */
void pop(StackItem *pItem ,Obj_Stack *pps)
{
    *pItem = (*pps) -> items[--(*pps)-> top];
}

/* Get the max of stack */
void peek(StackItem *pItem ,Obj_Stack *pps)
{
    *pItem = (*pps) -> items[(*pps)-> top-1];
}

/* Check whether the stack is full or not */
int Is_stackFull(Obj_Stack *pps)
{
    return (*pps) -> top == STACKMAX;
}

/* Check whether the stack is empty or not
    i/p: pointer to the latest created object */
int Is_stackEmpty(Obj_Stack *pps)
{
    return (*pps) -> top == 0;
}

/* return the stack size which is the value of top as it has been
    incremented */
int stackSize(Obj_Stack *pps)
{
    return (*pps) -> top;
}

/* Clear stack by setting the top to zero to restart from the entry point */
void clearStack(Obj_Stack *pps)
{
    /* simulate that top returned to zero */
    (*pps) -> top = 0;
}

/* function to traverse on all stack elements with an action
    i/p: - function to be implemented on each element
         - pointer to the object */
void TraverseStack(Obj_Stack *pps, void(*ptrFunc)(StackItem))
{
    /* loop on all elements */
    for(int i = (*pps)->top-1;  i >= 0 ;i--)
    {
        /* callback the function giving an input of each element */
        (*ptrFunc)((*pps)->items[i]);
    }
}

