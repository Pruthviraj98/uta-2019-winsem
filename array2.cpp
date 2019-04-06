#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;
int main(){
	
	long long int t;

	cin>>t;
	while(t--){
		bool flag=false;
		long long int X, C, P, Y, K, N;
		cin>>X>>Y>>K>>N;
		for(long long int i=0;i<N;i++){
			cin>>P>>C;
			if(P>=(X-Y) && C<=K){
				flag=true;
			}
		}
		if(flag==true){
			cout<<"LuckyChef\n";
		}else{
			cout<<"UnluckyChef\n";
		}
		flag=false;
	}	
}
