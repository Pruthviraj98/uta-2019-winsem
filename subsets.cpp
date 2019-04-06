#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<string.h>
#include<cstring>
using namespace std;

int output[1000][20];

int subsets(int input[], int size, int index){
	if(index==size){
		output[0][0]=0;
		return 1;
	}
	

	int smallSize=subsets(input, size, index+1);
	
	for(int i=0;i<smallSize;i++){
		output[i+smallSize][0]=output[i][0]+1;
		output[i+smallSize][1]=input[index];
		for(int j=1;j<=output[i][0];j++){
			output[i+smallSize][j+1]=output[i][j];
		}
	}	
	return 2*smallSize;
}

int main(){
 	int n;
 	cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	 }
	 int x= subsets(a, n, 0);
	 for(int j=0;j<x;j++){
	 	for(int k=1;k<n+1;k++){
	 		if(output[j][k]==0){
	 			continue;
			 }
	 		cout<<output[j][k]<<"\t";
		 }cout<<"\n";
	 }
}
