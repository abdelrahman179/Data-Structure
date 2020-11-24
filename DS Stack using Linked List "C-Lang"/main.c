#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Display(StackItem e)
{
    printf("%d\n", *(int*)e);
}

int main()
{
    /* create an object */
    Stack s;
    /* create node */
    CreateStack(&s);
    while(1)
    {
        printf("Enter Element \n");
        int x =(int*) malloc(sizeof(int));
        scanf("%d",x);
        /* push the variable value to the object item */
        Push((StackItem)x, &s);
        printf("More ? Y or N\n");
        char ch = getch();
        if(ch == 'N')
        break;
    }
    //TraverseStack(&s,&Display);
    ClearStack(&s);

    TraverseStack(&s,&Display);

    return 0;
}
