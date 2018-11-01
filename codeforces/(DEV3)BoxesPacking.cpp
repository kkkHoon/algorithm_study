#include <iostream>
#include <stack>

using namespace std;

int n, m, k;
stack<int> s;

int main()
{
	int temp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.push(temp);
	}

	int cnt = 1, sum = 0;
	while (!s.empty()) {
		sum += s.top();
		if (sum > k) {
			cnt++;
			sum = 0;
		}
		else
			s.pop();

		if (cnt > m)
			break;
	}

	if (!s.empty())
		cout << n - s.size() << endl;
	else
		cout << n << endl;
	return 0;
}