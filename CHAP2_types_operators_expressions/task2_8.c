#include <stdio.h>

void showBits(int x)
{
	for(char i = sizeof(int) * 8 - 1; i >=0; --i)
		printf("%i", (x >> i) & 0x01 ? 1 : 0);
	putchar('\n');
}


void rightRot(int x, int n);
int rightRotPro(int x, int n);

int main(void)
{
	int x;
	showBits(9);
	rightRot(9, 5);
	printf("Pro:\t\t");
	x = (rightRotPro(9,5));
	showBits(x);
	return 0;
}

void rightRot(int x, int n)
{
	int firstDig;
	int mask;
	int clearMask =  ~(0x1 << sizeof(int) * 8 -1);
	printf("ClearMask\t");
	showBits(clearMask);

	for(char i = 0; i < n; ++i)
	{
		firstDig  = x & 0x1;
		printf("FirstDig:\t");
		showBits(firstDig);

		mask = firstDig << sizeof(int) * 8 - 1;
		printf("Mask:\t\t");
		showBits(mask);

		x >>= 1;
		printf("X>>1:\t\t");
		x = x & clearMask;
		showBits(x);

		x = x & clearMask;
		x = x | mask;
		printf("X | mask\t");
		showBits(x);
	}
}

int rightRotPro(int x, int n)
{
	int mask;
	for(char i = 0; i < n; ++i)
	{
		mask = (x & 0x1) << sizeof(int) * 8 - 1;
		x >>= 1;
		x = (x & (~(0x1 << sizeof(int) * 8 -1))) | mask;
	}
	return x;
}
