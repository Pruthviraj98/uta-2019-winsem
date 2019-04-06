#include<iostream>
using namespace std;

int findlast(int input[], int size, int x, int output[]){
int ele=0;
for(int i=0;i<size;i++){
  if(input[i]==x){
    output[ele++]=size-1;
  }
}
  return(ele);
}


int main(){
	int n, ele, out[100];
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>ele;
	cout<<findlast(a, n, ele, out);
}
