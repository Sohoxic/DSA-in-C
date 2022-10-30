#include <stdio.h>
#define SIZE 5 
struct node{
    int d;
    int p; 
}; 

struct node Q[SIZE]; 

int isEmpty(int f, int r){
    return (f == r && f==-1);
}

int isFull(int f,int r){
    return(r == SIZE-1);
}
 
int oneElement(int f,int r){
    return(f == r && f != -1);
}

void enqueue(int *f, int *r, int data, int p){
    if(isFull(*f,*r)) 
        printf("The priority queue is Full \n");
    else if(isEmpty(*f,*r)){
        *f = *r = 0; 
        Q[*r].d = data; 
        Q[*r].p = p;
    }
    else{
        int t1,t2;
        t1 = *f; 
        while(p<Q[t1].p)
            t1++;
        t2 = ++*r;
        while(t2>t1){
            Q[t2].d = Q[t2 - 1].d; 
            Q[t2].p = Q[t2-1].p;
            t2--;
        }
        Q[t1].d = data;
        Q[t1].p = p; 
    }
} 

void dequeue(int *f, int *r){
    if(isEmpty(*f,*r)){
        printf("The queue is empty \n");
    }
    else if (oneElement(*f,*r)){
        *f = *r = -1;
    }
    else 
        ++*f;  // changed to ++ ,0th index is lost and so on
}

void display(int f, int r){
    if(!isEmpty(f,r)){
        for(int i = f; i<=r; i++){
            printf("The priority is %d and the data is %d \n",Q[i].p,Q[i].d);
        }
    }
}


int main(){
    int front = -1,rear = -1;  
    printf("%d %d \n ",front,rear); 
    enqueue(&front,&rear,5,1); 
    display(front,rear);
    printf("----------------------\n");
    enqueue(&front,&rear,4,3);
    enqueue(&front,&rear,4,6);
    enqueue(&front,&rear,4,5);
    enqueue(&front,&rear,4,2); 
    display(front,rear);
    printf("-----------------------\n");
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front,rear);
}