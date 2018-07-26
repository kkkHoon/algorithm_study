
#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
int n;
vector<vector<int>> adj_list;
int visisted_parent[100001];

void bfs(int i);

int main()
{
	int u, v;
	scanf("%d", &n);
	adj_list = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	
	bfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", visisted_parent[i]);
	}
	return 0;
}

void bfs(int i)
{
	int x, y;
	queue<pair<int, int>> q;
	pair<int, int> temp = pair<int, int>(i, -1);

	q.push(temp);
	while (q.size() > 0) {
		temp = q.front();
		q.pop();
		x = temp.first;
		y = temp.second;

		visisted_parent[x] = y;
		for (int i = 0; i < adj_list[x].size(); i++) {
			int next = adj_list[x][i];
			if (visisted_parent[next] == 0) {
				temp = pair<int, int>(next, x);
				q.push(temp);
			}
		}
	}
}