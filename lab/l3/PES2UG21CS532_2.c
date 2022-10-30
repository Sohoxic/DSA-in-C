#include <stdio.h>
#include <stdlib.h>

typedef struct structLink
{
	int data;
	struct structLink * next;
	struct structLink * prevLink;
}structLink;
structLink * getstructLink(int data)
{
	structLink * newDll = (structLink * ) malloc(sizeof(structLink));
	if (newDll == NULL)
	{
		return NULL;
	}
	newDll->data = data;
	newDll->next = NULL;
	newDll->prevLink = NULL;
	return newDll;
}
typedef struct DLL
{
	struct structLink * head;
}DLL;

DLL * makeDLL() 
{
	DLL * newDll = (DLL * ) malloc(sizeof(DLL));
	if (newDll == NULL)
	{
		return NULL;
	}
	newDll->head = NULL;
	return newDll;
}
void insert(DLL * newDll, int value)
{
	structLink * node = getstructLink(value);
	if ((newDll->head == NULL))
	{
		newDll->head = node;
		return;
	}
	structLink * temp = newDll->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
	node->prevLink = temp;
}

structLink* getNode(int data)
{

	structLink* newNode =
		(structLink*)malloc(sizeof(structLink));


	newNode->data = data;
	newNode->prevLink = newNode->next = NULL;
	return newNode;
}

void sortedInsert(DLL** mimicHead, int d)
{
    structLink* current;
    structLink* newNode = getNode(d);
	if ((*mimicHead)->head == NULL)
		(*mimicHead)->head = newNode;


	else if ((*mimicHead)->head->data >= newNode->data) {
		newNode->next = (*mimicHead)->head;
		newNode->next->prevLink = newNode;
		(*mimicHead)->head = newNode;
	}

	else {
		current = (*mimicHead)->head;


		while (current->next != NULL &&
			current->next->data < newNode->data)
			current = current->next;
		newNode->next = current->next;

		if (current->next != NULL)
			newNode->next->prevLink = newNode;

		current->next = newNode;
		newNode->prevLink = current;
	}
}

void display(DLL * newDll)
{
	if ((newDll->head == NULL))
	{
		printf("Empty Linked List");
	}
	else
	{
		structLink * temp = newDll->head;
		while (temp != NULL)
		{
			printf(" %d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}
void DLLmergedOrderedList(DLL * newDll, DLL * second)
{
	if ((newDll->head == NULL || second == NULL ||
         second->head == NULL || newDll->head == second->head))
	{
		return;
	}
	else
	{
		structLink * temp1 = newDll->head;
		structLink * temp2 = second->head;
		structLink * back = NULL;
		if ((temp1->data > temp2->data))
		{
			newDll->head = temp2;
		}
		while (temp1 != NULL && temp2 != NULL)
		{
			if ((temp1->data >= temp2->data))
			{
				if ((back != NULL))
				{
					back->next = temp2;
					temp2->prevLink = back;
				}
				back = temp2;
				temp2 = temp2->next;
			}
			else
			{
				if ((back != NULL))
				{
					back->next = temp1;
					temp1->prevLink = back;
				}

				back = temp1;
				temp1 = temp1->next;
			}
		}
		if ((temp1 != NULL))
		{
			back->next = temp1;
			temp1->prevLink = back;
		}
		if ((temp2 != NULL))
		{
			back->next = temp2;
			temp2->prevLink = back;
		}
		second->head = NULL;
	}
}
int main()
{
	DLL * dl1 = makeDLL();
	DLL * dl2 = makeDLL();
	int data,c;
    printf("\nLIST 1-");
    do
    {
        printf("\nEnter data:");
        scanf("%d", &data);
        sortedInsert(&dl1,data);
        printf("\nPress 1 to insert another node, 0 to exit");
        scanf("%d", &c);
    }
    while (c==1);
    printf("\nLIST 2-");
    do
    {
        printf("\nEnter data:");
        scanf("%d", &data);
        sortedInsert(&dl2,data);
        printf("\nPress 1 to insert another node , 0 to exit");
        scanf("%d", &c);
    }
    while (c==1);
    printf("\n-----------------------------------------------------------------------\n");
    printf("DLL1 -\n");
    display(dl1);
    printf("DLL2-\n");
    display(dl2);
    DLLmergedOrderedList(dl1, dl2);
    printf("newDllrged list-\n");
    display(dl1);
}
