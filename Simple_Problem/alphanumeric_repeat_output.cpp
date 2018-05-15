
#include "stdafx.h"
#include <stdio.h>
#include <regex>

const int MIN = 1, TEST_MAX = 1000, REPEAT_MAX = 8, BUFFER_SIZE = 22;
using namespace std;

int main()
{
	int T, R;
	char buffer[BUFFER_SIZE];		// To stroe 20 characters + '\n' and '\0' (two bytes need more)
	regex pattern("[0-9a-zA-Z$%*+-./:]+\n");

	scanf("%d", &T);
	if (!(MIN <= T && T <= TEST_MAX))	// test case range check
		return 0;
	
	for (int i = 1; i <= T; i++)
	{
		scanf("%d ", &R);
		if (!(MIN <= R && R <= REPEAT_MAX))		// repeat range check
			return 0;
		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)		// input string size check
			return 0;
		if (regex_match(buffer, pattern) == false)  // alphanumeric check
			return 0;

		int counter = 0;
		while (buffer[counter] != '\n') {
			for (int k = 1; k <= R; k++)
				printf("%c", buffer[counter]);
			counter++;
		}
		printf("\n");
	}
	return 0;
}


