#include <stdio.h> 
#include <stdlib.h> 

struct node{
    int data;
    struct node*next;
};

struct node *nn,*temp;  
struct node* createnode(int data){
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

void init(struct node**front, struct node **rear){
    *front = NULL;
    *rear = NULL; 
}

int isEmpty(struct node*front, struct node*rear){
    return(front == NULL && rear == NULL);
}

int isOneElement(struct node*front, struct node*rear){
    return(front == rear && rear != NULL);
}

void enqueue(struct node**front, struct node**rear, int data){
    nn = createnode(data); 
    if(isEmpty(*front, *rear))
        *front = *rear = nn; 
    else{
        (*rear)->next = nn; 
        *rear = (*rear)->next;
    }
} 

 
void dequeue(struct node** front,struct node** rear){
    if(isEmpty(*front,*rear)){
        printf("The queue is empty\n");
    }
    else if (isOneElement(*front,*rear)){
        *front = *rear = NULL;
    } 
    else{
        temp = *front;
        *front = (*front)->next; 
        temp->next = NULL; 
        free(temp);
    }
}  

void display(struct node*front,struct node*rear){
    printf("\n");
    if(isEmpty(front,rear)){
        printf("Queue is empty");
    }
    else {
        for(temp = front; temp!=NULL;temp=temp->next){
            printf("%d ",temp->data);
        }
    }
}


int main(){
    struct node*front, *rear; 
    init(&front,&rear); 
    for(int i=0; i<=5; i++){
        enqueue(&front,&rear,i);
        display(front,rear);
    }
    for(int i=0; i<=6; i++){
        dequeue(&front,&rear);
        display(front,rear);
    }
    return 0; 
}
