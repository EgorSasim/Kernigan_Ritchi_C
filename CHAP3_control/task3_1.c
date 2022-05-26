#include <stdio.h>

int binSearch(int val, int arr[], int aSize);

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	printf("BinSrch1: %i\n", binSearch(5, arr, 10));
	printf("BinSrch2: %i\n", binSearch(234, arr, 10));
	return 0;
}


int binSearch(int val, int arr[], int aSize)
{
	int low, high, mid;

	low = 0;
	high = aSize - 1;

	do
	{
		mid = (low + high) >> 1;
		if (arr[mid] < val)
			low = mid + 1;
		else high = mid - 1;

	} while(low < high && arr[mid] != val);

	if (arr[low] == val) return low;
	else if (arr[mid] == val) return mid;
	else	return -1;
}

