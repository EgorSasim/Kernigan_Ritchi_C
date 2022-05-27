#include <stdio.h>
#include <string.h>

void expand(char[], char[]);


int main(int argc, char *argv[])
{
	char to[100];

	expand(argv[1], to);
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
