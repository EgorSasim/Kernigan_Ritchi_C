#include <stdio.h>

char lower(char);

int main(void)
{

	printf("%c\n", lower('A'));
	printf("%c\n", lower('a'));
	printf("%c\n", lower('~'));
	return 0;
}

char lower(char c)
{
	return ( c >= 'A'  && c <= 'Z') ? c  + 'a' - 'A' : c;
}
