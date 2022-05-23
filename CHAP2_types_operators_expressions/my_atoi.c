#include <stdio.h>


int my_atoi(char *);

int main(void)
{

	printf("%d\n", my_atoi("1289235"));
	return 0;
}


int my_atoi(char *str)
{
	int n = 0;
	for(int i = 0; str[i] != '\0'; ++i)
		n = 10 * n + (str[i] - '0');

	return n;

}
