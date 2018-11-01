#include <iostream>

using namespace std;

void test();
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
		test();
	return 0;
}

void test()
{
	int L, v, l, r;
	int total_cnt, hidden_cnt;

	cin >> L >> v >> l >> r;
	total_cnt = L / v;
	if (l % v == 0)
		hidden_cnt = r / v - l / v + 1;
	else
		hidden_cnt = r / v - l / v;
	cout << total_cnt - hidden_cnt << endl;
}