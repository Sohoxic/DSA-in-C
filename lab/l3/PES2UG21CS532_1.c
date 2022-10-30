#include<stdio.h>
#include<stdlib.h>

struct DLLNode {
	int data;
	struct DLLNode* prevLink, *next;
}*temp;


struct DLLNode* makeDLLNode(int data)
{

	struct DLLNode* newDLLNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));


	newDLLNode->data = data;
	newDLLNode->prevLink = newDLLNode->next = NULL;
	return newDLLNode;
}


void sort(struct DLLNode** headMimic, struct DLLNode* newDLLNode)
{
	struct DLLNode* current;

	if (*headMimic == NULL)
		*headMimic = newDLLNode;


	else if ((*headMimic)->data >= newDLLNode->data) {
		newDLLNode->next = *headMimic;
		newDLLNode->next->prevLink = newDLLNode;
		*headMimic = newDLLNode;
	}

	else {
		current = *headMimic;


		while (current->next != NULL &&
			current->next->data < newDLLNode->data)
			current = current->next;
		newDLLNode->next = current->next;

		if (current->next != NULL)
			newDLLNode->next->prevLink = newDLLNode;

		current->next = newDLLNode;
		newDLLNode->prevLink = current;
	}
}


void printList(struct DLLNode* head)
{
	while (head != NULL) {
		printf ("%d\n",head->data);
		head = head->next;
	}
}

void search(struct DLLNode *head,int searchData){
  if(head==NULL){
    return ;
   }
  else{
    temp=head;
    int count=0;
    while(temp!=NULL && temp->data < searchData){
      temp=temp->next;
      count++;
    }
    if(temp!=NULL){
      printf("Element found at index %d\n",count );
    }
    else{
      printf("Element not found");
    }
  }
}

int main()
{
	struct DLLNode* head = NULL;
	struct DLLNode* newNode;
    int data,c=1,d=1;
    while (c==1)
    {

        printf("\nEnter data:");
        scanf("%d", &data);
        newNode=makeDLLNode(data);
        sort(&head, newNode);
        printf("\nPress 1 to insert:");
        scanf("%d", &c);
    }
    while(d==1){
      int searchData;

      printf("if you want to search Element enter 1 , else press 0\n");
      scanf("%d",&d );
      if(d==0){
        break;
      }
      else{
      printf("enter element you want to search for");
      scanf("%d",&searchData );
      search(head,searchData);
    }
  }


	printf("Created Doubly Linked List\n");
	printList(head);
	return 0;
}
