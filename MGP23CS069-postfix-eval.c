#include<stdio.h>
int top;
char stack[];
int result_top;

void push()
{
	if (top >= 99)
		printf("Stack overflow");
	else
		stack[++top = ch]
}

int pop()
{
	if (top == 1)
		printf("stack underflow");
	else
		return stack[result_top--]
}

void evaluate()
{
	if (ch == '+')
		return b + a;
	if (ch == '-')
		return b - a;
	if (ch == '*')
		return b * a;
	if (ch == '/')
		return b / a;
	if (ch == '^')
		return b ^ a;
	else
		return 0;
}


int main()
{
	char  result_stack[];
	
}
