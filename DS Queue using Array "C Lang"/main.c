#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define True 1

void VisitQueueItems(int item)
{
    printf("%d\n", item);
}

int main()
{
    /* create a queue object */
    struct queue q;
    CreateQueue(&q);

    while(True)
    {
        /* If condition to check either the queue is full or not */
        if(IsQueueFull(&q) == True)
        {
            printf("Queue Is Full \n");
            break;
        }
        printf("EnQueue Item \n");
        int item ;
        scanf("%d", &item);
        EnQueue(item, &q);

        printf("Continue ? Y - N \n");
        char YN = getch();
        if(YN == 'N')
            break;
    }
    /*
    int i;
    for(i=0; i < MAXQUEUE; i++)
    {
        if(IsQueueEmpty(&q)==True)
        {
            printf("Queue Is Empty");
            break;
        }
        int out;
        DeQueue(&out,&q);
        printf("%d\n", out);
    }
    */
    TraverseQueue(&q, &VisitQueueItems);

    system("pause");
    return 0;
}
