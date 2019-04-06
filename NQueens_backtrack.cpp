#include<iostream>
#include<string.h>
using namespace std;

int board[11][11];//globAL MATRIX and can change whenerverneeded

bool isPossible(int n, int row, int col){
	
	
	//1. avoiding in column
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1){
			return false;
		}
	}
	
	//2. avoiding in upper left diagonal
	for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--){
		if(board[i][j]==1){
			return false;
		}
	}
	
	//3. upper right diagonal avoiding
	for(int i=row-1, j=col+1;i>=0 && j<=n;i--, j++){
		if(board[i][j]==1){
			return false;
		}
	}
	
	return true;
}



void nQueenHelper(int n, int row){
	if(row==n){
		//we have reached the solution
		//print the board matrix
		//return
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	
	//place at all the possible positions and move to smaller problem
	for(int j=0;j<n;j++){
		if(isPossible(n, row, j)){
			board[row][j]=1;
			nQueenHelper(n, row+1);
			board[row][j]=0;//while backtreacking, for the next solution this has to be zero
		}
	}
}

void placeNQueens(int n){
	memset(board, 0, 11*11*sizeof(int));
	
	nQueenHelper(n, 0);
}

int main(){
	int n;
	cin>>n;
	placeNQueens(n);
}
