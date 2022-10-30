#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10
typedef struct TreeNode
{
    int utype;
    union
    {
        float operand;
        char operater;
    }u;
    struct TreeNode *left;
    struct TreeNode *right;
}NODE;
static int top=-1;
void push(NODE *d,NODE **stack)
{
   if(top>=MAX)
    printf("STACK FULL");
  else
    stack[++top]=d;
}
NODE* pop(NODE *stack[])
{
   if(top==-1)
   {
     printf("STACK EMPTY");
     return NULL;
   }
   else
    return stack[top--];
}
NODE* construct(char exp[],NODE s1[])
{
    int i=0;
    NODE *nn;
    while(exp[i])
    {
      if(isdigit(exp[i]))//operand
      {
        nn=(NODE*)malloc(sizeof(NODE));
        nn->utype=1;
        nn->u.operand=exp[i]-'0';
        nn->left=NULL;
        nn->right=NULL;
        push(nn,&s1);
      }
      else{
        nn=(NODE*)malloc(sizeof(NODE));
        nn->utype=2;
        nn->u.operater=exp[i];
        nn->right=pop(&s1);
        nn->left=pop(&s1);
        push(nn,&s1);
      }
      i++;
    }
return pop(&s1);
}
void inorder(NODE *bst)
{
    if(bst!=NULL)
    {
       inorder(bst->left);
       if(bst->utype==1)
        printf("%g ",bst->u.operand);
       else
        printf("%c ",bst->u.operater);
       inorder(bst->right);
    }
}
float calculate(float x,float y,char op)
{
    float res;
    switch(op)
    {
    case '+':
        res=x+y;
        break;
    case '-':
        res=x-y;
        break;
    case '*':
        res=x*y;
        break;
    case '/':
        res=x/y;
        break;
    }
    return res;
}
float evaluate(NODE *t)
{
    if(t->utype==1)
        return t->u.operand;
    float x=evaluate(t->left);
    float y=evaluate(t->right);
    return calculate(x,y,t->u.operater);
}
int main()
{
    NODE *bst=NULL,stack[MAX];
    char exp[MAX]="567*+8-";
    bst=construct(exp,stack);
    printf("\n");
    inorder(bst);
    printf("\nResult=%g",evaluate(bst));
return 0;
}
