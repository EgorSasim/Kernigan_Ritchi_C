#include <stdio.h>
#include <stdlib.h>

#define START  0
#define FINISH 300
#define STEP   20

void fahrToCel(int start, int finish, int step);
void celToFahr(int start, int finish, int step);

int main(void)
{
	int start, finish, step;
	int mode = 0;


	do
	{
		printf("Write \"start\" \"finish\" \"step\"\n");
		scanf("%d %d %d", &start, &finish, &step);
		printf("Write \"0\" to convert fahr to celsius, \"1\" to convert celsius to fahr, -1  to exit\n");
		scanf("%d", &mode);


		if(mode == 1)
			celToFahr(start, finish, step);
		else if(!mode)
			fahrToCel(start, finish, step);
		else
			printf("Thanks for choosing our program)\n HAVE A GOOD DAY!!!\n");

	}while(mode != -1);

	return 0;
}

void fahrToCel(int start, int finish, int step)
{

	if(start > finish)
	{
		for(; finish <= start; start -= step)
			printf("%3d %4.2f\n", start, (5.0/9.0)*(start - 32.0));
		return;
	}
	printf("FAHR TO CELL TABLE\n");
	for(; start <= finish; start+=step)
		printf("%3d %4.2f\n", start, (5.0/9.0)*(start - 32.0));
}

void celToFahr(int start, int finish, int step)
{

	printf("CEL TO FAHR TABLE\n");
	for(; start <= finish; start += step)
		printf("%3d %4.2f\n", start, ( 5.0/9.0* start ) + 32 );
}
