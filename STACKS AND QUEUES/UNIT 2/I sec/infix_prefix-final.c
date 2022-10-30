// C program to convert infix expression to prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack {
	int top;
	int capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack(int capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));
//if malloc is successful
	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return (stack->top == -1);
}

char peek(struct Stack* stack)
{
	return (stack->array[stack->top]);
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '@';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

// A utility function to check if
// the given character is operand
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z');
}

// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

// The main function that
// converts given infix expression
// to postfix expression.
char* infixToPostfix(char* exp)
{
	int i, k;
	struct Stack* stack = createStack(strlen(exp));
	for (i = 0, k = -1; exp[i]; ++i) {
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);
		else if (exp[i] == ')')
            {
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);//pop out all operators till (
            if(!isEmpty(stack))
                pop(stack);//pop out the (
            }
		else // an operator is encountered
            {
			if(exp[i]=='^')
            {
                while (!isEmpty(stack)
				&& Prec(exp[i]) <= Prec(peek(stack)))//<= RIGHT TO LEFT
				exp[++k] = pop(stack);
            }
            else
            {
                while (!isEmpty(stack)
				&& Prec(exp[i]) < Prec(peek(stack)))//< LEFT TO RIGHT
				exp[++k] = pop(stack);
            }

			push(stack, exp[i]);
            }
	}
	while (!isEmpty(stack))
		exp[++k] = pop(stack);
	exp[++k] = '\0';
	return exp;
	//printf("%s", exp);
}

// for reverse of the given expression
char* reverse(char array[30])
{
	int i,j=0;
	char temp[100];
	for(i=strlen(array)-1;i!=-1;--i,++j) {
            if(array[i]=='(')
                temp[j]=')';
            else if(array[i]==')')
                temp[j]='(';
            else
                temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return array;
}
int main()
{
	char exp[] = "2+3*5+6";
	printf("Infix Expression:%s",exp);
    printf("\nAfter reverese:%s",reverse(exp));
   // printf("\nPrefix Expression:%s",infixToPostfix(exp));
	printf("\nPrefix Expression:%s",reverse(infixToPostfix(exp)));
	return 0;
}
