#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

int n, a, b;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}