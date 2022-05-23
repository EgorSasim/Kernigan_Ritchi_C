#include <stdio.h>

int htol(char *);

int main(int argc, char *argv[])
{
	printf("%d\n", htol(argv[1]));
	return 0;
}

int htol(char *str)
{
	int n = 0;
	if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		for( int i = 2; str[i] != '\0'; ++i)
		{
			if(str[i] >= 'A' && str[i] <= 'F')
				n = n * 16 + (str[i] - 'A' + 10);
			else if(str[i] >= 'a' && str[i] <= 'f')
				n = n * 16 + (str[i] - 'a' + 10);
			else if(str[i] >= '0' && str[i] <= '9')
				n = n * 16 + (str[i] - '0');
			else
			{
				printf("Wrong input\n");
				return -1;
			}
		}

	return n;

}
