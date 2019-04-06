#include<bits/stdc++.h>
using namespace std;

int main(){
	int * numbers=new int[1000001];
	for(int i=0;i<=1000000;i++){
		numbers[i]=1;
	}
	numbers[0]=-1;
	numbers[1]=0;
	for(int i=2;i<=500000;i++){
		if(numbers[i]==1){
			for(int j=i*2;j<=1000000;j+=i){
				numbers[j]++;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(numbers[i]!=1){
			numbers[i]--;
		}
	}
	int T;
	cin>>T;
	while(T--){
		int a,b,n, ans=0;
		cin>>a>>b>>n;
		for(int i=a;i<=b;i++){
			if(numbers[i]==n){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	delete []numbers;
}
