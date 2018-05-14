

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

using namespace std;
const int MIN = 1, MAX = 1000;

bool checkNum(int length, int integer);
int get_length(int num);

int main()
{
	int N, count = 0;
	scanf("%d", &N);
	if (!(MIN <= N && N <= MAX))
		return 0;

	for (int i = 1; i <= N; i++)
	{
		bool result = checkNum(get_length(i), i);
		if (result) {
			count += 1;
		}
	}
	printf("%d\n", count);
	return 0;
}

bool checkNum(int length, int integer)
{
	if (length <= 2)
		return true;
	else
	{
		int digit = integer % 10;
		int difference;
		for (int i = 2; i <= length; i++)
		{
			int d = pow(10, i);
			int next_digit = (integer % d) / pow(10, i - 1);

			if (i == 2) {
				difference = next_digit - digit;
				digit = next_digit;
			}
			else if (difference == next_digit - digit)
				digit = next_digit;
			else
				return false;
		}
		return true;
	}
}

int get_length(int num)
{
	int i = 1;
	while (true)
	{
		int divid = (num / pow(10, i));
		if (divid == 0)
			return i;
		else
			i += 1;
	}
}


