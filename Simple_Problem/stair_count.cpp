
#include "stdafx.h"
#include <stdio.h>


int max(int a, int b);
int stair(int n, int k);

int A[301];
int D[301][3];

int main()
{
	int N;
	scanf("%d", &N);
	if (!(1 <= N && N <= 300))	// range check
		return 0;

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		if (!(1 <= A[i] && A[i] <= 10000))
			return 0;
	}

	printf("%d\n", max(stair(N, 1), stair(N, 2)));

	return 0;
}

int stair(int n, int k)
{
	if (n <= 1) {	// Init
		D[1][k] = A[1];
		return A[1];
	}
	else if (n == 2 && k == 1) {
		D[n][k] = A[n];
		return A[n];
	}
	if (D[n][k] > 0) return D[n][k]; // Memoization

	if (k == 1)
		D[n][k] = stair(n - 2, 2) + A[n];
	else if (k == 2)
		D[n][k] = max(stair(n - 1, 1), stair(n - 2, 1)) + A[n];

	return D[n][k];
}

int max(int a, int b)
{
	if (a <= b) return b;
	else return a;
}