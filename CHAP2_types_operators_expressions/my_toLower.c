#include <stdio.h>

char my_toLower(char);
void my_toLowerStr(char *);

int main(void)
{
	char str[] = "Hello, GEORGE!!!.\nHow Are YOU!!!??? 23423\nBye\n";
	my_toLowerStr(str);
	printf("New str: %s", str);
	return 0;
}

char my_toLower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

void my_toLowerStr(char *str)
{
	for (int i = 0; str[i] != '\0'; ++i)
		str[i] = my_toLower(str[i]);
}
