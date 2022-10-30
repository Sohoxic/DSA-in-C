#include<stdio.h>
#define SIZE 10
typedef struct node{
int data;
int flag;
}NODE;
void insertNode(NODE *bst,int data,int index)
{
    if(index>=SIZE)
        printf("Cannot Insert data");
    else
    {
        if(bst[index].flag==0)
        {
           bst[index].data=data;
           bst[index].flag=1;
        }
        else if(data<=bst[index].data)
        {
            index=2*index+1;
            insertNode(bst,data,index);
        }
        else
        {
            index=2*index+2;
            insertNode(bst,data,index);
        }
    }
}
void inorder(NODE *bst,int index)
{
    if(index<SIZE && bst[i].flag)
    {
        inorder(bst,2*index+1);
        printf("%d ",bst[index].data);
        inorder(bst,2*index+2);
    }
}
int main()
{ 
    NODE bst[SIZE]={}; //initialises the structure array to 0.
    int d,ch;
    do{
    printf("\nEnter data:");
    scanf("%d",&d);
    insertNode(bst,d,0);
    printf("\n");
    inorder(bst,0);
    printf("To Continue Press 1: ");
    scanf("%d",&ch);
    }while(ch);
}
