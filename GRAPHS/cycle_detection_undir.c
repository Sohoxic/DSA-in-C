#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;

static unsigned int dfs(const edge *edges,unsigned int no_of_edge, unsigned int *visited,unsigned int vertices, unsigned int vertex, unsigned int predecessor){
    unsigned int i, cf=0;
    visited[vertex] = 1;
    for(i=0;i<no_of_edge && !cf;i++){
        if(edges[i].first == vertex || edges[i].second == vertex){
            const unsigned int next = edges[i].first == vertex? edges[i].second : edges[i].first;
            if(visited[next]==0)
            {
                cf=dfs(edges,no_of_edge,visited,vertices,next,vertex);
            }
            else if(next!=predecessor)
            {
                cf=1;
            }
          }
        }
        printf("%d\n",cf );

    return cf;          }


unsigned int cycle_finder(const edge *edges , unsigned int no_of_edge, unsigned int vertices)
{
   unsigned int *visited=calloc(vertices,sizeof(unsigned int));
   unsigned int cf;
   if (visited==NULL)
   {
       return 0;
   }
   cf=dfs(edges,no_of_edge,visited,vertices,0,0);
   free(visited);
   return cf;
}
/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int vertices;  /* number of vertices */
    unsigned int no_of_edge; /* number of edges */
    printf("enter no of edges\n");
    scanf("%d", &no_of_edge);
    printf("enter no of vertices\n");
    scanf("%d", &vertices);
    edge *edges;
    unsigned int ans;
    edges = malloc(no_of_edge*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<no_of_edge;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }

    ans= cycle_finder(edges, no_of_edge, vertices);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}
