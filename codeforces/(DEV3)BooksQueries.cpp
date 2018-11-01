#include <iostream>
#define origin 20000

using namespace std;

int shelf[400005];
int idx_to_index[200005];

int main()
{
	bool first_time = true;
	int n, idx, L = origin, R = origin;
	char temp;

	cin >> n; cin.get();
	for (int i = 0; i < n; i++) {
		cin >> temp >> idx;
		cin.get();

		if (first_time) {
			idx_to_index[idx] = L; // or R
			first_time = false;
		}
		else {
			if (temp == 'L')
				idx_to_index[idx] = --L;
			else if (temp == 'R')
				idx_to_index[idx] = ++R;
			else if (temp == '?') {
				int L_dist, R_dist;
				L_dist = idx_to_index[idx] - L;
				R_dist = R - idx_to_index[idx];
				if (L_dist <= R_dist)
					cout << L_dist << endl;
				else
					cout << R_dist << endl;
			}
		}
	}
	return 0;
}