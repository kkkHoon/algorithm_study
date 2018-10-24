#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> point;

int map[101][101];
int time[101][101];
int air_map[101][101];
int max_row, max_col;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0,0,-1,1 };
int level;
queue<point> q;

bool chk(int r, int c);
void dfs(int r, int c);
int main()
{
	cin >> max_row >> max_col;
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			cin >> map[i][j];
		}
	}

	level = 0;
	dfs(0, 0);
	level = 1;
	while (!q.empty()) {
		int tc = q.size();
		while (tc--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			map[r][c] = 0;   // map[r][c] =   1(cheese) -> 0(air)
			dfs(r, c);
		}
		level++;
	}
	level = level - 1;

	int cnt = 0;
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if (time[i][j] == level)
				cnt++;
		}
	}
	cout << level << endl;
	cout << cnt << endl;

	//for (int i = 0; i < max_row; i++) {
	//	for (int j = 0; j < max_col; j++) {
	//		cout << time[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	return 0;
}

bool chk(int r, int c)
{
	return (r < 0 || r >= max_row || c < 0 || c >= max_col);
}

void dfs(int r, int c)
{
	air_map[r][c] = 1;
	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		if (chk(nr, nc)) continue;

		if (map[nr][nc] == 0 && air_map[nr][nc] == 0)
			dfs(nr, nc);
		else if (map[nr][nc] == 1 && time[nr][nc] == 0) {
			q.push({ nr,nc });
			time[nr][nc] = level + 1;
		}
	}
}