//#include<stdio.h>
/*
int main(){
  int num=-10,num1=0;
  int res;
  (num>0)? (res=1): (res=-1);
  printf("%d\n",res);
  printf("%d\n",res);
  }
  */




//Question 2 Output is welcome
//-345679  two's complement


//Output is [3 45]  [3 98]


//Output is 10
//Factr calculates factorial
//0 1
/*
#include<stdio.h>


int fib(int n){
  if ((n==0) || (n==1))
    return n;

  else return fib(n-1)+fib(n-2);
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    printf("%d",fib(i));
}
*/
#include<stdio.h>
int dec(int n){
  if(n==0){
    printf("%d\n",n);
    return n;
  }
  else {
    printf("%d\n",n);
    return dec(n-1);
}
int main(){
   int n;
   scanf("%d\n",&n);
   dec(n);
 }
