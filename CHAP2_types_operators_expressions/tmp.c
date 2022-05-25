#include <stdio.h>

void showBitsOptimized(int);

void main()
{
	showBitsOptimized(0b000111011101111110001);
	putchar('\n');
}


void showBitsOptimized(int x)
{
	for(; x != 0; x>>=1)
		printf("%i", x & 0x1 ? 1 : 0);
}
