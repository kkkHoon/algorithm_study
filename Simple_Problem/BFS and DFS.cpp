
#include "stdafx.h"
#include <cstdio>

#include <queue>
#include <stack>

int neigbor_matrix[1001][1001];
bool visited_list[1001];

using namespace std;

void initialize(int n);
void DFS(int V, int N);
void BFS(int V, int N);

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	int from, to;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &from, &to);
		neigbor_matrix[from][to] = 1;
		neigbor_matrix[to][from] = 1;
		// bidirectional line
	}

	DFS(V, N);
	BFS(V, N);

	return 0;
}

void initialize(int n)
{
	for (int i = 1; i <= n; i++)
		visited_list[i] = false;
}

void DFS(int V, int N)
{
	initialize(N);
	stack<int> st;
	int j;

	do {
		// The first visit
		if (visited_list[V] == false) {
			printf("%d ", V);
			visited_list[V] = true;
		}

		// find next node
		for (j = 1; j <= N; j++) {
			if (neigbor_matrix[V][j] == 1 && visited_list[j] == false) {
				break;
			}
		}

		// no way to down on graph
		if (st.size() > 0 && j == N + 1) {
			V = st.top();
			st.pop();
		}
		// any way to down on graph
		else if (j <= N) {
			st.push(V);
			V = j;
		}
	} while (st.empty() == false);
	printf("\n");
}

void BFS(int V, int N)
{
	initialize(N);
	queue<int> q;
	
	q.push(V);
	while (q.size() > 0) {
		V = q.front();
		q.pop();

		if (visited_list[V] == false) {
			printf("%d ", V);
			visited_list[V] = true;
		}

		for (int j = 1; j <= N; j++) {
			if (neigbor_matrix[V][j] == 1 && visited_list[j] == false)
				q.push(j);
		}
	}
	printf("\n");
}