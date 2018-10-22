#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1500001];
int T[1500001];
int P[1500001];
int n;

int dfs(int day);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(1) << endl;
	return 0;
}

int dfs(int day)
{
	if (day >= n + 1)
		return 0;

	if (dp[day] != -1)
		return dp[day];

	int daily_way = dfs(day + 1);
	int work_way = -1;
	if (day + T[day] <= n + 1) {
		work_way = P[day] + dfs(day + T[day]);
	}
	dp[day] = max(daily_way, work_way);
	return dp[day];
}