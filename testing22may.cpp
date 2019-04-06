#include <iostream>
#include<string.h>
using namespace std;

char* keypad[10]={"", "", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};

int keyPadChar(int n, string output[]){
	
	int a[10000];
	int dummy=n;
	int counter=0;
	while (dummy>0){
		int temp=dummy%10;
		dummy=dummy/10;
		a[counter]=temp;
		counter++;
	}
	cout<<"\n\n";
	for(int i=0;i<counter;i++){
		cout<<a[i]<<"\t";
	}
	
	return(1);
}


int main(){
	int n;
	cin>>n;
	string output[1000];
	int x=keyPadChar(n, output);
	for(int i=0;i<x;i++){
		cout<<output[i]<<"\t";
	}
}

