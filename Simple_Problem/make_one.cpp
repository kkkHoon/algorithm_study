
#include "stdafx.h"
#include <stdio.h>

int toOne(int n);
int counter[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	if (!(1 <= n && 1000000))
		return 0;
	printf("%d\n", toOne(n));
	return 0;
}

int toOne(int n)
{
	if (n <= 1)
		return 0;
	if (counter[n] > 0)  // memoization
		return counter[n];

	int min;
	min = toOne(n - 1) + 1;
	if (n % 2 == 0 && toOne(n / 2) + 1 < min)  
		min = counter[n / 2] + 1;
	if (n % 3 == 0 && toOne(n / 3) + 1 < min)  // Do not use 'else if'. n�� 2�� 3�� ������� ���(ex 6) else if ������ toOne(n/2)�� ����ǰ�, toOne(n/3)�� ����ȵȴ�.
		min = counter[n / 3] + 1;
	counter[n] = min;
	return counter[n];
}