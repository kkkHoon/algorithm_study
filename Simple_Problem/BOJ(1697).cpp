#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

int n, k;
int visit[100001];
queue<pair<int, int>> q;

int main()
{
	cin >> n >> k;
	memset(visit, -1, sizeof(visit));

	q.push({ n,0 });
	visit[n] = 0;
	while (!q.empty()) {
		int pos = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (pos + 1 <= 100000) {
			if (visit[pos + 1] == -1 || visit[pos + 1] > cost + 1) {
				visit[pos + 1] = cost + 1;
				q.push({ pos + 1, visit[pos + 1] });
			}
		}
		if (pos - 1 >= 0) {
			if (visit[pos - 1] == -1 || visit[pos - 1] > cost + 1) {
				visit[pos - 1] = cost + 1;
				q.push({ pos - 1, visit[pos - 1] });
			}
		}
		if (pos * 2 <= 100000) {
			if (visit[pos * 2] == -1 || visit[pos * 2] > cost + 1) {
				visit[pos * 2] = cost + 1;
				q.push({ pos * 2, visit[pos * 2] });
			}
		}
	}
	cout << visit[k] << endl;
	return 0;
}