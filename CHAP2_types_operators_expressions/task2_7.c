#include <stdio.h>


void showBits(int x)
{

	for(char i = sizeof(int) * 8 - 1; i >= 0; --i)
		printf("%i", ((x >> i) & 0x1) ? 1 : 0);
	putchar('\n');
}


void invert(int x, int p, int n);
int  invertPro(int x, int p, int n);

int main(void)
{
	invert(0b101001011001, 3, 4);

	printf("Pro:\t\t");
	showBits(invertPro(0b101001011001, 3, 4));
	return 0;
}


void invert(int x, int p, int n)
{
	printf("x:\t\t");
	showBits(x);

	int mask =  ((0x1 << n) - 1) << p;
	printf("mask:\t\t");
	showBits(mask);

	x = x ^ mask;
	printf("X xor MASK:\t");
	showBits(x);
}

int  invertPro(int x, int p, int n)
{
	return x ^ (((0x1 << n) - 1) << p);
}
