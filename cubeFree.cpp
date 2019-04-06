#include<bits/stdc++.h>
using namespace std;

int main(){
	int * numbers=new int[1000001];
	for(int i=0;i<=1000000;i++){
		numbers[i]=0;
	}
	numbers[0]=-1;
	for(int i=2;i<=100;i++){
		for(int j=i*i*i;j<=1000000;j+=i*i*i){
			numbers[j]=-1;
		}
	}
	
	int count=1;
	for(int i=1;i<1000000;i++){
		if(numbers[i]!=-1){
			numbers[i]=count;
			count++;
		}
	}
	
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		int ans=numbers[n];
		if(ans==-1){
			cout<<"Case "<<i+1<<": "<<"Not Cube Free"<<endl;
		}else{
			cout<<"Case "<<i+1<<": "<<numbers[n]<<endl;
		}
	}
}
