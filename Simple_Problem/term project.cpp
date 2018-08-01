
#include "stdafx.h"
#include <cstdio>
#include <queue>

using namespace std;
int input_list[100001];

void project_team();
void print_table(int n);

int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int i = 1; i <= test_case; i++)
		project_team();
	return 0;
}

void project_team()
{
	queue<int> q;
	int n, i, k, left_node, circle_size, cnt = 0;
	
	// user input
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &input_list[i]);

	left_node = n;
	for (i = 1; i <= n; i++) {
		//printf("before table(i = %d), cnt = %d \n", i, cnt);
		//print_table(n);

		// search the graph
		k = i; circle_size = 0;
		while (input_list[k] != -1 && circle_size <= left_node) {
			q.push(k);
			circle_size++;

			if (input_list[k] == k) {
				cnt += 1;
				break;
			}
			else if (input_list[k] == i) {
				cnt += circle_size;
				break;
			}
			else {
				k = input_list[k];
			}
		}

		if (circle_size > left_node) {
			input_list[i] = -1;
			left_node--;
			while (q.size() > 0) {
				q.pop();
			}
		}
		else {
			// delete searched node
			while (q.size() > 0) {
				k = q.front(); q.pop();
				input_list[k] = -1;
				left_node--;
			}
		}
		//printf("After table(i = %d), cnt = %d \n", i, cnt);
		//print_table(n);
	}
	printf("%d\n", n - cnt);
}

void print_table(int n)
{
	printf("|");
	for (int i = 1; i <= n; i++) {
		printf(" %d |", i);
	}
	printf("\n----------------\n");

	for (int i = 1; i <= n; i++) {
		printf(" %d ", input_list[i]);
	}
	printf("\n");
}