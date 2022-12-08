#include <iostream>

int getLastOccurance(char c, char s[])
{

	char x = -1;

	for (int i = 0; i < strlen(s); i++)
	{
		
		if (s[i] == c)
		{
			x = i;
		}

	}

	return x;

}

int getOccurance(char c, char s[], int occurance)
{

	int o = 0;
	int i = 0;

	while(s[i] != 0)
	{
		if (s[i] == c)
		{

			o++;

			if (o == occurance)
			{
				return i;
			}

		}

		i++;
	}

	return -1;

}

int countChar(char c, char s[])
{

	int x = 0;

	int i = 0;

	while(s[i] != 0)
	{

		if (s[i] == c) x++;

		i++;

	}

	return x;

}

int checkParanthesis(char s[])
{

	int open = 0;
	int closed = 0;

	int i = 0;

	while(s[i] != 0)
	{
		if (s[i] == 0) break;
		if (s[i] == 123) open++;
		if (s[i] == 125) closed++;

		i++;

	}

	return open == closed;

}

//nu are un tip de paranteza
int missingParanthesis(char s[])
{

	if (countChar('{', s) == 0)
	{
		return getOccurance('}', s, 1);
	}

	if (countChar('}', s) == 0)
	{
		return getOccurance('{', s, 1);
	}

	return -1;

}

//incepe cu }
int startsWrong(char s[])
{
	if (getOccurance('}', s, 1) < getOccurance('{', s, 1)) return getOccurance('}', s, 1);
	return -1;
}

int unclosedBracket(char s[])
{

	int open = countChar('{', s);
	int closed = countChar('}', s);

	if (open > closed)
	{
		return getOccurance('{', s, open - closed);
	}
	else
	{
		return getLastOccurance('}', s);
	}

}

int check(char s[])
{

	if (!checkParanthesis(s)) return 0;
	if (missingParanthesis(s) == -1 && startsWrong(s) == -1 && unclosedBracket(s) == -1) return 1;

	return 0;

}

int getErrorLine(char s[])
{

	int missing = missingParanthesis(s);
	int sw = startsWrong(s);
	int unclosed = unclosedBracket(s);

	if (missing != -1)
	{
		printf("%s\n", "Bracket missing!");
		return missing;
	}
	else if (sw != -1)
	{
		printf("%s\n", "Starts wrong!");
		return sw;
	}
	else if (unclosed != -1)
	{
		printf("%s\n", "Unclosed brackets!");
		return unclosed;
	}

	return -1;

}

int main()
{

	char s[1000];

	int error = 0;

	//fgets(s, sizeof(s), stdin);
	scanf_s("%[^\n]%*c", s, 1000);

	//printf("Ai introdus un sir de marime: %d", length);

	if (!check(s))
	{

		error = getErrorLine(s);

		printf("Incorect! %d\n", error);
		printf("Error: %c\n", s[error]);

		s[error] = '_';

		puts(s);

	}
	else
	{
		printf("Corect");
	}

	return 0;

}
