#include <stdio.h>

void squeeze(char *, char *);

int main(void)
{
	char base[] = "Hello world!!!\n";
	char s2[] = "l;!Ho ";

	squeeze(base, s2);

	printf("Base: %s\n", base);

	return 0;
}

void squeeze(char *base, char *s2)
{
	for(int i = 0; s2[i] != '\0'; ++i)
	{
		int k = 0;
		for(int j = 0; base[j] != '\0'; ++j)
		{
			if(base[j] != s2[i])
				base[k++] = base[j];
		}
		base[k] = '\0';

	}

}
