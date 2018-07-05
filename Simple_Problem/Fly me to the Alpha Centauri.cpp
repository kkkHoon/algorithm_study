
#include "stdafx.h"
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int test_case, x, y;
	long long moved_distance;
	scanf("%d", &test_case);

	for (int i = 1; i <= test_case; i++)
	{
		scanf("%d %d", &x, &y);
		int count = 1, k = 1;  // count == minimum moving cost , k == speed
		x += 1;
		moved_distance = 1;

		while (moved_distance + (k + 1) <= (y - x)) {  // speed up
			moved_distance += (k + 1);
			k += 1;
			x += k;
			count += 1;
		}

		while (x < y) {  // speed down
			if (moved_distance <= (y - x)) {
				x += k;
			}
			else {
				if (k != 1) {
					moved_distance -= k;
					k -= 1;
				}
				x += k;
			}
			count += 1;
		}
		printf("%d\n", count);
	}
	return 0;
}
