#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int lthread;
    int rthread;
    struct node *left;
    struct node *right;
}NODE;

NODE* createNode(int data)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    return nn;
}
NODE* inorderSuccessor(NODE *t)
{
    if(t->rthread==1)
        return t->right; 
    else
    {
        if(t->rthread==0)
            t=t->right;
        while(t->lthread==0)
            t=t->left;
        return t;
    }
}
void inorder(NODE *root)
{
    NODE *t=root;
    if(root==NULL)
        printf("Tree is empty");
    else
    {
        while(t->lthread==0)
            t=t->left;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=inorderSuccessor(t);
        }
    }
}
NODE* insertNode(NODE *root,int data)
{
    NODE *t=root,*parent,*nn;
    nn=createNode(data);
    if(root==NULL)
    {
        root=nn;
        root->lthread=0;
        root->rthread=0;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    while(t!=NULL)
    {
        parent=t;
        if(data<t->data)
        {
            if(t->lthread==0)
                    t=t->left;
            else
                break;
        }
        else if(data>t->data)
        {
           if(t->rthread==0)
                    t=t->right;
            else
                break;
        }
        else
        {
            printf("Duplicate data");
            return root;
        }
    }
    if(data<parent->data)//left child
    {
        nn->lthread=1;
        nn->rthread=1;
        nn->left=parent->left;
        nn->right=parent;
        parent->left=nn;
        parent->lthread=0;

    }
    else//right child
    {
        nn->lthread=1;
        nn->rthread=1;
        nn->left=parent;
        nn->right=parent->right;
        parent->right=nn;
        parent->rthread=0;
    }
return root;
}
int main()
{
    NODE *tbst=NULL;
    int d,ch;
    do{
     printf("\nEnter the data :");
     scanf("%d",&d) ;
     tbst=insertNode(tbst,d);
     printf("\nTo continue press 1 :");
     scanf("%d",&ch) ;
    }while(ch);
    inorder(tbst);
    return 1;
}
