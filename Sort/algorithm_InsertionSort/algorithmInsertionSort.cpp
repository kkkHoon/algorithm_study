// algorithmInsertionSort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

bool insertion_sort(int *input_seq, int size);
int getInteger();
using namespace std;

int main()
{
	int *input_list;
	int input_size;

	cout << "Please type input list size" << endl;
	input_size = getInteger();
	input_list = (int *)malloc(sizeof(int) * input_size);

	for (int k = 0; k < input_size; k++) {
		cout << "Please type " << k << "'s integer value" << endl;
		input_list[k] = getInteger();
	}
	insertion_sort(input_list, input_size);
	
	if (input_list != NULL) {
		for (int k = 0; k < input_size; k++) {
			cout << "Output_list[" << k << "] :: " << input_list[k] << endl;
		}
	}
	else {
		cout << "Unexpected Error!" << endl;
	}

	free(input_list);
	return 0;
}

bool insertion_sort(int *input_seq, int size) {
	int r;

	if (input_seq == NULL)
		return false;
	else if (size == 1)
		return true;
	else {
		for(int j=1; j<size; j++){
			int key = input_seq[j];

			if (key > input_seq[j - 1])		// if key is on the right position
				continue;
			else {
				for (r = j - 1; r >= 0; r--) {	// move bigger number than key to forward
					if (input_seq[r] >= key)	
						input_seq[r + 1] = input_seq[r];
					else 
						break;
				}
				input_seq[r + 1] = key;
			}
		}
		return true;
	}
}

int getInteger() {
	int i;
	while (true) {
		cin >> i;
		if (cin.fail()) {
			cout << "It is not an integer... retype" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		break;
	}
	return i;
}
