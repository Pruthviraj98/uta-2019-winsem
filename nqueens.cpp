/*
 * C++ Program to Solve N-Queen Problem
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 10
using namespace std;
 
 
/* check if a queen can be placed on board[row][col]*/
bool isSafe(int board[N][N], int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;
}
 
/*solve N Queen problem */
bool solveNQUtil(int board[N][N], int col, int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if ( isSafe(board, i, col, n) )
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, n) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
 
/* solves the N Queen problem using Backtracking.*/
void solveNQ(int n)
{
    int board[N][N] = {0};
    if (solveNQUtil(board, 0, n) == false)
    {
        return;
    }
	for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
      cout<<board[i][j]<<"\t";
      }
      cout<<"\n";
    }

}
 
// Main
int main()
{
	int n;
	cin>>n;
    solveNQ(n);
    return 0;
}
