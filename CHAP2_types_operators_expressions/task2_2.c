#include <stdio.h>


#define MAXLINE 1000

void getLine(char *, int);


int main(void)
{
	char str[MAXLINE];
	//getLine(str, MAXLINE);

	printf("%d %d", 'a', 'A');

	printf("Inputed str: %s\n", str);
	return 0;
}

void getLine(char *str, int lim)
{

	int c;
	for(int i = 0; i < lim - 1; ++i)
	{
		if( (c = getchar()) != EOF)
			if(c == '\n')
				break;
			else
				str[i] = c;
	}

}
