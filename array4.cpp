#include<iostream>
#include<stdlib.h>
#include<map>

#define ll long long int

using namespace std;
int main(){
ll t;
cin>>t;
while(t--){
	ll n;
	cin>>n;
	ll A[n];
	bool flag=false;	
	for(ll i=0;i<n;i++){
		cin>>A[i];
		if(i==0){
			continue;
		}
		if(A[i]>10){
			flag=true;
			continue;
		}
		if(A[i]>A[i-1] && (A[i]-A[i-1])>1){
			flag=true;
			continue;
		}		
		if(A[i]<A[i-1] && (A[i-1]-A[i])>1 && (A[n-i]-A[i])!=0){
			flag=true;
			continue;
		}
		if(A[i]==A[i-1]){
			if(n-i>0 && A[n-i]-A[i]!=0){
				flag=true;
			}
		}
	}
	if(flag==true){
		cout<<"no\n";
		flag=false;
	}else{
		cout<<"yes\n";
	}
}
}
