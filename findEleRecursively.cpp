#include<iostream>
using namespace std;

bool find(int input[], int size, int x){
	if(size<0){
		return false;
	}
	
	if(input[0]==x){
		return true;	
	}
	
	bool isTrue=find(input+1, size-1, x);
	return isTrue; 
}


int findfirst(int input[], int size, int x){
	if(size<0){
		return false;
	}
	
	if(input[0]==x){
		return size-1;	
	}
	
	int isTrue=findfirst(input+1, size-1, x)-1;
	return isTrue; 
}


int main(){
	int n, ele;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>ele;
	if(find(a, n, ele)){
		cout<<"found";
		cout<<findfirst(a, n, ele);
	}else{
		cout<<"not found";
	}
	
}
