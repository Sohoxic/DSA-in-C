#include<stdio.h>
typedef struct node{
  int data;
  struct node *link;
}node;

void create(node *head){
  node *temp=(node*)malloc(sizeof(node));
  int n;
  scanf("%d\n",&n);
  temp->data=n;
  temp->link=NULL;
  if(head==NULL){
    head=temp;
  }

}
void insert_beg(node *head){
  node *temp=(node*)malloc(sizeof(node));
  int n;
  scanf("%d\n",&n);
  temp->data=n;
if(head==NULL){
  create(head);
}
else{
  temp->link=head;
  head=temp;
}
//insert_end
/
 temp-link=NULL;
 node *t2= ... ;
 t2->head;
while(t2->link!=NULL){
  t2=t2->link;
}
t2->link=temp;


*/
}
int main()
{
  node *head=(node*)malloc(sizeof(node));
  create(head);
  insert(head);
}
