#include<bits/stdc++.h>
using namespace std;


int main(){
//	cout<<"hi";
int * arr=new int[1000001];

memset(arr, 1, sizeof(arr));

for(int i=0;i<500000;i++){
	if(arr[i]==1){
	for(int j=i;j<100000;j+=j*i){
		arr[j]=-1;	
	}
	}
}

int t;
cin>>t;
  while (t>0){    
    int a, b, n;
    cin>>a>>b>>n;
	int counter=0;
	for(int i=0;i<100000;i++){
		if(arr[i]=n){
			counter++;
		}
	}
	cout<<counter<<endl;
	t--;
  }
	// Write your code here
}
