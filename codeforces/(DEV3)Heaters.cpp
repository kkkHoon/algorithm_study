#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;
int map[1005];
int power[1005];
vector<int> off_v = vector<int>();
int off_v_size;
int n, r, heat_cnt = 0;

int main()
{
	bool cold_house = false;
	cin >> n >> r;
	for (int section = 1; section <= n; section++) {
		cin >> map[section];
		power[section] = 0;
	}

	for (int section = 1; section <= n; section++) {
		if (map[section] == 1) {
			for (int p = section - r + 1; p <= section + r - 1; p++) {
				if (p < 1 || p > n)
					continue;
				power[p] = section;
			}
		}
	}

	int pos = 1;
	while (pos <= n) {
		if (power[pos] == 0) {
			cold_house = true;
			break;
		}
		else {
			heat_cnt++;
			pos = power[pos] + r;
		}
	}
	if (cold_house)
		cout << -1 << endl;
	else
		cout << heat_cnt << endl;
	return 0;
}