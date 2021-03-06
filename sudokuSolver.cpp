#include<iostream>
using namespace std;

 
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0 
#define N 9
 
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);
bool sudokuSolver(int grid[][9])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (sudokuSolver(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}
 
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}
 
int main(){
	int sudokuMatrix[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>sudokuMatrix[i][j];
		}
	}
	cout<<sudokuSolver(sudokuMatrix);
}
