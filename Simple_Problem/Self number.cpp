

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
const int MAX = 10000;

void self_num(vector<bool> *arr, int num);
int get_length(int num);

int main()
{
	vector<bool> array(MAX, true);
	for (int i = 1; i <= MAX; i++)
	{
		self_num(&array, i);
		if (array[i - 1])
			printf("%d\n", i);
	}
	return 0;
}

void self_num(vector<bool> *arr, int num)
{
	int length = get_length(num);
	int sum = num;

	int d;
	for (int i = 1; i <= length; i++)
	{
		d = pow(10, i);
		sum += (num % d) / (pow(10,i - 1));
	}

	if (sum <= MAX && (*arr)[sum -1] == true)
		(*arr)[sum-1] = false;
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

