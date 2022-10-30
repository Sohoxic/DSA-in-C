#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct stack{
    NODE *top;
}STACK;

STACK *s;
void init(STACK *s)
{
    s->top=NULL;
}

void push(STACK *s,int data)
{
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->next=s->top;
    s->top=nn;
}

int isempty(STACK *s)
{
    if(s->top==NULL)
    {
        printf("Stack is empty");
        return 1;
    }
    return 0;
}

void pop(STACK *s)
{
    if(!isempty(s))
    {
        NODE *t;
        t=s->top;
        s->top=t->next;
        t->next=NULL;
        free(t);
    }
}

void peep(STACK *s)
{
    NODE *t=s->top;
    if(!isempty(s))
    {
        printf("\nTop most element:%d",t->data);
    }
}
void display(STACK *s)
{
    NODE *t=s->top;
    if(!isempty(s))
    {
        while(t!=NULL){
           printf("%d ",t->data);
           t=t->next;
        }
    }
}

int main()
{

}
