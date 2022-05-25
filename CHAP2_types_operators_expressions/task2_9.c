#include <stdio.h>

int bitcount(int);
void showBits(int x)
{
	for(char i = sizeof(int) * 8 - 1; i >=0; --i)
		printf("%i", ((x >> i) & 0x1) ? 1 : 0);
	putchar('\n');
}

int main(void)
{
	int x = 47205; // 1011 1000 0110 0101
	int y = 1;
	printf("Amount of numbers 1 in bitwise representation of %i: %i\n", x, bitcount(x));
	return 0;
}

int bitcount(int x)
{
	int b;
	for(b = 0; x!= 0; x &= (x - 1))
		++b;
	return b;
}
