#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char[], char[]);


int main(void)
{
	char to[100] = "";
	char from[] = "Hello\nhow\tare\nyou???";

	escape(from, to);

	printf("%s\n", to);
	return 0;
}


void escape(char from[], char to[])
{
	int i, k;
	i = k = 0;

	while(from[i++] != '\0')
	{
		switch (from[i])
		{
			case '\t':
				to[k++] = '\\';
				to[k++] = 't';
				break;
			case '\n':
				to[k++] = '\\';
				to[k++] = 'n';
				break;
			default:
				to[k++] = from[i];
				break;
		}
	}
}
