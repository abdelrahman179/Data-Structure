#include "queue.h"


/* Create a queue statically
    i/p : pointer type of struct that points to struct object variables  */
void CreateQueue(struct queue * pq)
{
    pq -> head = 0 ;   /* var to hold the index of first element */
    pq -> tail = -1;   /* var to hold the index of recent queued element */
    pq -> size = 0 ;   /* var to hold the size of queued elements */
}

/* Determine either the queue is full or not
    i/p: pointer type of struct that points to struct object tail variable
    return: 0 > false, 1 > true */
int IsQueueFull(struct queue * pq)
{
    /* return either 0 false, 1 true */
    return pq -> size == MAXQUEUE;
}

/* Enqueue an element to the queue
    i/p: value of the variable will be enqueued
            & pointer type of struct that points to struct object variables */
void EnQueue(int item, struct queue *pq)
{
    /* if condition to determine either the queue is full
        as if it's full the tail will point to index 0 */
    if(pq-> tail == MAXQUEUE -1)
        pq -> tail = 0;
    else
        pq -> tail++; /* increment to insert in the next index */

    /* insert the value passed to the new index */
    pq -> items[pq -> tail] = item;
    pq -> size++;
}

/* Dequeue an element from the queue
    i/p: pointer to a variable to hold the dequeued value
            & pointer type of struct that points to struct object variables */
void DeQueue(int * outItem, struct queue *pq)
{
    /* let the value passed equal the value that head holds */
    *outItem = pq -> items[pq -> head];

    /* if condition to detect either the empty or not */
    if(pq -> head == MAXQUEUE-1)
        pq -> head = 0;
    else
        pq -> head++; /* increment the head to let it points to the next element */

    pq -> size--;
}

/* Determine either the queue is empty or not
    i/p: pointer type of struct that points to struct object size variable
    return: 0 > false, 1 > true */
int IsQueueEmpty(struct queue * pq)
{
    return pq -> size == 0;
}

/* Get the size of the queue
    i/p: pointer type of struct that points to struct object size variable */
int QueueSize(struct queue * pq)
{
    return pq -> size;
}

/* Clear queue elements
    i/p: pointer type of struct that points to struct object variables */
void ClearQueue(struct queue * pq)
{
    pq -> head  = 0;
    pq -> tail  = -1;
    pq -> size  = 0;
}

/* Traverse function to implement an operation on queue elements */
void TraverseQueue(struct queue * pq, void (*pf)(int x))
{
    int i;
    for(i = 0; i < pq -> size; i++)
        (*pf)(pq -> items[i]);
}
