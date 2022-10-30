#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 20

typedef struct heap{
int heap[SIZE];
int heapsize;
}NODE;
void init(NODE *h)
{
   h->heapsize=0;
   h->heap[0]=INT_MAX;
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void insert(NODE *h,int data)
{
    int c,p;
    h->heap[++(h->heapsize)]=data;
    c=h->heapsize;
    p=c/2;
    while(h->heap[p]<h->heap[c])
    {
        swap(&h->heap[p],&h->heap[c]);
        c=p;
        p=c/2;
    }
}
void insert_BottomUp(NODE *h)
{
    int p,c;
    for(p=(h->heapsize)/2;p>=1;p--)
    {
        c=2*p;
        while(c<=h->heapsize)
        {
            if(c+1<=h->heapsize && h->heap[c+1]>h->heap[c])
                c++;//to find the largest of two children
            if(h->heap[p]<h->heap[c])
                swap(&h->heap[p],&h->heap[c]);
            else
                break;
            p=c;
            c=2*p;
        }
    }
}
void display(NODE *h)
{
    if(h->heapsize>0)
    {
        printf("\n");
       for(int i=1;i<=h->heapsize;i++)
        printf("%d ",h->heap[i]);
    }
}
int deleteElement(NODE *h)
{
    int d,c,p;
    d=h->heap[1];
    h->heap[1]=h->heap[h->heapsize--];
    p=1;
    c=2*p;
    while(c<=h->heapsize)
    {
        if(c+1<=h->heapsize && h->heap[c+1]>h->heap[c])
            c++;
        if(h->heap[p]<h->heap[c])
            swap(&(h->heap[p]),&(h->heap[c]));
        else
            break;
       p=c;
       c=2*p;
        }
    return d;
}
int main()
{
    int d,ch;
    NODE *h1,*h2;
    h1=(NODE*)malloc(sizeof(NODE));
    init(h1);
    h2=(NODE*)malloc(sizeof(NODE));
    init(h2);
    do
    {
      printf("\nEnter the data");
      scanf("%d",&d);
      h2->heap[++(h2->heapsize)]=d; //Bottom up - construct a BT
      insert(h1,d);
      printf("\nPress 1 to Continue :");
      scanf("%d",&ch);
    }while(ch);
    display(h1);
    insert_BottomUp(h2);
    display(h2);
    printf("\n PRIORITY QUEUE - MAX HEAP:\n");
    if(h1->heapsize>=1)
    {
       int n=h1->heapsize;
       for(int i=1;i<=n;i++)
            printf("%d ",deleteElement(h1));
    }
    display(h1);
}
