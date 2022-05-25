#include <stdio.h>

int showBits(int x)
{
	for(char i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		printf("%i", ((x >> i) & 0x1) ? 1 : 0);
	}
	putchar('\n');

}

int setBits(int x, int p, int n, int y);
int setBitsPro(int x, int p, int n, int y);

int main()
{
	showBits(90);
	setBits(27052, 3, 4, 90);
	int res = setBitsPro(27052, 3, 4, 90);
	showBits(res);
	return 0;
}

int setBits(int x, int p, int n, int y)
{
	showBits(3);
	int rightYPart = y & ((0x1 << n) - 1);
	showBits(rightYPart);

	int insertPart = rightYPart << p;
	showBits(insertPart);

	int bitMask = ~(((0x1 << n) - 1) << p);
	showBits(bitMask);

	x = x & bitMask;
	showBits(x);

	x = x | insertPart;
	showBits(x);
}

int setBitsPro(int x, int p, int n, int y)
{

	return x & ( ~(((0x1 << n) - 1) << p) ) | (( y & ((0x1 << n) - 1)) << p);

}
