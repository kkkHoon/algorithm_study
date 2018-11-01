#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int n;
long long dp[100];
long long fib(int n);

int main()
{
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}

long long fib(int n)
{
	if (n <= 2)
		return 1;

	if (dp[n] > 0)
		return dp[n];
	else {
		dp[n] = fib(n - 1) + fib(n - 2);
		return dp[n];
	}
}