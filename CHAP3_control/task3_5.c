#include <stdio.h>
#include <stdlib.h>

void itob(int , char [], int);

int main(int argc, char *argv[])
{

	char str[100];


	itob(atoi(argv[1]), str, atoi(argv[2]));

	printf("%s\n", str);
	return 0;
}

void itob(int n, char s[], int b)
{

	int arr[32] = {0};
	int i       =  0 ;

	while( n > 0)
	{
		arr[i++] = n % b;
		n /= b;
	}

	int numLen = i;
	int j;
	for(j = 0; j <= numLen;)
	{
		switch(arr[i])
		{
			case 10:
				s[j] = 'A';
				break;
			case 11:
				s[j] = 'B';
				break;
			case 12:
				s[j] = 'C';
				break;
			case 13:
				s[j] = 'D';
				break;
			case 14:
				s[j] = 'E';
				break;
			case 15:
				s[j] = 'F';
				break;
			default:
				s[j] = arr[i] + '0';
		}

		j++;
		i--;

	}
	s[j] = '\0';
}
