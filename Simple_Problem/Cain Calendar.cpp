
#include "stdafx.h"
#include <cstdio>

using namespace std;

int main()
{
	int test_case, M, N, X, Y, Z, k1, k2;

	scanf("%d", &test_case);
	for (int i = 1; i <= test_case; i++)
	{
		scanf("%d %d %d %d", &M, &N, &X, &Y);

		//find max_Z
		int max_Z = 0;
		k1 = 1, k2 = 1;
		while (M * k1 != N * k2) {
			if (M * k1 < N * k2)
				k1 += 1;
			else
				k2 += 1;
		}
		max_Z = M * k1;

		//find Z
		k1 = 0, k2 = 0;
		int temp_z1, temp_z2;
		while (1) {
			temp_z1 = M * k1 + X;
			temp_z2 = N * k2 + Y;

			if (temp_z1 == temp_z2) {
				printf("%d\n", temp_z1);
				break;
			}
			else if (temp_z1 > temp_z2) {
				if (temp_z1 > max_Z) {
					printf("-1\n");
					break;
				}
				k2 += 1;
			}
			else {
				if (temp_z2 > max_Z) {
					printf("-1\n");
					break;
				}
				k1 += 1;
			}
		}
	}
	return 0;
}
