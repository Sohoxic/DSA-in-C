#include<stdio.h>
#include<stdlib.h>

struct graph{
  int data;
  struct graph* next;
};

void create_graph(struct graph *g){
  //int v;
  printf("enter no. of vertices\n");
  scanf("%d",&g[0].data);
  g[0].next=NULL;
  for(int i=1;i<=g[0].data;i++){
    g[i].data = i;
    g[i].next = NULL;
  }
  while(1){

    int v1,v2;
    printf("enter the edges(v1,v2)\n");
    scanf("%d %d",&v1,&v2);
    if(v1>=1 && v2>0 && v1<=g[0].data && v2<=g[0].data){
      struct graph* t=NULL;
      struct graph* nn = (struct graph*)malloc(sizeof(struct graph));
      t = &g[v1];
      while(t->next!=NULL){
        t=t->next;
      }
      t->next = nn;
      nn->data = v2;
      nn->next = NULL;
    }
    else{
      return;
    }
    }

}


void display(struct graph* g){
  struct graph* t;
  for(int i=1;i<=g[0].data;i++){
    t = &g[i];
    printf("\n%d=>",t->data);
    while(t->next!=NULL){
      t=t->next;
      printf("%d\n",t->data);
    }
  }
}

void indegree(struct graph* g, int v){
  struct graph* t = NULL;
  int count=0;
  for(int i=1;i<g[0].data;i++){
    t = &g[i];
    while(t->next!=NULL){
      t = t->next;
      if(t->data == v){
        count++;
      }
    }
  }

  printf("The indegree of the vertex %d is %d\n", v, count );
}

void outdegree(struct graph* g, int v){
  struct graph* t = &g[v];
  int count=0;
  while(t->next!=NULL){
    t=t->next;
    count++;
  }
  printf("The outdegree of the vertex %d is %d\n", v, count );
}

int main(){
  struct graph g[20];
  create_graph(g);
  int ch,v;
  while(1){
    printf("1.display 2.indegree 3.outdegree 4.quit");
    scanf("%d",&ch);
    switch(ch){
       case 1: display(g);  break;
      case 2: printf("enter the vertex whose indegree you want to find\n");
              scanf("%d", &v );
              indegree(g,v); break;
      case 3: printf("enter the vertex whose outdegree you want to find\n");
              scanf("%d", &v );
              outdegree(g,v);  break;
      case 4: return 0;
    }
  }
  return 0;
  return 0;
}
