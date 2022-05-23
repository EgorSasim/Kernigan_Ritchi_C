#include <stdio.h>


#define SIZE(x) sizeof(x) * 8

void signed_one(int);
void unsigned_one(int);


int main()
{

	signed_one(SIZE(int));
	signed_one(SIZE(signed char));
	signed_one(SIZE(float));
	signed_one(SIZE(short));

	unsigned_one(SIZE(unsigned char));
	unsigned_one(SIZE(unsigned short));
	unsigned_one(SIZE(unsigned int));


	return 0;
}



void signed_one(int count)
{
	int min, max, pro;

	pro = 1;

	while(count != 1)
	{
		pro <<= 1;
		--count;
	}

	min = ~pro + 1;
	max =  pro - 1;

	printf("Min value: %i\nMax value: %i\n", min, max);

}

void unsigned_one(int count)
{
	int min, max, pro;

	pro = 1;

	while(count != 0)
	{
		pro <<= 1;
	}

	min = 0;
	max = pro - 1;

	printf("Min value: %i\nMax value: %i\n", min, max);
}
