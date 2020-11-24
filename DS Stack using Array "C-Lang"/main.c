/* 

Array implementation Stack

*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Display(StackItem e)
{
    printf("%d\n" ,(*(int*)e));
}

int main()
{

    Obj_Stack s;
    createStack(&s);

    int x = 10;
    push((StackItem)&x , &s);

    StackItem item;
    pop(&item ,&s);
    printf("%d" ,*((int *)item));

    /* int resultEm = stackEmpty(&s);
    printf("%d" ,resultEm);

    printf("%d" ,stackSize(&s));

    int x = 10;
    push((StackItem)&x , &s);

    int resultFu = stackFull(&s);
    printf("%d" ,resultFu);

    StackItem item;
    pop(&item ,&s);
    printf("%d" ,*((int *)item));


    clearStack(&s);
    printf("%d" ,stackSize(&s)); */

    /*int x = 10;
    push((StackItem)&x , &s);

    int y = 15;
    push((StackItem)&y , &s);

    //TraverseStack(&s ,&Display);

    StackItem item;
    peak(&item, &s);
    printf("peak - %d\n", *((int*)item));

    StackItem item_1;
    peek(&item_1, &s);
    printf("peak - %d", *((int*)item_1));*/

    return 0;
}
