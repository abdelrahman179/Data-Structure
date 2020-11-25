#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void display(int x)
{
    printf("%d - ",x);
}

int main()
{
    struct queue *q;

    CreateQueue(&q);

    while(1)
    {
        printf("Element ?\n");
        int x;
        scanf("%d" , &x);
        EnQueue(x , q);
        printf("More ? N - Y \n");
        char YN = getch();
        if(YN == 'N')
        break;
    }

    int y;
    DeQueue(&y , q);
    printf("%d\n" ,y);

    int z;
    DeQueue(&z , q);
    printf("%d" ,z);

    return 0;
}
