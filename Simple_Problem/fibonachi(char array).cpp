
#include "stdafx.h"
#include <cstdio>
#include <string.h>

using namespace std;
char fb[100][100];

void calculate_fb(int n);
bool check_fb(int first, int second);
int getLastIndex(int n);

int main()
{
	int n;
	scanf("%d", &n);

	if (n < 2)
		printf("%d\n", n);
	else {
		fb[0][0] = '0';
		fb[1][0] = '1';
		for (int i = 2; i <= n; i++) {
			calculate_fb(i);
		}

		int last = getLastIndex(n);
		for (int i = last; i >= 0; i--)
			printf("%c", fb[n][i]);
		printf("\n");
	}
	return 0;
}

void calculate_fb(int n)
{
	const int BASE = 10;
	int n_1, n_2, carrier = 0;

	int i = 0;
	while (check_fb(n - 1, i) && check_fb(n - 2, i)) {
		n_1 = fb[n - 1][i] - '0';
		n_2 = fb[n - 2][i] - '0';
		fb[n][i] = '0' + ((n_1 + n_2 + carrier) % BASE);
		carrier = (n_1 + n_2 + carrier) / BASE;
		i++;
	}

	if (check_fb(n - 1, i) == false && check_fb(n - 2, i) == false) {
		if (carrier > 0)
			fb[n][i] = '0' + carrier;
	}
	else if (check_fb(n - 1, i) == true && check_fb(n - 2, i) == false) {
		while (check_fb(n - 1, i)) {
			n_1 = fb[n - 1][i] - '0';
			fb[n][i] = '0' + ((n_1 + carrier) % BASE);
			carrier = (n_1 + carrier) / BASE;
			i++;
		}
	}
	else if (check_fb(n - 1, i) == false && check_fb(n - 2, i) == true) {
		while (check_fb(n - 2, i)) {
			n_2 = fb[n - 2][i] - '0';
			fb[n][i] = '0' + ((n_2 + carrier) % BASE);
			carrier = (n_2 + carrier) / BASE;
			i++;
		}
	}
}

bool check_fb(int first, int second)
{
	if (fb[first][second] >= '0' && fb[first][second] <= '9')
		return true;
	else
		return false;
}

int getLastIndex(int n)
{
	int i = 0;
	while (check_fb(n, i))
		i++;
	return i - 1;
}

