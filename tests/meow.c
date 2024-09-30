//p + (q * r) / (w - (a - b) / e)
//stack using array a. infix to post fix algorithm

/*
* p = 2
* q = 8
* r = 2
* w = 9
* a = 5
* b = 2
* e = 3
*/

/*
*  A * B + ( B / C ^ ( D - E ) )
*  	A * B + ( B / C ^ DE- )
*  		A * B + ( B / CDE-^ )
*  			A * B + BCDE-^/
*  				AB* + BCDE-^/
*  					AB*BCDE-^/+
* 
* A 1
* B 2
* C 3
* D 4
* E 5
*  15*2345-^/+
*/


/*
*stack postfix
*ab*bcde-^/+
*repeat until length
*	if meet operand
*		stack.push()
*	if meet operator
*		result = stack[n-1] operator stack[n-2]
*		stack.pop()
*		stack.pop()
*		stack.push(result)
*/


#include<stdio.h>
int top = -1;
char stack[30], result_stack[30];

void push(int value)
{
	stack[top] = (int) value;
	printf("\npushed %d", stack[top]);
	top = top + 1;
}

void pop()
{
	printf("\npopped %d", stack[top]);
	top = top - 1;
}

void eval()
{
	int result;
	for (int i = 0; stack[i] != '\0'; i++)
	{
		printf("\n");
		if (stack[i] == '+')
		{
			result = result_stack[top-1] + result_stack[top-2];
			pop();
			pop();
			push(result);
			printf("%d", result);
		}

		else if (stack[i] == '-')
		{
			result = result_stack[top-1] - result_stack[top-2];
			pop();
			pop();
			push(result);
			printf("sub %d", result);
		}

		else if (stack[i] == '*')
		{
			result = result_stack[top-1] * result_stack[top-2];
			pop();
			pop();
			push(result);
			printf("%d", result);
		}

		else if (stack[i] == '/')
		{
			result = result_stack[top-1] / result_stack[top-2];
			pop();
			pop();
			push(result);
			printf("%d", result);
		}

		else if (stack[i] == '^')
		{
			result = result_stack[top-1] ^ result_stack[top-2];
			pop();
			pop();
			push(result);
			printf("%d", result);
		}

		else {
			push(stack[i]);
			printf("%c", stack[i]);
		}
	}
}

int main()
{
	printf("Enter the postfix expression:");
	scanf("%s", stack);
	eval();
	printf("result is %d", result_stack[0]);
	return 0;
}

