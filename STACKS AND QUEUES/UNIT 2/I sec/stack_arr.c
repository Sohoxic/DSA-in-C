#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct stack
{
    int top;
    int arr[MAX];
};
typedef struct stack STACK;
STACK *s;
void init(STACK *s)
{
    s->top=-1;
}

int isempty(STACK *s)
{
    if(s->top==-1)
    {
       printf("The Stack is empty");
       return 1;
    }
    return 0;
}
int isfull(STACK *s)
{
    if(s->top==MAX-1)
    {
       printf("The Stack is full");
       return 1;
    }
    return 0;
}
void push(STACK *s,int data)
{
    if(!isfull(s))
    {
       s->top++;
       s->arr[s->top]=data;
       printf("Inserted:%d",s->arr[s->top]);
    }
}

void pop(STACK *s)
{
    if(!isempty(s))
    {
        printf("Deleted:%d",s->arr[s->top]);
        s->top--;
    }
}

void peep(STACK *s)
{
if(!isempty(s))
    {
        printf("The last element:%d",s->arr[s->top]);
    }
}
void display(STACK *s)
{
if(!isempty(s))
    {
        for(int i=s->top;i>=0;i--)
            printf("%d ",s->arr[i]);
    }
}
