#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACKSIZE 100

double stack[STACKSIZE] = {0};
int stack_pos = 0;

void push(double);
double pop(void);

int tmp[6] = {0, [1...5] = {0}};

int main(int argc, char *argv[])
{

	if(!argv[1])
	{
		printf("No input str, please try again\n");
		return -1;
	}

	char *inpStr = argv[1];


	for(int i = 0; *(inpStr + i) != '\0'; ++i)
	{
		switch(*(inpStr+ i))
		{


		}

	}


	return 0;
}

void push(double num)
{
	if(stack_pos < STACKSIZE)
	{
		stack[stack_pos++] = num;
	}
	else
		printf("Error: stack if full\n");
}

double pop(void)
{
	if(stack_pos > 0)
	{
		return stack[--stack_pos];
	}
	else
	{
		printf("Error: stack is empty\n");
		return 0.0;
	}
}

bool isNum(char symb)
{
	return true;
}
