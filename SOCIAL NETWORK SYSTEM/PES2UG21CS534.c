#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

int Empty(node *emp)
{
    return (emp==NULL);
}

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user=malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token=strtok(strfriends,"|");
    int i=0;
    while( token != NULL )
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i+=1;
        token=strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}



//search for user with id=key
struct node* search(int key, struct node *users)
{
    //CODE HERE
    if(Empty(users))
        return NULL;
    while(users)
    {

        if(key>users->id)
            users=users->right;
        else if(key<users->id)
            users=users->left;
        else
            return users;
    }
    return NULL;
}
//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    user->left=NULL;
    user->right=NULL;
 int flag=0;
 while (flag != 1)
     if(search(user->id, users)==NULL)
     {
        flag=1;
     }
     else
     {
         (user->id)++;
     }

 int j=0;
 while (j != user->numfren)
 {
     node *sc;
     sc=search(user->friends[j],users);
     if(sc != NULL)
     {
         j=j+1;
         sc->friends[sc->numfren]=user->id;
         (sc->numfren)++;
     }
     else
     {
         user->friends[user->numfren]=0;

         for (int k=j; k<user->numfren; k+=1)
         {
             user->friends[k]=user->friends[k + 1];
         }
         (user->numfren)--;
     }
 }
 if(j==0)
 {
     user->friends[j]=-1;
 }

 return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
  /*
    //CODE HERE
    if(Empty(root))
       root=user;
    else{
        if(root->id<id)
          root->left=insertUser(root->left,id,user);
        else
          root->right=insertUser(root->right,id,user);
    }
    return root;
}
*/
struct node *root1=root;
    if(Empty(root1))
    {
        root=user;
    }
    else
    {
        while (true)
        {
            if(id>=root1->id)
            {

                if(root1->right==NULL)
                {
                    root1->right=user;
                    break;
                }
                else
                {
                    root1=root1->right;
                }
            }
            else if(id<root1->id)
            {
                if(root1->left==NULL)
                {
                    root1->left=user;
                    break;
                }
                else
                {
                    root1=root1->left;
                }
            }
        }
    }
    return root;
  }

//prints friends list
void friends(int id, struct node *users)
{
   //CODE HERE
   node* sea=search(id, users);
   if(!Empty(sea)){
     if(sea->numfren==0)
        printf("%d\n",-1);
     else{
      for(int i=0;i<sea->numfren;i+=1){
         printf("%d\n",sea->friends[i]);
      }
   }
   }
   else
    {
        printf("%d\n", -1);
    }
}
/*
void searchNode(node **t,int data,node **parent)
{
    while((*t)->id!=data)
    {
        *pant;
        if(data<=(t)->id)
                t=(t)->left;
        else
            *t=(*t)->right;
    }
}*/

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValuenode(struct node *node) {
  //CODE HERE
    struct node *s=node;
    if(s->right!=NULL)
        s=s->right;
    while(s->left!=NULL)
        s=s->left;
    return s;
}


//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
    node *t=users;
    if(Empty(t))
        return NULL;
    for (int i=0; i<t->numfren; i+=1)
        {
            struct node* tp;
            tp=search(t->friends[i], users);
            for (int j=0; j<tp->numfren; j+=1)
            {
                if(tp->friends[j]==key)
                {
                    tp->friends[tp->numfren]=0;
                    for (int k=j; k<tp->numfren; k+=1)
                    {
                        tp->friends[k]=tp->friends[k + 1];
                    }
                    --(tp->numfren);
                    break;
                }
                else
                    j+=1;
            }
        }
        return users;

}

// Deleting a node
struct node *deletenode(struct node *root, int key) {
  //CODE HERE
    if(Empty(root))
    {
        printf("empty!!");
    }
    else
    {
        if(key<root->id)
        {
            root->left=deletenode(root->left, key);
        }
        else if(key>root->id)
        {
            root->right=deletenode(root->right, key);
        }

        else if(root->left==NULL)
        {
            node *tp=root->right;
            free(root);
            return tp;
        }
        else if(root->right==NULL)
        {
            node *tp=root->left;
            free(root);
            return tp;
        }
        else
        {
            node *tp=minValuenode(root);
            root->id=tp->id;
            strcpy(root->name, tp->name);
            root->right=deletenode(root->right, tp->id);
        }
    }

    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers)
{
    //CODE HERE
    if(Empty(myusers))
        return;
    else{
        printInOrder(myusers->left); //L
        printf("%d %s\n",myusers->id, myusers->name); //v
        printInOrder(myusers->right);//R
    }
}


int main(int argc, char **argv)
{
    node *users=NULL;
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:

                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:

                scanf("%d", &id);
                deleteFriends(id, users);
                users=deletenode(users, id);
                break;

            case 3:

                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL)
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}
