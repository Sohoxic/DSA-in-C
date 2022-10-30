#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
	int top;
	int capacity;
	int* array;
};
struct Stack* createStack(int capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));
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
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z');
}
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

int infixToPostfix(char* exp)
{
	int i, k; //we can initialise k=-1 in this line also , instead of initialising it inside the for loop.
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
			while (!isEmpty(stack)
				&& Prec(exp[i]) < Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
            }
	}
	while (!isEmpty(stack))
		exp[++k] = pop(stack);
	exp[++k] = '\0';
	printf("%s", exp);
}
int main()
{
	char exp[] = "2+3*5+6";
	infixToPostfix(exp);
	return 0;
}
