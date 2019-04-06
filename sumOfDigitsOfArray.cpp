#include<iostream>
using namespace std;

int sum(int input[], int n){
	if(n==0){
		return 0;
	}
	
	return (input[0]+sum(input+1, n-1));
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<sum(a, n);
}
