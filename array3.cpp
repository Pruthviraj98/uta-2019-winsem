#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int N;
		cin>>N;
		long long int A[N];
		cin>>A[0];
		long long int smallest=A[0];
		long long int sum=A[0];
		for(long long int i=1;i<N;i++){
			cin>>A[i];
			if(A[i]<smallest){
				smallest=A[i];
			}
			sum+=A[i];
		}
		cout<<sum-N*smallest<<"\n";
	}
}
