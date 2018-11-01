#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int n;
int dp[1005];
int func(int n);

int main()
{
	cin >> n;
	cout << func(n) << endl;
	return 0;
}

int func(int n)
{
	if (n <= 2)
		return n;
	if (dp[n] > 0)
		return dp[n];

	dp[n] = (func(n - 1) + func(n - 2)) % 10007;
	return dp[n];
}