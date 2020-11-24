
#ifndef _STACK_ARRAY_BASED_H_
#define _STACK_ARRAY_BASED_H_


/* Pointer of struct that points to array elements */
typedef void * StackItem;

/* Pointer that points on each created object of a struct */
typedef struct stack * Obj_Stack;

/* Create an object size of stack struct in heap, set top to zero as an entry element
    i/p: address of the created element */
void createStack(Obj_Stack *pps);

/* Push an element to stack
    i/p: - pointer of struct that points to the item to be pushed
         - pointer to the object   */
void push(StackItem item, Obj_Stack *pps);

/* Pop the recent inserted element from stack and save to the variable
        created type of array of struct
    i/p: - pointer of struct that points to the item to be popped
         - pointer to the object   */
void pop(StackItem *pItem ,Obj_Stack *pps);

/* Get the max of stack */
void peak(StackItem *pItem ,Obj_Stack *pps);

/* Check whether the stack is full or not */
int Is_stackFull(Obj_Stack *pps);

/* Check whether the stack is empty or not
    i/p: pointer to the latest created object */
int Is_stackEmpty(Obj_Stack *pps);

/* return the stack size which is the value of top as it has been
    incremented */
int stackSize(Obj_Stack *pps);

/* Clear stack by setting the top to zero to restart from the entry point */
void clearStack(Obj_Stack *pps);

/* function to traverse on all stack elements with an action
    i/p: - function to be implemented on each element
         - pointer to the object */
void TraverseStack(Obj_Stack *pps, void (*ptrFunc)(StackItem x));


#endif
