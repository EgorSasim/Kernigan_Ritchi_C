#include <stdio.h>
#include <string.h>

int strindex(char[], char[]);

int main(void)
{

	int index = strindex("Hello, wo wo wo mmmm), world!!!", "wo");
	printf("%i\n", index);

	return 0;
}

int strindex(char s[], char t[])
{

	int i, j, k;

	for(i = strlen(s) - 1; i >= 0; --i)
	{
		for(j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; --j, --k)
			if(k == 0) return i - strlen(t);
	}
	return -1;
}
