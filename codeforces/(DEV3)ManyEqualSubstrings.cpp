#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
string s;

int main()
{
	cin >> n >> k;
	cin.get();
	cin >> s;
	vector<int> pi = vector<int>(n, 0);

	int i = 0;
	for (int j = 1; j < n; j++) {
		while (i > 0 && s[i] != s[j])
			i = pi[i - 1];
		if (s[i] == s[j])
			pi[j] = ++i;
	}

	int start = pi[n - 1];
	string suffix_s = s.substr(start);
	for (int cnt = 1; cnt <= k; cnt++) {
		if (cnt == 1)
			cout << s;
		else
			cout << suffix_s;
	}
	cout << endl;
	return 0;
}