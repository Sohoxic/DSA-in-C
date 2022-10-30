// #include<stdio.h>
//
// #define size 5
// typedef struct stack{
//   int top;
//   int arr[size];
// }STACK;
//
// void init(STACK *s){
//   s->top=-1;
// }
//
// STACK push(STACK *s,int ele){
//   (s->top)++;
//   s->arr[s->top]=ele;
// }
//
// STACK pop(STACK *s){
//   s->top--;
// }
//
// void display(STACK *s){
//   if(s->top==size){
//     printf("STACK OVERFLOW\n");
//   }
//   else{
//     int position = s->top;
//     for(int i=s->top;i>=0;i--){
//       printf("%d",s->arr[i]);
//     }
//     printf("\n");
//   }
// }
//
// void peep(STACK *s){
//   printf("%d",s->arr[s->top]);
// }
//
//
// int main(){
//   STACK s;
//   init(&s);
//   push(&s,1);
//   push(&s,2);
//   push(&s,3);
//   push(&s,4);
//   display(&s);
//   pop(&s);
//   display(&s);
//   return 0;
//
// }

                          // STACK USING LINKED LIST.
// #include <stdio.h>
// #include<stdlib.h>
// typedef struct stack{
//   int data;
//   struct stack *link;
// }Stack;
//
// void init(Stack *s){
//   s=NULL;
// }
//
// void push(Stack *s,int ele){
//   Stack *node = (Stack *)malloc(sizeof(Stack));
//   node->data=ele;
//   node->link=NULL;
//   if(s==NULL){
//     s=node;
//   }
//   else{
//     node->link = s;
//     s=node;
//   }
// }
//
// void display(Stack *s){
//   if(s==NULL){
//     printf("It's an empty stack\n");
//   }
//   else{
//     Stack *temp = s;
//     while(temp!=NULL){
//       printf("%d\n",temp->data);
//       temp=temp->link;
//     }
//   }
// }
//
// void pop(Stack *s){
//   Stack *temp= s;
//   s=s->link;
//   temp=NULL;
//   free(temp);
// }
//
//
// void main(){
//   Stack *s;
//   init(s);
//   push(s,1);
//   printf("%d",s->data);
//   display(s);
//   //printf("%d\n", );
//   // push(&s,2);
//   // push(&s,3);
//   // push(&s,4);
//   // display(&s);
//   // printf("\n");
//   // pop(&s);
//   // display(&s);
// }

              // QUEUE  ARRAY IMPLEMENTATION
// #include<stdio.h>
// #include <stdlib.h>
// #define size 10
//
// int queue[size];
//
// void init(int *front , int *rear){
//   *front = -1;
//   *rear = -1;
// }
//
// int isEmpty(int front, int rear){
//   return (front == rear && front ==-1);
// }
//
// int isFull(int front, int rear){
//   return((front == 0 && rear ==size -1) || (front == rear + 1)); // front == rear +1 use korchi jokhon front postion!=0 and circular queue r moton kaaj korche.
// }
//
// int isOneElement(int front, int rear){
//   return(front == rear && front!=-1);
// }
//
// void enqueue (int *front, int *rear, int ele){
//   if(isFull(*front,*rear)){
//     printf("QUEUE is full\n");
//   }
//   else if(isEmpty(*front,*rear)){
//     *front = *rear = 0;
//     queue[*rear]=ele;
//   }
//   else if(*rear == size - 1){
//     *rear = 0;
//     queue[*rear] = ele;
//   }
//   else{
//     (*rear)++;
//     queue[*rear]=ele;
//   }
// }
//
// void display(int front,int rear){
//     if(isEmpty(front,rear)){
//         printf("Queue is Empty \n");
//     }
//     else if (rear < front){
//         for(int i = front; i<=size-1; i++){
//             printf("%d \t",queue[i]);
//         }
//         for(int i = 0 ; i<=rear; i++){
//             printf("%d \t",queue[i]);
//         }
//         printf("\n");
//     }
//     else{
//         for(int i=front; i<=rear; i++){
//             printf("%d \t",queue[i]);
//         }
//         printf("\n");
//     }
// }
//
// void dequeue(int *front, int *rear){
//   if(isEmpty(*front,*rear)){
//     printf("queue is empty\n");
//   }
//   else if(isOneElement(*front, *rear)){
//     *rear=*front = -1;
//   }
//   else if(*front == size - 1){
//     front = 0;
//   }
//   else{
//     (*front)++;
//
//   }
// }
// int main(){
//   int front,rear;
//   init (&front,&rear);
//   enqueue(&front,&rear,1);
//   enqueue(&front,&rear,2);
//   enqueue(&front,&rear,3);
//   display(front,rear);
//   dequeue(&front,&rear);
//   display(front,rear);
//   return 0;
// }

                     // QUEUE IMPLEMENTATION USING LINKED LIST
// #include <stdio.h>
// #include <stdlib.h>
//
// typedef struct node{
//   int data;
//   struct node *next;
// }STACK;
//
// STACK *newnode,*temp;
// STACK *createnode(int data){
//   newnode = (STACK *)malloc(sizeof(STACK));
//   newnode -> data = data;
//   newnode -> next = NULL;
//   return newnode;
// }
//
// void init(STACK **front, STACK **rear){
//   *front = NULL;
//   *rear = NULL;
// }
//
// int isEmpty(struct node *front, struct node*rear){
//     return(front == NULL && rear == NULL);
// }
//
// int isOneElement(struct node *front, struct node *rear){
//     return(front == rear && rear != NULL);
// }
//
// void enqueue(STACK **front,STACK **rear,int ele){
//   newnode = createnode(ele);
//   if(isEmpty(*front,*rear)){
//     *front=*rear=newnode;
//   }
//   else{
//     (*rear)->next = newnode;
//      *rear = (*rear)->next;
//   }
// }
//
// void dequeue(struct node **front, struct node **rear){
//   if(isEmpty(*front,*rear)){
//         printf("The queue is empty\n");
//     }
//     else if(isOneElement(*front,*rear)){
//       *front = *rear = NULL;
//     }
//     else {
//       temp = *front;
//         *front = (*front)->next;
//         temp->next = NULL;
//         free(temp);
//     }
// }
//
// void display(struct node *front, struct node *rear){
//   printf("\n");
//     if(isEmpty(front,rear)){
//         printf("Queue is empty");
//     }
//     else {
//       for(temp = front; temp!= NULL; temp= temp->next){
//         printf("%d\n", temp->data );
//        }
//     }
// }
//
// int main()
// {
//   STACK *front,*rear;
//   init(&front,&rear);
//   for(int i=0; i<=5; i++){
//         enqueue(&front,&rear,i);
//         display(front,rear);
//     }
//     for(int i=0; i<=6; i++){
//         dequeue(&front,&rear);
//         display(front,rear);
//     }
//   return 0;
// }

                     // CIRCULAR QUEUE
// #include <stdio.h>
// #include <stdlib.h>
//
// struct node{
//     int data;
//     struct node*next;
//   };
//
// struct node *nn,*temp;
// struct node* createnode(int data){
// nn = (struct node*)malloc(sizeof(struct node));
// nn->data = data;
// // nn->next = NULL;             last node's next shd be pointed to the first node and this will be handled in methods
// return nn;
// }
//
// void init(struct node**front, struct node **rear){
//   *front = NULL;
//   *rear = NULL;
// }
// int isEmpty(struct node*front, struct node*rear){
//   return(front == NULL && rear == NULL);
// }
// int isOneElement(struct node*front, struct node*rear){
//   return(front == rear && rear != NULL);
// }
//
// void enqueue(struct node**front, struct node**rear, int data){
//   nn = createnode(data);
//                          //printf("%d",1234);
//   if(isEmpty(*front, *rear)){
//       *front = *rear = nn;         // first node inserted
//       (*rear)->next = *front;      // nn->next = *front
//    }
//
//   else{
//       (*rear)->next = nn;
//       *rear = (*rear)->next;
//       nn->next = *front;
//   }
//                          //printf("%d",()->data);
// }
//
//
// void dequeue(struct node**front,struct node**rear){
//       if(isEmpty(*front,*rear)){
//         printf("The queue is empty\n");
//       }
//       else if (isOneElement(*front,*rear)){
//         *front = *rear = NULL;
//       }
//       else{
//         temp = *front;
//         *front = (*front)->next;
//         (*rear)->next = *front;
//         temp->next = NULL;
//         free(temp);
//        }
// }
//
// void display(struct node*front,struct node*rear){
//       if(isEmpty(front,rear)){
//         printf("Queue is empty");
//       }
//       else {
//         //printf("%d",front->data);
//         temp=front;
//         while(temp!=rear){
//             printf("%d",temp->data);
//             temp=temp->next;
//           }
//         printf("%d",temp->data);
//
//         }
//         printf("\n");
// }
//
//
// int main(){
//     struct node*front, *rear;
//     init(&front,&rear);
//     enqueue(&front,&rear,1);
//     enqueue(&front,&rear,2);
//     enqueue(&front,&rear,3);
//     enqueue(&front,&rear,4);
//     display(front,rear);
//     for(int i=0; i<=3; i++){
//         dequeue(&front,&rear);
//         display(front,rear);
//     }
//     return 0;
// }

                // PRIORITY QUEUE
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
                    // display(front,rear);
                    // printf("----------------------\n");
                    enqueue(&front,&rear,4,3);
                    enqueue(&front,&rear,4,6);
                    enqueue(&front,&rear,4,5);
                    enqueue(&front,&rear,4,2);
                    display(front,rear);
                    printf("-----------------------\n");
                    dequeue(&front,&rear);
                    dequeue(&front,&rear);
                    // dequeue(&front,&rear);
                    display(front,rear);
                }
