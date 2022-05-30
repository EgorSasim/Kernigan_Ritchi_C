#include <stdio.h>

#define swap(t,x,y) {t c; c = x; x = y; y = c;}

int main(void)
{
	int a, b;
	a = 1;
	b = 2;
	printf("a: %d\tb: %d\n", a, b);
	swap(int, a, b);
	printf("a: %d\tb: %d\n", a, b);
	return 0;
}
