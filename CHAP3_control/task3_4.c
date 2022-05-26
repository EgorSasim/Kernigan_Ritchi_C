#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

void itoa(int, char[]);
void reverse(char []);

int main(void)
{
	char s[100] = "";
	int n = INT_MIN;
	printf("%i\n", n);
	itoa(n, s);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[])
{
	int i = 0;
	int sign;


	if( (sign = n) < 0)
	{
		if(n == INT_MIN)
			n+=1;
		n = -n;
	}

	do
	{
		s[i++] = (n % 10) + '0';
	}while( (n = n / 10) > 0);

	if (sign < 0)
	{
		if(sign == INT_MIN)
			s[0] += 1;
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char str[])
{
	char c;
	int  i, j;
	for(i = 0, j = strlen(str) - 1; i < j; ++i, --j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

}
