#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 50
typedef struct stk{
  char st[max];
  int top;
}stk;
void push(stk *ptr, char data) {
  ptr->top++;
  ptr->st[ptr->top]=data;
}
char pop(stk *ptr) {
  return ptr->st[ptr->top--];
}
int compare(char data){
  switch(data) {
    case '+':return 1;
    case '-':return 1;
    case '*':
    case '/':
    case '%': return 2;
    case '$':
    case '^': return 3;
    default: return 0;
  }
}
char Rev(char st[]) {
  for(int i=0; i<strlen(st); i++) {
    if(st[i]=='(') st[i]=')';
    else if(st[i]==')') st[i]='(';

  }
  int len=0,i,j;
  char tp;
  len=strlen(st);
  for(i=len-1,j=0;j<(len/2); i--,j++){
        tp=st[j];
        st[j]=st[i];
        st[i]=tp;
    }
  //strrev(st);
}
int compute(char ch, int op1, int op2) {
  switch(ch) {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    case '$':
    case '^':return pow(op1,op2);
    case '%':return op1%op2;
  }
}
int eval(char Pref[]) {

  int i,s[100],top=-1;
  int res,op1,op2; char ch;
  for(i=strlen(Pref)-1; i>=0; i--) {
    ch=Pref[i];
    if(isdigit(ch)) s[++top]=ch-'0';
    else {
      op1=s[top--];
      op2=s[top--];
      res=compute(ch,op1,op2);
      s[++top]=res;
    }
  }
  res=s[top--];
  return res;
}
int main() {
  char Inf[max],Pref[max];
  int l;
  stk *ptr,s;
  ptr=&s;
  s.top=-1;
  scanf("%d%s",&l,Inf);
  Rev(Inf);
  push(ptr,'(');
  strcat(Inf,")");
  int i=0, k=0; char x;
  while(Inf[i]!='\0'){
    if(Inf[i]=='(') push(ptr,Inf[i]);
    else if(isalnum(Inf[i])) Pref[k++]=Inf[i];
    else if(Inf[i]==')'){
      while(s.st[s.top]!='(') Pref[k++]=pop(ptr);
      x=pop(ptr);
    }
    else{
    while((compare(s.st[s.top])>compare(Inf[i]))) {
      Pref[k++]=pop(ptr);
    }
    push(ptr,Inf[i]);
  }i++;
  }
  Pref[k]='\0';
  Rev(Pref);
  printf("%s %d",Pref,eval(Pref));
  return 0;
}
