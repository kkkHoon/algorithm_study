
#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int map[100][100][100];
int dist[100][100][100];
int dh[] = { 0, 0, 0, 0, -1, 1 };
int dr[] = { -1, 1, 0, 0, 0, 0 };
int dc[] = { 0, 0, -1, 1, 0, 0 };

int main()
{
	queue<pair<pair<int, int>, int>> q;
	int h, r, c;
	scanf("%d %d %d", &c, &r, &h);
	memset(dist, -1, sizeof(dist));

	// user input
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%d", &map[k][i][j]);

				if (map[k][i][j] == 1) {
					dist[k][i][j] = 0;
					q.push(make_pair(make_pair(k, i), j));
				}
			}
		}
	}

	// tomato gogogo
	while (!q.empty()) {
		int hh = q.front().first.first;
		int hr = q.front().first.second;
		int hc = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = hh + dh[i];
			int nr = hr + dr[i];
			int nc = hc + dc[i];

			if (nh < 0 || nh >= h || nr < 0 || nr >= r || nc < 0 || nc >= c) continue;

			if (map[hh][hr][hc] == 1) { // only tomato can move
				if (map[nh][nr][nc] == 0 && dist[nh][nr][nc] == -1) {
					dist[nh][nr][nc] = dist[hh][hr][hc] + 1;
					map[nh][nr][nc] = 1;
					q.push(make_pair(make_pair(nh, nr), nc));
				}
			}
		}
	}

	int max = -1;
	bool all_spread = true;
	for (int k = 0; (all_spread && k < h); k++) {
		for (int i = 0; (all_spread && i < r); i++) {
			for (int j = 0; j < c; j++) {
				if (map[k][i][j] == 0) {
					all_spread = false;
					break;
				}

				if (dist[k][i][j] > max) {
					max = dist[k][i][j];
				}
			}
		}
	}

	if (all_spread) printf("%d\n", max);
	else printf("-1\n");

	return 0;
}