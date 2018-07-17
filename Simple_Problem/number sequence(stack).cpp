
#include "stdafx.h"
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	int n, input,number;
	char output[200001];
	int output_len = 0;

	scanf("%d", &n);
	number = 1;
	bool possible_number = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);

		if (input == number) {
			// Push
			st.push(number++);
			output[output_len++] = '+';
			
			// Pop
			st.pop();
			output[output_len++] = '-';
		}
		else if (input > number) {
			while (input >= number) {
				// Push
				st.push(number++);
				output[output_len++] = '+';
			}

			// Pop
			st.pop();
			output[output_len++] = '-';
		}
		else if (input < number) {
			if (st.size() > 0 && st.top() == input) {
				// Pop
				st.pop();
				output[output_len++] = '-';
			}
			else {
				possible_number = false;
				break;
			}
		}
	}
	if (!possible_number)
		printf("NO\n");
	else {
		for (int i = 0; i < output_len; i++)
			printf("%c\n", output[i]);
	}

	return 0;
}


