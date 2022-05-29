#include <stdio.h>
#include <stdlib.h>

void rec_itoa(int);


int main(int argc, char *argv[])
{

	if(!argv[1])
	{
		printf("invalid params\n");
		return -1;
	}
	rec_itoa(atoi(argv[1]));
	putchar('\n');
	return 0;
}

void rec_itoa(int n)
{
	if(n < 0)
	{
		putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		rec_itoa(n / 10);
	}
	putchar(n % 10 + '0');
}
