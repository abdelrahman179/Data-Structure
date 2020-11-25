#include "queue.h"
#include <stdlib.h>

/* Create a queue dynamically
    i/p : pointer type of struct that points to struct object variables  */
void CreateQueue(struct queue *pq)
{
    /* allocate dynamically the object variables in heap */
    pq = (struct queue *)malloc(sizeof(struct queue));
    pq -> size = 0;     /* set size to zero */
    pq -> phead = NULL; /* set phead to NUll as it points to nothing */
    pq -> ptail = NULL; /* set ptail to NUll as it points to nothing */
}

/* Determine either the queue is full or not
    i/p: pointer type of struct that points to struct object tail variable
    return: 0 > false, 1 > true */
int IsQueueFull(struct queue * pq)
{
    return 0;
}
/* Enqueue an element to the queue
    i/p: value of the variable will be enqueued
            & pointer type of struct that points to struct object variables */
void EnQueue(int item, struct queue * pq)
{
    /* create a pointer to queue node struct to hold the pointer of located in heap
        size of struct */
    struct queuenode *pn =(struct queuenode*) malloc(sizeof(struct queuenode));
    pn -> item = item;  /* set the item passed to function to struct variable */
    /* if condition to determine either it will be the 1st node or next one */
    if(pq -> phead == NULL)
        pq -> phead = pq -> ptail = pn; /* phead and ptail will points to the node */
    else
    {
        /* set tail to point to next element */
        pq -> ptail -> pNext = pn;
        pq -> ptail = pn;
    }
    pq -> size++;
}
/* Determine either the queue is empty or not
    i/p: pointer type of struct that points to struct object size variable
    return: 0 > false, 1 > true */
int IsQueueEmpty(struct queue * pq)
{
    return pq -> size == 0;
}

/* Dequeue an element from the queue
    i/p: pointer to a variable to hold the dequeued value
            & pointer type of struct that points to struct object variables */
void DeQueue(int *item, struct queue * pq)
{   /* pointer of stuct to hold the head var  */
    struct queuenode *pn = pq -> phead;
      *item = pn -> item;  /*  */

      /* if condition to determine whether it's the last node or not */
      if(pq -> phead -> pNext == NULL)
        pq -> phead = pq -> ptail = NULL;
      else
        pq -> phead = pn -> pNext;

    /* free located node space */
    free(pn);
    pq -> size--;
}
/* Get the size of the queue
    i/p: pointer type of struct that points to struct object size variable */
int QueueSize(struct queue * pq)
{
    return pq -> size;
}
/* Clear queue elements
    i/p: pointer type of struct that points to struct object variables */
void ClearQueue(struct queue *pq)
{
    /* pointer of stuct to hold the head var  */
    struct queuenode *pF = pq -> phead;
    /* pointer of stuct to hold the head pF  */
    struct queuenode *pT = pF;
    while(pF)
    {
        pF = pF -> pNext;
        free(pT);
        pT = pF;
    }
    pq -> size = 0;
    pq -> phead = NULL;
    pq -> ptail = NULL;
}
/* Traverse function to implement an operation on queue elements */
void TraverseQueue(struct queue *pq, void (*pf)(int item))
{
    while(pq -> phead)
    {
        (*pf)(pq -> phead -> item);
        pq -> phead = pq -> phead -> pNext;
    }
}




