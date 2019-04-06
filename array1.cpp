#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	long long int t, c, n;
	cin>>t;
	while(t--){
		cin>>n>>c;
		long long int sum=0;
		for(long long int i=0;i<n;i++){
			long long int temp;
			cin>>temp;
			sum+=temp;
		}
		if(sum<=c){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
	}
}
