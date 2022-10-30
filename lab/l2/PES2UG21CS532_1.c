#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coeff;
    int px;
    int py;
    struct polynomial *link;
} poly;

typedef struct ptr
{
    poly *head;
} head;

poly *createnode(int coefficient, int px, int py)
{
    poly *temp;
    temp = (poly *)malloc(sizeof(poly));

    temp->coeff = coefficient;
    temp->px = px;
    temp->py = py;
    temp->link = NULL;

    return temp;
}
poly *input(poly *ptr, int coefficient, int px, int py)
{

    poly *temp = createnode(coefficient, px, py);

    if (ptr == NULL)
    {
        ptr = temp;
        return ptr;
    }
    poly *p = ptr;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
    return ptr;
}
void display(poly *ptr)
{
    poly *cur = ptr;

    while (cur != NULL)
    {
        printf("%dx^%dy^%d", cur->coeff, cur->px, cur->py);
        cur = cur->link;
     
        printf(" + \n");
    }
}


poly* add(poly *list1,poly *list2){
    
    if(list1==NULL && list2==NULL){
        return NULL;}
    if(list1==NULL){

        list2->link=add(list2->link,NULL);

        return list2;
    }
    if(list2==NULL){

        list1->link=add(list1->link,NULL);
        return list1;
    }
    if(list1->px==list2->px && list1->py==list2->py){

        list1->coeff=list1->coeff+list2->coeff;
        list1->link=add(list1->link,list2->link);
        return list1;
    }
    else if(list1->px>list2->px){
            list1->link=add(list1->link,list2);
            return list1;
    }
    else if(list1->px<list2->px){
        list2->link=add(list1,list2->link);
            return list2;
    }
    else{
        if(list1->py>list2->py){
            list1->link=add(list1->link,list2);
            return list1;
        
        }
        else{
            list2->link=add(list1,list2->link);
            return list2;
        }
    }
}
int main()
{
    poly *polynomial1 = malloc(sizeof(poly));
    ;
    poly *polynomial2 = malloc(sizeof(poly));
    ;
    poly *sum = malloc(sizeof(poly));

    polynomial1 = NULL;
    polynomial2 = NULL;

    int choice, poly1, poly2;
    int coeff, px, py;

    printf(" Input the polynomial 1 \n");

    printf("\nenter the length of the polynomial 1\n");
    scanf("%d", &poly1);

    for (int i = 0; i < poly1; i++)
    {
        printf("enter the coefficient of %d term\n", i + 1);
        scanf("%d", &coeff);
        printf("enter the power of x of the %d term\n", i + 1);
        scanf("%d", &px);
        printf("enter the power of y of the %d term\n", i + 1);
        scanf("%d", &py);
        polynomial1 = input(polynomial1, coeff, px, py);
    }
    printf("\nenter the length of the polynomial 2\n");
    scanf("%d", &poly2);
    printf(" Input the polynomial 2 \n");

    for (int i = 0; i < poly2; i++)
    {
        printf("enter the coefficient of %d term\n", i + 1);
        scanf("%d", &coeff);
        printf("enter the power of x of the %d term\n", i + 1);
        scanf("%d", &px);
        printf("enter the power of y of the %d term\n", i + 1);
        scanf("%d", &py);
        polynomial2 = input(polynomial2, coeff, px, py);
    }
    // display(polynomial1);
    // display(polynomial2);
    sum = add(polynomial1, polynomial2);

    printf("the addition gives\n");
    display(sum);

    return 0;
}
