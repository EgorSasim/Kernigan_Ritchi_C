#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int binSearch(int x, int v[], int n);

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int res = binSearch(5, arr, 10);
	printf("Res %i\n", res);
	return 0;
}


int binSearch(int x, int arr[], int aSize)
{
	int low, high, mid;

	low = 0;
	high = aSize - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if( x < arr[mid])
		{
			high = mid - 1;
		}
		else if (x > arr[mid])
		{
			low = mid + 1;
		}
		else return mid;
	}
	return -1;	//no matches
}
