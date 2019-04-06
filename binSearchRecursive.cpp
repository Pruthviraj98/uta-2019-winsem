#include<iostream>
using namespace std;

int binary(int input[], int l, int rt, int ele){
	if(rt>=l){
		int mid=(l+rt)/2;
	if(input[mid]==ele){	
		return(mid+1);
	}
	if(ele>input[mid]){
		l=mid+1;
	}else{
		rt=mid-1;
	}
	int pos=binary(input, l, rt, ele);
	}
	return -1;
	
}

int binarySearch(int input[], int size, int element){
	int pos=binary(input, 0, size-1, element);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ele;
	cin>>ele;
	cout<<binarySearch(a, n-1, ele);
}
