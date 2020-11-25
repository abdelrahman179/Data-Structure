
#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

/* Set the size of the array  */
#define MAXQUEUE 3

struct queue
{
    int head;
    int tail;
    int size;
    int items[MAXQUEUE];
};

/* Create a queue statically
    i/p : pointer type of struct that points to struct object variables  */
void CreateQueue(struct queue * pq);

/* Enqueue an element to the queue
    i/p: value of the variable will be enqueued
            & pointer type of struct that points to struct object variables */
void EnQueue(int item, struct queue *pq);

/* Dequeue an element from the queue
    i/p: pointer to a variable to hold the dequeued value
            & pointer type of struct that points to struct object variables */
void DeQueue(int *item, struct queue *pq);

/* Determine either the queue is full or not
    i/p: pointer type of struct that points to struct object tail variable
    return: 0 > false, 1 > true */
int IsQueueFull(struct queue * pq);

/* Determine either the queue is empty or not
    i/p: pointer type of struct that points to struct object size variable
    return: 0 > false, 1 > true */
int IsQueueEmpty(struct queue * pq);

/* Get the size of the queue
    i/p: pointer type of struct that points to struct object size variable */
int QueueSize(struct queue * pq);

/* Clear queue elements
    i/p: pointer type of struct that points to struct object variables */
void ClearQueue(struct queue * pq);

/* Traverse function to implement an operation on queue elements */
void TraverseQueue(struct queue * pq, void (*pf)(int x));


#endif
