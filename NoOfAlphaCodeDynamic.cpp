#include<iostream>
using namespace std;

int num_codes(int*n, int size){
	if(size==1){
		return 1;
	}
	if(size==0){
		return 1;
	}
	int output=num_codes(n, size-1);
	if(arr[size-2]*10+arr[size-1]<=26){
		output+=num_codes(n, size-2);
	}
	return output;
}

int main(){
	int n;
	cin>>n;
	int* arr= new int(n);
	cout<<num_codes(n, arr);
}
