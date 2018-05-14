

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int MIN = 1, MAX = 10;
bool rangeCheck(int num);
bool repeat_circle(int num, int start_row, int start_column, int end_row, int end_column);
void print_arr(int N);

int **arr;

int main()
{
	int T, N;

	scanf("%d", &T);
	if (T <= 0)
		return 0;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		if (!rangeCheck(N))
			return 0;

		arr = (int **)malloc(sizeof(int *) * N);
		for (int i = 0; i < N; i++)
			arr[i] = (int *)malloc(sizeof(int) * N);

		printf("\#%d\n", test_case);
		repeat_circle(1, 0, 0, N - 1, N - 1);
		print_arr(N);

		for (int i = 0; i < N; i++)
			free(arr[i]);
		free(arr);
	}
	return 0;
}

bool rangeCheck(int num)
{
	if (MIN <= num && num <= MAX)
		return true;
	else
		return false;
}

bool repeat_circle(int num, int start_row, int start_column, int end_row, int end_column)
{
	if (start_column >= end_row) {
		if(start_row == end_row)  // 1개 남았을 떄~
			arr[start_row][start_column] = num;
		return true; // 꽉 채워서 끝날 떄~
	}
	else
	{
		int column = start_column;
		for (int i = start_row; i < end_row; i++)
		{
			if (i == start_row) {
				for (int j = start_column; j <= end_column; j++) {
					arr[i][j] = num;
					num += 1;
				}
			}
			else {
				arr[i][end_row] = num;
				num += 1;
			}
		}

		column = end_column;
		for (int i = end_row; i > start_row; i--)
		{
			if (i == end_row) {
				for (int j = end_column; j >= start_column; j--) {
					arr[i][j] = num;
					num += 1;
				}
			}
			else {
				arr[i][start_row] = num;
				num += 1;
			}
		}
		return repeat_circle(num, start_row + 1, start_column + 1, end_row - 1, end_column - 1);
	}
}

void print_arr(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

