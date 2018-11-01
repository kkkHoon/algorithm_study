#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int n, num, cnt;
void calculate(int num);
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt = 0;
		calculate(num);
		cout << cnt << endl;
	}
	return 0;
}

void calculate(int num)
{
	if (num <= 0) {
		if (num == 0)
			cnt++;
		return;
	}

	calculate(num - 1);
	calculate(num - 2);
	calculate(num - 3);
}