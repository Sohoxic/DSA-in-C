#include<stdio.h>
#include<stdlib.h>
//#include"barlst1.h"

#define MAX 3
typedef struct arlst{
 int *a;
 int size;
 int used_size;
}VARLST;

 void init(VARLST *pal);
 void array_alloc(VARLST*);
 int append(VARLST *pal,int ele);
 int delLast(VARLST *pal,int *pe);
 void disp(VARLST* pal);


void init(VARLST *pal)
 {
   pal->used_size=-1;
   pal->size=0;
}
void array_alloc(VARLST *pal)
{ if(pal->size==0)
    {pal->a=(int*)malloc(sizeof(int)*MAX);
    pal->size=MAX;}
  else if(pal->used_size==pal->size-1)
    {
          pal->a=(int*)realloc(pal->a,2*pal->size*sizeof(int));
          pal->size=2*pal->size;
    }
}

int append(VARLST *pal,int ele)
{
   array_alloc(pal);
   if (pal->used_size==(pal->size)-1)
      return 0;
   pal->used_size++;
   pal->a[pal->used_size]=ele;
   return 1;
}
 int delLast(VARLST *pal,int *pe)
{
  if(pal->used_size==-1)
    return 1;
  *pe=pal->a[pal->used_size];
   pal->used_size--;
   return 0;
}


 void disp(VARLST* pal){
  for(int i=0;i<=pal->used_size;i++)
   printf("%d ",pal->a[i]);
}






int main()
{
 VARLST myLst;
 int choice,ele,res;
 init(&myLst);
 printf("Welcome");
 do{
   printf("\n1.append 2 DelLast 3 display \n");
   printf("choose the option");
   scanf("%d",&choice);
   switch(choice)
    {
      case 1: printf("enter element");
              scanf("%d",&ele);
              res=append(&myLst,ele);
              if(res)
               printf("Successful");
              else
               printf("Unsuccessful");
             break;
      case 2: res=delLast(&myLst,&ele);
             if(res)
                printf("Not possible");
             else
               printf("%d del ele",ele);
             break;
      case 3: disp(&myLst);
             break;
   }
 }while(choice<4);
}
