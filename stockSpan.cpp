#include<iostream>
#include<vector>
using namespace std;

int findNos(int input[], int n, int ele){
	int counter=1;
	for(int i=0;i<n;i++){
		if(input[i]<ele){
			++counter;	
		}else{
			counter=1;
		}
	}
	return(counter);
}

int* stockSpan(int input[], int size){
  int counter=1;
  int x=0;
  static int output[100];
  for(int i=0;i<size;i++){
	output[x++]=findNos(input, i, input[i]);
	}
  return(output);
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int*arr=stockSpan(a, n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
