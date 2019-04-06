#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<string.h>
#include<cstring>
using namespace std;


int output[63000][50];
int subsets2(int input[], int size, int index){
	if(index==size){
		output[0][0]=0;
		return 1;
	}
	

	int smallSize=subsets2(input, size, index+1);
	
	for(int i=0;i<smallSize;i++){
		output[i+smallSize][0]=output[i][0]+1;
		output[i+smallSize][1]=input[index];
		for(int j=1;j<=output[i][0];j++){
			output[i+smallSize][j+1]=output[i][j];
		}
	}	
	return 2*smallSize;
}
int subsets(int input[], int size, int index, int output2[][20], int k){
int x= subsets2(input, size, index);
int	kc=x;
	for(int j=0;j<x;j++){
	int sum=0;	
	 	for(int k=1;k<size+1;k++){
	 		if(output[j][k]==0){
	 			continue;
			 }
			 sum=sum+output[j][k];
//	 		cout<<output[j][k]<<"\t";
		 }
		 
	
	if(sum==k){
		for(int k=1;k<size+1;k++){
	 		if(output[j][k]==0){
	 			continue;
			 }
			 output2[j][k]=output[j][k];
		 	}		 	
		}else{
			kc--;
		}
}
return(kc);
}

int main(){
 	int n;
 	cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	 }
	int kk;
	cin>>kk; 
	
	 int output3[10000][20];
	 int x= subsets(a, n, 0, output3, kk);
	 for(int j=0;j<x;j++){
	 	for(int k=0;k<n+1;k++){
	 		cout<<output3[j][k]<<"\t";
		 }cout<<"\n";
	 }
}
