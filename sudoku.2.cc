#include <iostream>
#define N 9
using namespace std;
bool findEmptySlot(int grid[N][N], int &row, int &col) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 0) {
				row = i, col = j;
				return true;
			}
		}
	}
	return false;
}

bool isValid(int grid[N][N], int row, int col, int num) {
	for (int i = 0; i < N; i++) {
		if (grid[row][i] == num) return false;	// row check
		if (grid[i][col] == num) return false;	// col check
		if (grid[row - row%3 + i/3][col - col%3 + i%3] == num) return false;	// box check
	}
	return true;
}

bool SolveSuduku(int grid[N][N], int pos) {
	int row, col, num;

	// base case, 80 guarantee solved
	if (pos >= 81)
		return true;
	row = pos / 9, col = pos % 9;
	if (grid[row][col] != 0)
		return SolveSuduku(grid, pos+1);
	for (num = 1; num <= N; num++) {
		printf("(%d, %d) = %d\n", row, col, num);
		if (isValid(grid, row, col, num) == true) {
			grid[row][col] = num;
			if (SolveSuduku(grid, pos+1) == true)
				return true;
			grid[row][col] = 0; // leave unassigned
		}
	}
	return false; // trigger backtrace
}

void printGrid(int grid[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	// 0 means unassigned cells
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
		 	  {5, 2, 0, 0, 0, 0, 0, 0, 0},
			  {0, 8, 7, 0, 0, 0, 0, 3, 1},
			  {0, 0, 3, 0, 1, 0, 0, 8, 0},
			  {9, 0, 0, 8, 6, 3, 0, 0, 5},
			  {0, 5, 0, 0, 9, 0, 6, 0, 0},
			  {1, 3, 0, 0, 0, 0, 2, 5, 0},
			  {0, 0, 0, 0, 0, 0, 0, 7, 4},
			  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	if (SolveSuduku(grid, 0) == true)
		printGrid(grid);
	else
		printf("No solution exists\n");
 
	return 0;
}
