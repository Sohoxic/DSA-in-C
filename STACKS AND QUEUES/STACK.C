#include<stdio.h>
#define stacksize 5

typedef struct stack
{
    int top;
    int items[stacksize];

}stack;


void init(stack *p)
{
    p->top=-1;
}

stack push(stack *p,int ele)
{
    p->top=p->top+1;
    p->items[p->top]=ele;


}

void display(stack *p)
{
    if(p->top==stacksize)
    {
        printf("it is overflow");
    }
    else
    {
        int size=p->top;
        for(int i=size;i>=0;i--)
        {
            printf("%d\n",p->items[size]);
            size--;
        }

    }
    
}

void pop(stack *p)
{
    int del;
    del=p->top;
    p->top=p->top-1;
    printf("the deleted element of the stack",p[del]);



}

void peep(stack *p)
{
    printf("the top element of the stack",p->items[p->top]);
}

int main()
{
    stack head;
    init(&head);
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    display(&head);
  

    


}

