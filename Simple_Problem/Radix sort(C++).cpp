
#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;
const int base = 10;

int n;
vector<int> list;

int getMaxLength(int base);
void radix_sort(int i, int base);

int main()
{
	scanf("%d", &n);
	list = vector<int>(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	int iterator_max = getMaxLength(base);
	for (int i = 0; i < iterator_max; i++)
		radix_sort(i, base);
	
	for (int i = 0; i < n; i++)
		printf("%d\n", list[i]);
	list.clear();
	return 0;
}

void radix_sort(int i, int base)
{
	vector<vector<int>> Buckets = vector<vector<int>>(base);
	for (int k = 0; k < base; k++) {
		Buckets[k] = vector<int>();
	}

	if (!list.empty()) {
		for (int k = 0; k < n; k++) {
			int digit = int((list[k] / pow(base, i))) % base;
			Buckets[digit].push_back(list[k]);
		}
	}

	int count = 0;
	for (int k = 0; k < base; k++) {
		for (int t = 0; t < Buckets[k].size(); t++)
			list[count++] = Buckets[k][t];
	}

	for (int k = base - 1; k >= 0; k--) {
		Buckets[k].clear();
	}
	Buckets.clear();
}

int getMaxLength(int base)
{
	if (list.size() > 0) {
		int max = list[0];
		for (int i = 1; i < list.size(); i++) {
			if (list[i] > max)
				max = list[i];
		}

		int digit_length = 1;
		while (pow(base, digit_length) <= max)
			digit_length += 1;
		return digit_length;
	}
	return 0;
}