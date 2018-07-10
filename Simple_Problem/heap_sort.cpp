
#include "stdafx.h"
#include <cstdio>
#include <vector>

using namespace std;

void swap(int index1, int index2);
void insert_minHeap(int i, int num);
int remove_minHeap(int max);

vector<int> list;

int main()
{
	int max_n, current_n, num;

	scanf("%d", &max_n);
	list = vector<int>(max_n + 1);

	// Insert numbers into min heap
	for (int i = 1; i <= max_n; i++) {
		scanf("%d", &num);
		insert_minHeap(i, num);
	}
	

	// Remove number from min heap
	current_n = max_n;
	for (current_n; current_n >= 1; current_n--) {
		num = remove_minHeap(current_n);
		printf("%d\n", num);
	}

	list.clear();
	return 0;
}

int remove_minHeap(int max)
{
	int minimum_number = list[1];
	list[1] = list[max];
	
	int p = 1;
	while (p * 2 + 1 <= max)
	{
		if (list[p * 2] < list[p * 2 + 1]) {
			if (list[p] > list[p * 2])
			{
				swap(p, p * 2);
				p = p * 2;
			}
			else
				break;
		}
		else {
			if (list[p] > list[p * 2 + 1])
			{
				swap(p, p * 2 + 1);
				p = p * 2 + 1;
			}
			else
				break;
		}
	}
	return minimum_number;
}

void insert_minHeap(int i, int num)
{
	list[i] = num;
	for (int k = i; k > 1; k = k / 2)
	{
		int parent_num = list[k / 2];
		if (parent_num > num) // To protect min heap property
			swap(k, k / 2);
		else
			break;
	}
}

void swap(int index1, int index2)
{
	int temp = list[index1];
	list[index1] = list[index2];
	list[index2] = temp;
}
