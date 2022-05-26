#include <stdio.h>
#include <string.h>

void expand(char[], char[]);


int main(void)
{
	char from[] = "-a-z0-73-5-";
	char to[100];

	expand(from, to);
	printf("%s\n", to);
	return 0;
}

void expand(char from[], char to[])
{
	char c;
	int i;
	for(i = 0; from[i] != '\0'; i++)
	{
		if(from[i] == '-')
		{
			if (i != 0 && i != strlen(from) - 1)
			{
				c = from[i - 1];
				while(c <= from[i+1])
					putchar(c++);
				putchar(' ');
			}
		}
	}

	to[i] = '\0';
}
