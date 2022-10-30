#include<stdio.h>
#include<stdlib.h>

struct graph{
    int v;  // total no. of vertices in the graph
    int mat[20][20];
    int visited[20];
};

void create_graph(struct graph* g){
  printf("enter no. of vertex");
  int v;
  scanf("%d", &g->v );
  for(int i=1;i<=g->v;i++){
    for(int j=1;j<=g->v;j++)
      g->mat[i][j] = 0;
  }

  while(1){
    int v1,v2;
    printf("enter edge (v1,v2)\n");
    scanf("%d",&v1); scanf("%d",&v2);
    if(v1<=g->v && v2<=g->v && v1>0 && v2>0){
      g->mat[v1][v2] = 1;
    }
    else{
      break;
    }
  }
}

void display(struct graph* g){
  for(int i=1;i<=g->v;i++){
    for(int j=1;j<=g->v;j++)
      printf("%d", g->mat[i][j]);
    printf("\n");
  }
}

void indegree(struct graph *g,int v){
  int count=0;
  for(int j=1;j<=g->v;j++)
    if(g->mat[j][v])
      count++;

  printf("indegree of the vertex %d is %d\n",v,count);
}

void outdegree(struct graph *g,int v){
  int count=0;
  for(int j=1;j<=g->v;j++)
    if(g->mat[v][j])
      count++;

  printf("outdegree of the vertex %d is %d\n",v,count);
}

void init_visited(struct graph* g){
  for(int i=0; i<g->v; i++){
    g->visited[i]=0;
  }
}

void dfs(struct graph* g, int s){
  printf("%d\n",start );
  g->visited[start] = 1;
  for(int j=1; j<g->v; j++){
    if(g->mat[start][i]==1 && g->visited[i]==0){
      dfs(g,i);
    }
  }
}

int main(){
  struct graph g;
  int ch,v,start;
  create_graph(&g);
  while(1){
    printf("1.display 2.indegree 3.outdegree 4.quit");
    scanf("%d",&ch);
    switch(ch){
       case 1: display(&g);  break;
      case 2: printf("enter the vertex whose indegree you want to find\n");
              scanf("%d\n", &v );
              indegree(&g,vertex); break;
      case 3: printf("enter the vertex whose outdegree you want to find\n");
              scanf("%d\n", &v );
              outdegree();  break;
      case 4: init_visited(&g);
              printf("enter starting index\n");
              scanf("%d\n", &start);
              dfs(&g1,start);
      case 5: return 0;
    }
  }
  return 0;
}
