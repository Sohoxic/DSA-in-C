#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

struct node *t1,*t2;
void creat();
void insert();
void display();
void del_alt_node();
void main(){
    int ch;

    do
    {
        printf("\n1.Creat a list \n2.Insert a elements\n3.Delete alternate node\n4.Display elements\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            creat();
            //insert();
            break;
        case 2:
            insert();
            break;
        case 3:
            del_alt_node();
            break;
        case 4:
            display();
            break;

        default:
            break;
        }
    } while (ch);
    scanf("%d",&ch);

}
void creat(){
    if (head==NULL)
    {
        int no;
        head=(struct node*)malloc(sizeof(struct node));
        printf("Enter the first element");
        scanf("%d",&no);
        head->data=no;
        head->next=NULL;
    }
    else
    {
        printf("List already exists");
    }
}
void insert(){
    if (head==NULL)
    {
        creat();
    }
    else{
    int ch,no;
    printf("Enter the element to be inserted");
    scanf("%d",&no);
    printf("Enter your choice:1.Insert at beginning \n 2.At end \n 3.At middle");
    scanf("%d",&ch);
    t1=(struct node*)malloc(sizeof(struct node));
    t1->data=no;
    switch (ch)
    {
    case 1:
    {
        t1->next=head;
        head=t1;
        break;
    }
    case 2:
    {
        t1->next=NULL;
        t2=head;
        while (t2->next!=NULL)
        {
            t2=t2->next;
        }
        t2->next=t1;
        break;
    }
    case 3:
    {
        int pos;
        printf("Enter the position to be inserted");
        scanf("%d",&pos);
        t2=head;
        for (int i = 0; i < pos-1; i++)
        {
            if (t2->next!=NULL)
            {
                t2=t2->next;
            }
            else
            {
                printf("Inapp position,hence inserted at end");
                break;
            }
        }
        t1->next=t2->next;
        t2->next=t1;
        break;
    }

    default:
        break;
    }
    }
}

void del_alt_node() {
       if (head == NULL)
          return;
       struct node *prev = head;
       struct node *node = head->next;
       while (prev != NULL && node != NULL) {
          prev->next = node->next;
          free(node);
          prev = prev->next;
          if (prev != NULL) {
             node = prev->next;
          }
       }
    }


void display(){
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        t1=head;
        printf("\n%d ",t1->data);
        while (t1->next!=NULL)
        {
            t1=t1->next;
            printf("%d->",t1->data);
        }
        printf("NULL");
    }
}
