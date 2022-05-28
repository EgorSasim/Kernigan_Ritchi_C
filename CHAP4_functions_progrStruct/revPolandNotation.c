#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP  100	// input string length
#define NUMBER '0'	// number sign

#define MAXVAL 100	// stack depth

#define BUFSIZE	100	// buffer for ungetch

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;		// next free stack position
double val[MAXVAL];	// stack

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0)
					push(pop() / op2);
				else
					printf("Can not divide by zero!!!\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("ERROR!!!\nInvalid input!!!\n");
				break;
		}
	}
	return 0;
}



void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Stack is full!!!\n");
}


double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
		printf("Stack is empty!!!\n");
	return 0.0;
}


int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (buf > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE )
		printf("Ungetch: too much symbols\n");
	else
		buf[bufp++] = c;
}



















