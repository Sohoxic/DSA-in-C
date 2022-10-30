#include<stdio.h>
/*
int main()
{
  int num,res;
  scanf("%d",&num );
  num>0 ? (res=1) : (res=-1);
  printf("%d",res);
  return 0;
}
*/
/*
int main(){
  int a=-10;
  printf("%d\n",!a ); // jekono number except for 0 jodi hy then otar not 0 hobe ,  jodi number is 0 then output is 1.
  int b=100;
  printf("%d\n",~b); // negation(~) is used for 2's compliment
  return 0;
}
*/

/*
struct __attribute__((packed)) test {            // __attribute__((packed)) use korle padding remove hye jay.
  char  t1;
  int t2;
};

int main(){
  struct test t;
  printf("%ld\n",sizeof(t));
  return 0;
}
*/
int fib(int n)
{
  if (n==0) || (n==1)
    return n;
  else
    return fib(n-1)+fib(n-2);
}
int main(){
  printf("%d",fib(5));
}
