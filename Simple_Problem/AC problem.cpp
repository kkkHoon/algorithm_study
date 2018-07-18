
#include "stdafx.h"
#include <cstdio>
#include <deque>
#include <string.h>
#include <string>


using namespace std;
void AC();
char function[100001];
char input_message[400001];

int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
		AC();
	return 0;
}

void AC()
{
	int n;
	deque<int> dq;
	int direction = 1;

	scanf("%s", &function);
	scanf("%d", &n); getchar();
	scanf("%s", &input_message);

	char *ptr = strtok(input_message, "[,]");
	while (ptr != NULL) {
		dq.push_back(atoi(ptr));
		ptr = strtok(NULL, "[,]");
	}

	int index = 0;
	while (function[index] != '\0') {
		if (function[index] == 'R')
			direction *= -1;
		else if (function[index] == 'D') {
			if (dq.size() > 0) {
				if (direction == 1)
					dq.pop_front();
				else if (direction == -1)
					dq.pop_back();
			}
			else {
				index = -1;
				break;
			}
		}
		index++;
	}

	if (index == -1)
		printf("error\n");
	else {
		printf("[");
		while (dq.size() > 1) {
			if (direction == 1) {
				printf("%d,", dq.front());
				dq.pop_front();
			}
			else if (direction == -1) {
				printf("%d,", dq.back());
				dq.pop_back();
			}
		}
		if (dq.size() == 1)
			printf("%d", dq.front());
		printf("]\n");
	}
}

