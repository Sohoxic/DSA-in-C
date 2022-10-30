#include<stdio.h>
#include <stdlib.h>
#define size 10

int queue[size];

void init(int *front , int *rear){
  *front = -1;
  *rear = -1;
}

int isEmpty(int front, int rear){
  return (front == rear && front ==-1);
}

int isFull(int front, int rear){
  return((front == 0 && rear ==size -1) || (front == rear + 1)); // front == rear +1 use korchi jokhon front postion!=0 and circular queue r moton kaaj korche.
}

int isOneElement(int front, int rear){
  return(front == rear && front!=-1);
}

void enqueue (int *front, int *rear, int ele){
  if(isFull(*front,*rear)){
    printf("QUEUE is full\n");
  }
  else if(isEmpty(*front,*rear)){
    *front = *rear = 0;
    queue[*rear]=ele;
  }
  else if(*rear == size - 1){
    *rear = 0;
    queue[*rear] = ele;
  }
  else{
    (*rear)++;
    queue[*rear]=ele;
  }
}

void display(int front,int rear){
    if(isEmpty(front,rear)){
        printf("Queue is Empty \n");
    }
    else if (rear < front){
        for(int i = front; i<=size-1; i++){
            printf("%d \t",queue[i]);
        }
        for(int i = 0 ; i<=rear; i++){
            printf("%d \t",queue[i]);
        }
        printf("\n");
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d \t",queue[i]);
        }
        printf("\n");
    }
}

void dequeue(int *front, int *rear){
  if(isEmpty(*front,*rear)){
    printf("queue is empty\n");
  }
  else if(isOneElement(*front, *rear)){
    *rear=*front = -1;
  }
  else if(*front == size - 1){
    front = 0;
  }
  else{
    (*front)++;

  }
}
int main(){
  int front,rear;
  init (&front,&rear);
  enqueue(&front,&rear,1);
  enqueue(&front,&rear,2);
  enqueue(&front,&rear,3);
  display(front,rear);
  dequeue(&front,&rear);
  display(front,rear);
  return 0;
}
