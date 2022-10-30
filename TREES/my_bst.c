#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}bst;

bst* createnode(int data){
    bst *newnode = (bst*)malloc(sizeof(bst));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int isEmpty(bst *node){
    return (t==NULL);
}

bst* insertNode(bst* root,int data){
    if(isEmpty(root)){
        root = createnode(data);
    }
    else if(data<=root){
        insertNode(root->left,data);
    }
    else
        root->right=insertNode(root->right,data);
    else return;
}

void inorder(bst* node){
    if(isempty(t))
        printf("Tree ie empty");
    else{
        if(t->left!=NULL){
            inorder(node->left);
        }
        printf("%d",node->data);
        if(t->right!=NULL){
            inorder(node->right);
        }
    }
}

void postorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else{

        if(t->left!=NULL)
            postorder(t->left); //L
        if(t->right!=NULL)
            postorder(t->right);//R
         printf("%d ",t->data); //v
    }
}

void preorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else{
        printf("%d ",t->data); //v
        if(t->left!=NULL)
            preorder(t->left); //L
        if(t->right!=NULL)
            preorder(t->right);//R
    }

}

searchNode(bst **t,int data, bst** parent){
    while(data!=(*t)->data && t!=NULL){
        if(data <= *(t)->data){
            *(t)=*(t)->left;
        }
        else
            *t=(*t)->right;

    }
}

NODE* inordersuccessor(NODE* t)
{
    NODE *s=t;
    if(s->right!=NULL)
        s=s->right;
    while(s->left!=NULL)
        s=s->left;
    return s;
}

void deleteNode(bst* root, int data){
    bst* parent=null,temp=root;
    while(data!=temp->data){
        searchNode(&temp,data,&parent)
    }
    if(isEmpty(temp)){
        printf("NO DATA FOUND");
        return root;
    }
    // case 1 : leaf node condition
    if(temp->left == NULL && temp->right == NULL){
        if(parent == NULL){
            root = NULL;
        }
        else if(parent->left==temp)//left child
            parent->left=NULL;
        else                    //right child
            parent->right=NULL;
        free(t);
            
    }
    // case 2 : one child condition
    else if(t->left==NULL || t->right==NULL)
    {
        if(parent==NULL)//root
        {
            if(t->left!=NULL)//left child
            {
                root=root->left;
                t->left=NULL;//optional
            }
            else
            {
              root=root->right;
              t->right=NULL;//optional
            }
        }
        else
        {
            if(parent->left==temp)//left child of parent
            {
                if(temp->left!=NULL)
                    parent->left=temp->left;
                else
                    parent->left=temp->right;
            }
            else
            {
                if(temp->left!=NULL)
                    parent->right=temp->left;
                else
                    parent->right=temp->right;
            }
        }
        free(t);
    }
    else{
        
    }

}

int main(){

    return 0;
}