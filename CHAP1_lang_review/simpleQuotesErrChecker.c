#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct brackets
{
	int circleBrackets;
	int squareBrackets;
	int curlyBrackets;
}sBrackets;

typedef struct quotes
{
	int singleQuotes;
	int doubleQuotes;
}sQuotes;

typedef struct elems
{
	sBrackets brackets;
	sQuotes   quotes;
}sElems;


enum err_type
{
	 CIRCLE_BRACKETS_ERR  = 0
	,SQUARE_BRACKETS_ERR
	,CURLY_BRACKETS_ERR
	,SINGLE_QUOTES_ERR
	,DOUBLE_QUOTES_ERR

	,ERR_TYPE_END
};


void imbalanceCheck(char *str);
void clearEls(sElems *);
char checkEls(sElems *);
void addEls(sElems *, char sign);


int main(int argc, char *argv[])
{

	imbalanceCheck(argv[1]);
	return 0;
}

void clearEls(sElems *els)
{
	els->brackets.circleBrackets = 0;
	els->brackets.squareBrackets = 0;
	els->brackets.curlyBrackets  = 0;

	els->quotes.singleQuotes     = 0;
	els->quotes.doubleQuotes     = 0;
}

void addEls(sElems *els, char sign)
{
	static char singleQuotesFlag = 0;
	static char doubleQuotesFlag = 0;

	switch(sign)
	{
		case '(':
			els->brackets.circleBrackets++;
			break;
		case ')':
			els->brackets.circleBrackets--;
			break;
		case '[':
			els->brackets.squareBrackets++;
			break;
		case ']':
			els->brackets.squareBrackets--;
			break;
		case '{':
			els->brackets.curlyBrackets++;
			break;
		case '}':
			els->brackets.curlyBrackets--;
			break;
		case '\"':
			if(doubleQuotesFlag == 0)
			{
				els->quotes.doubleQuotes++;
			}
			else
			{
				els->quotes.doubleQuotes--;
			}

			doubleQuotesFlag = (doubleQuotesFlag + 1) % 2;
			break;
		case '\'':
			if(singleQuotesFlag == 0)
			{
				els->quotes.singleQuotes++;
			}
			else
			{
				els->quotes.singleQuotes--;
			}

			singleQuotesFlag = (singleQuotesFlag + 1) % 2;
			break;
		default:
			return;
	}

}

char checkEls(sElems *els)
{
	if( els->brackets.circleBrackets != 0)
		return CIRCLE_BRACKETS_ERR;
	if(els->brackets.squareBrackets  != 0)
		return SQUARE_BRACKETS_ERR;
	if(els->brackets.curlyBrackets   != 0)
		return CURLY_BRACKETS_ERR;
	if(els->quotes.singleQuotes      != 0)
		return SINGLE_QUOTES_ERR;
	if(els->quotes.doubleQuotes      != 0)
		return DOUBLE_QUOTES_ERR;

	return ERR_TYPE_END;
}


void imbalanceCheck(char *str)
{

	if(!str)
	{
		printf("Empty string?\nReally?\nAre U kidding me?)\n");
		return;
	}
	int linesCnt;
	sElems elems;

	clearEls(&elems);



	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == '{')
			addEls(&elems, '{');
		if(str[i] == '}')
			addEls(&elems, '}');
		if(str[i] == '[')
			addEls(&elems, '[');
		if(str[i] == ']')
			addEls(&elems, ']');
		if(str[i] == '(')
			addEls(&elems, '(');
		if(str[i] == ')')
			addEls(&elems, ')');
		if(str[i] == '\"')
			addEls(&elems, '\"');
		if(str[i] == '\'')
			addEls(&elems, '\'');
	}

	switch(checkEls(&elems))
	{
		case(CIRCLE_BRACKETS_ERR):
			printf("Err with circle brackets\n");
			break;
		case(SQUARE_BRACKETS_ERR):
			printf("Err with square brackets\n");
			break;
		case(CURLY_BRACKETS_ERR):
			printf("Err with curly brackets\n");
			break;
		case(SINGLE_QUOTES_ERR):
			printf("Err with single quotes\n");
			break;
		case(DOUBLE_QUOTES_ERR):
			printf("Err with double quotes\n");
			break;
		default:
			printf("Everything seems good,  but just in case check it by yourself again)\n");
			break;

	}

}
