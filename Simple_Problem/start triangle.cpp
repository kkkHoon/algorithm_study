
#include "stdafx.h"
#include <cstdio>
#include <stdlib.h>
#include <cstring>

using namespace std;
int max_height, max_column;
char **M;

void draw_triange(int height, int row, int col);

int main()
{
	int H;
	scanf("%d", &H);
	max_height = H;
	max_column = H * 2;

	M = new char*[max_height];
	for (int r = 0; r < max_height; r++) {
		M[r] = new char[max_column];
		memset(M[r], ' ', sizeof(char) * max_column);
	}
	draw_triange(H, 0, H - 1);

	for (int r = 0; r < max_height; r++) {
		for (int c = 0; c < max_column; c++)
			printf("%c", M[r][c]);
		printf("\n");
	}


	for (int r = 0; r < max_height; r++)
		delete[] M[r];
	delete[] M;

	return 0;
}

void draw_triange(int height, int row, int col)
{
	if (height == 3 && row >= 0 && row + 2 < max_height && col - 2 >= 0 && col + 2 < max_column) {
		M[row][col] = '*';
		
		M[row + 1][col - 1] = '*';
		M[row + 1][col + 1] = '*';

		M[row + 2][col - 2] = '*';
		M[row + 2][col - 1] = '*';
		M[row + 2][col] = '*';
		M[row + 2][col + 1] = '*';
		M[row + 2][col + 2] = '*';
	}
	else if (height > 3){
		int width = height;
		int leftDot_row, leftDot_col;
		int rightDot_row, rightDot_col;

		leftDot_row = row + height / 2;
		leftDot_col = col - (width / 2);

		rightDot_row = row + height / 2;
		rightDot_col = col + (width / 2);

		if (leftDot_row >= 0 && leftDot_row < max_height)
			draw_triange(height / 2, leftDot_row, leftDot_col);
		if (rightDot_row >= 0 && rightDot_row <= max_height)
			draw_triange(height / 2, rightDot_row, rightDot_col);
		draw_triange(height / 2, row, col);
	}
}