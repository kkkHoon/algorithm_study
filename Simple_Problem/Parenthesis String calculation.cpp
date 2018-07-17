
#include "stdafx.h"
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
void check_PS(const char *PS);
int get_vectorSum(int index);

vector<vector<int>> depth_operand = vector<vector<int>>(17);

int main()
{
	char PS[51];
	scanf("%s", &PS);

	check_PS(PS);

	return 0;
}

void check_PS(const char *PS)
{
	stack<char> st;
	bool VPS_check = true;
	int k = 0, depth = 0;
	while (PS[k] != '\0') {
		if (PS[k] == '(' || PS[k] == '[') {
			(PS[k] == '(') ? st.push(')') : st.push(']');
		}
		else if (PS[k] == ')' || PS[k] == ']') {
			if (st.empty() || st.top() != PS[k]) {   // empty check before pop(). there is no more number to pop. It is not valid PS.
				VPS_check = false;
				break;
			}
			else {
				depth = st.size();
				if (PS[k] == ')')
					depth_operand[depth].push_back(get_vectorSum(depth + 1) * 2);
				else if (PS[k] == ']')
					depth_operand[depth].push_back(get_vectorSum(depth + 1) * 3);
				st.pop();
			}
		}
		k++;
	}

	if (VPS_check == true && st.empty())
		printf("%d\n", get_vectorSum(1));
	else
		printf("0\n");
}

int get_vectorSum(int index)
{
	if (depth_operand[index].size() == 0)
		return 1;
	else {
		int sum = 0, last = depth_operand[index].size() - 1;
		for (int i = last; i >= 0; i--) {
			sum += depth_operand[index][i];
			depth_operand[index].pop_back();
		}
		return sum;
	}
}

