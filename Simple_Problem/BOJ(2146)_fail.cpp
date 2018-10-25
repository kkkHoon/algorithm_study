#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> point;

int map[101][101];
int distance_map[101][101];
int visit[101][101];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0,0,-1,1 };

int n;
queue<point> q;

int bfs();
void dfs(int r, int c, int num);
bool chk(int r, int c);

int main()
{
	cin >> n;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> map[r][c];
		}
	}

	int island_num = 1;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (map[r][c] == 1 && visit[r][c] == 0) {
				dfs(r, c, island_num++);
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}

int bfs()
{
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int num = visit[r][c];
		int d = distance_map[r][c];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (chk(nr, nc)) continue;

			if (visit[nr][nc] == 0) {
				visit[nr][nc] = num;
				distance_map[nr][nc] = d + 1;
				q.push({ nr,nc });
			}
			else if (visit[nr][nc] != num) {
				return distance_map[r][c] + distance_map[nr][nc];
			}
		}
	}
	return 0;
}

bool chk(int r, int c)
{
	return (r < 0 || r >= n || c < 0 || c >= n);
}

void dfs(int r, int c, int num)
{
	visit[r][c] = num;
	q.push({ r,c });

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (chk(nr, nc)) continue;
		if (map[nr][nc] == 1 && visit[nr][nc] == 0)
			dfs(nr, nc, num);
	}
}