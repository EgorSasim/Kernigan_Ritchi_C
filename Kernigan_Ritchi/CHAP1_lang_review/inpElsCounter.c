#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_AGAIN     1
#define NOT_SPACE_AGAIN 0


#define IN_WORD  1
#define OUT_WORD 0


#define MAXLINE 1000

#define SPACE_OR_TAB_AGAIN     1
#define NOT_SPACE_OR_TAB_AGAIN 0

#define DETAB   2
#define TAB_SIZE 4


int charCnt(void);
void spaceTabsNLineCounter(int[3]);
void rmRepSpaces(void);
void symbRepresent(void);
int wordsCounter(void);
void newWordPerStr(void);
void gistWordLen(void);
void symbFrequency(void);

int getLine(char[], int);
void copy(char[], char[]);

void printLimStr(int lim);

void rmRepTabsSpaces(char *);

void revStr(char *);

void detab(char *);
void entab(char *);

void borderStr(char *, int);
void rmComments(char *str);

enum
{
	 NLINE = 0
	,TAB
	,SPACE
};


int main(void)
{

	char str[MAXLINE];
	char longestStr[MAXLINE];
	int  strLen;
	int  longestStrLen = 0;



	rmComments("//strange string with comments\nint i = 0;\nchar c = 0;\nprintf(c);\n//one more comment line\nand some code again...\n");
	/*while( ( strLen = getLine(str, MAXLINE)) > 0)
	{
		borderStr(str, 5);
	}

	if(longestStrLen >  0)
	{
		printf("\nThe longest line is: %s\nWith the length: %d\n", longestStr, longestStrLen);
	}
	else
		printf("No input\n");
	*/

	//char str[] = "  Hello  world   how are you     today	  		darling";

	return 0;
}


int charCnt(void)
{
	int cnt = 0;

	while( getchar() != EOF )
		cnt++;

	return cnt;
}


void spaceTabsNLineCounter(int arr[3])
{
	char c;
	int i_space, i_tab, i_nline;
	i_space = i_tab = i_nline = 0;

	while( (c = getchar()) != EOF)
	{
		switch(c)
		{
			case '\n':
				i_nline++;
				break;
			case '\t':
				i_tab++;
				break;
			case ' ':
				i_space++;
				break;
			default:
				break;
		}
	}
	arr[NLINE] = i_nline;
	arr[TAB] = i_tab;
	arr[SPACE] = i_space;
}


void rmRepSpaces(void)
{
	char c;
	char spaceFlag = NOT_SPACE_AGAIN;

	while( (c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(spaceFlag == SPACE_AGAIN)
				continue;
			spaceFlag = SPACE_AGAIN;
			putchar(c);
		}
		else
		{
			putchar(c);
			spaceFlag = NOT_SPACE_AGAIN;
		}
	}
}


void symbRepresent(void)
{
	char c;

	while( (c = getchar()) != EOF)
		switch(c)
		{
			case '\t':
				putchar('\\');
				putchar('t');
				break;
			case '\b':
				putchar('\\');
				putchar('b');
				break;
			case '\\':
				putchar('\\');
				putchar('\\');
				break;
			default:
				putchar(c);
				break;
		}

}

int wordsCounter(void)
{
	char c;
	char wrdFlag = OUT_WORD;
	int wrdCnt = 0;
	while( (c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
			wrdFlag = OUT_WORD;
		else if(wrdFlag == OUT_WORD)
		{
			wrdFlag = IN_WORD;
			wrdCnt++;
		}
	}
	return wrdCnt;
}


void newWordPerStr(void)
{
	char c;
	char wrdFlag = OUT_WORD;

	while ( ( c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			wrdFlag = OUT_WORD;
			putchar('\n');
		}
		else if (wrdFlag == OUT_WORD)
			wrdFlag = IN_WORD;

		if(c != '\n' && c != ' ') putchar(c);
	}
}


void gistWordLen(void)
{
	char c;
	int wrdLen = 0;
	char wrdFlag = OUT_WORD;

	while( ( c = getchar()) != EOF)
	{
		if(wrdFlag == IN_WORD)
			wrdLen++;
		if(c == ' ' || c == '\t' || c == '\n')
		{
			if(wrdLen != 0)
			{
				for(char i = 0; i < wrdLen; ++i)
					putchar('-');
				putchar('\n');
				wrdLen = 0;
			}
			wrdFlag = OUT_WORD;
		}
		else if (wrdFlag == OUT_WORD)
		{
			wrdFlag = IN_WORD;
		}
	}
}





void symbFrequency(void)
{

	char charFreqStore[128];
	char c;


	for(int i = 0; i < 128; i++)
	{
		charFreqStore[i] = 0;
	}

	while( (c = getchar()) != EOF)
	{
		charFreqStore[c]++;
	}

	for(int i = 0; i < 128; i++)
	{
		printf("%c: %i\n", i, charFreqStore[i]);
	}
}


int getLine(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}


void copy(char from[], char to[])
{
	int i = 0;
	while( (to[i] = from[i]) != '\0')
		++i;
}


void printLimStr(int lim)
{
	int line;
	char str[MAXLINE];

	while( ( line = getLine(str, MAXLINE) ) > 0)
	{
		if(line > lim)
			printf("The string with len more then %d:\n%s", lim, str);
	}
}


void rmRepTabsSpaces(char *str)
{
	int i = 0;
	int j, tmp;
	char status = NOT_SPACE_OR_TAB_AGAIN;

	while(str[i] != '\0')
	{
		if(str[i] == '\t' || str[i] == ' ')
		{
			if(str[i] == '\t') str[i] = ' ';
			if(status == SPACE_OR_TAB_AGAIN)
			{
				for(j = i; str[j] != '\0'; j++)
				{
					str[j] = str[j+1];
				}
			}
			else
			{
				++i;
				status = SPACE_OR_TAB_AGAIN;
			}
		}
		else
		{
			status = NOT_SPACE_OR_TAB_AGAIN;
			++i;
		}

	}

}




void revStr(char *str)
{
	int i, j, tmp;

	for(i = 0, j = strlen(str) - 1; i < j; ++i, --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


void detab(char *str)
{

	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == '\t')
		{
			for(int j = 0; j < DETAB; ++j)
				putchar(' ');
		}
		else
		{
			putchar(str[i]);
		}
	}

}



void entab(char *str)
{

	int spaceCnt = 0;

	char state = OUT_WORD;

	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == ' ')
		{
			state = OUT_WORD;
			spaceCnt++;
		}
		else if(state == OUT_WORD)
		{
			state = IN_WORD;
			for(int j = 0; j < spaceCnt / TAB_SIZE; ++j)
			{
				putchar('\t');
			}
			for(int j = 0; j < spaceCnt % TAB_SIZE; ++j)
			{
				putchar(' ');
			}
			spaceCnt = 0;
		}
		if(state == IN_WORD)
			putchar(str[i]);
	}
}




void borderStr(char *str, int lim)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (i % lim == 0)
			putchar('\n');
		putchar(str[i]);
	}
}


void rmComments(char *str)
{
	char c;
	char commentFlag = 0;

	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(commentFlag == 1)
		{
			if(str[i] == '\n')
				commentFlag = 0;
			continue;
		}

		if(str[i] == '/')
		{
			if(str[i+1] == '/')
			{
				commentFlag = 1;
				continue;
			}
		}
		putchar(str[i]);
	}
}





