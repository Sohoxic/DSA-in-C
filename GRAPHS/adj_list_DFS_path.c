//Different paths using DFS_list
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

struct node
{
    int data;//vertex
    struct node *next;
};
void create_graph(struct node *l)
{
    int v,from,to;
    v=l[0].data;
    for(int i=1;i<=v;i++)
    {
        l[i].data=i;
        l[i].next=NULL;
    }
    while(1)
    {
        printf("\nEnter the edge(v1 v2):");
        scanf("%d %d",&from,&to);
        if(from<1 || from>v ||to<1 || to>v)
            return;
        struct node *t,*nn;
        nn=(struct node*)malloc(sizeof(struct node));
        t=&l[from];
        while(t->next!=NULL)
            t=t->next;
        t->next=nn;
        nn->data=to;
        nn->next=NULL;
    }
}
void display(struct node *l)
{
    struct node *t;
    for(int i=1;i<=l[0].data;i++)
    {
       t=&l[i];
       printf("\n%d=>",t->data);//optional
       while(t->next!=NULL)
       {
           t=t->next;
           printf("%d ",t->data);
       }
    }
}

void dfs_path(struct node *l,int source,int dest,int *visited,int *path)
{
    static int count;
    struct node *t;
    t=&l[source];
    visited[source]=1;
    path[count++]=source;
    if(source==dest)
    {
        printf("\n");
        for(int i=0;i<count;i++)
        {
            printf("%d ",path[i]);
        }
    }
    else{
    while(t->next!=NULL)
        {
        t=t->next;
        if(visited[t->data]==0)//if unvisited
            dfs_path(l,t->data,dest,visited,path);
        }
    }
    count--;
    visited[source]=0;
}
int main()
{
    int ch,v,source,dest,*visited,*path;
    struct node l1[MAX_NODES];
    printf("\nEnter the no. of vertices:");
    scanf("%d",&v);
    l1[0].data=v;
    l1[0].next=NULL;
    visited=(int*)calloc(v+1,sizeof(int));
    path=(int*)calloc(v,sizeof(int));
    create_graph(l1);
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1.Display");
        printf("\n2.DFS_path");
        printf("\n3.Quit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1://Display
            display(l1);
            break;
        case 2:
            printf("\nEnter the source and destination vertex:");
            scanf("%d %d",&source,&dest);
            dfs_path(l1,source,dest,visited,path);
            break;
        case 3://Quit
            return;
        }
    }
}
