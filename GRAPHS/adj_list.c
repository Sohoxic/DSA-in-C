//Adjacency List
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
    printf("\nEnter the no. of vertices:");
    scanf("%d",&v);
    l[0].data=v;
    l[0].next=NULL;
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
void indegree(struct node *l,int v)
{
    int count=0;
    struct node *t;
    for(int i=1;i<=l[0].data;i++)
    {
        t=&l[i];
        while(t->next!=NULL)
        {
            t=t->next;
            if(t->data==v)
                count++;
        }
    }
    printf("\n The Indegree of the vertex %d is %d",v,count);
}
void outdegree(struct node *l,int v)
{
    int count=0;
    struct node *t=&l[v];
    while(t->next!=NULL)
    {
        count++;
        t=t->next;
    }
    printf("\n The Outdegree of the vertex %d is %d",v,count);
}
void init_visited(int *visited, int v)
{
    for(int i=0;i<=v;i++)
        visited[i]=0;
}
void dfs(struct node *l,int start,int *visited)
{
    struct node *t;
    printf("%d ",start);
    visited[start]=1;
    t=&l[start];
    while(t->next!=NULL)
    {
        t=t->next;
        if(visited[t->data]==0)//if unvisited
            dfs(l,t->data,visited);
    }

}
int main()
{
    int ch,v,start,visited[MAX_NODES];
    struct node l1[MAX_NODES];
    create_graph(l1);
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1.Display");
        printf("\n2.Indegree of a node");
        printf("\n3.Outdegree of a node");
        printf("\n4.DFS");
        printf("\n5.Quit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1://Display
            display(l1);
            break;
        case 2://Indegree of a node
            printf("\nEnter the vertex:");
            scanf("%d",&v);
            indegree(l1,v);
            break;
        case 3://Outdegree of a node
            printf("\nEnter the vertex:");
            scanf("%d",&v);
            outdegree(l1,v);
            break;
        case 4:
            init_visited(visited,l1[0].data);
            printf("\nEnter the source vertex:");
            scanf("%d",&start);
            dfs(l1,start,visited);
            break;
        case 5://Quit
            return;
        }
    }
}
