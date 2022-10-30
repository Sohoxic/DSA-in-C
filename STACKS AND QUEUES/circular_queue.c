
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
    // nn->next = NULL;             last node's next shd be pointed to the first node and this will be handled in methods
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
    //printf("%d",1234);
    if(isEmpty(*front, *rear)){
        *front = *rear = nn;         // first node inserted 
        (*rear)->next = *front;      // nn->next = *front 
    }
        
    else{
        (*rear)->next = nn; 
        *rear = (*rear)->next;
    }
    //printf("%d",()->data);
} 

 
void dequeue(struct node**front,struct node**rear){
    if(isEmpty(*front,*rear)){
        printf("The queue is empty\n");
    }
    else if (isOneElement(*front,*rear)){
        *front = *rear = NULL;
    } 
    else{
        temp = *front;
        *front = (*front)->next; 
        (*rear)->next = *front;
        temp->next = NULL; 
        free(temp);
    }
}  

void display(struct node*front,struct node*rear){
    if(isEmpty(front,rear)){
        printf("Queue is empty");
    }
    else {
    	//printf("%d",front->data);
    	temp=front;
    	while(temp!=rear){
    		printf("%d",temp->data);
    		temp=temp->next;
    	}
    	printf("%d",temp->data);
 
    }
    printf("\n");
}


int main(){
    struct node*front, *rear; 
    init(&front,&rear); 
   	enqueue(&front,&rear,1);
   	enqueue(&front,&rear,2);
   	enqueue(&front,&rear,3);
   	enqueue(&front,&rear,4);
    display(front,rear);
    for(int i=0; i<=3; i++){
        dequeue(&front,&rear);
        display(front,rear);
    }
    return 0; 
}
