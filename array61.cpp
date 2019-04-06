#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int M;
		cin>>M;
		int x, y;
		cin>>x>>y;
		int Hno;
		int houses[101];
		houses[0]=1000;
		for(int i=1;i<101;i++){
			houses[i]=1;
		}
		for(int i=0;i<M;i++){
			cin>>Hno;			
			for(int j=Hno+1;j<=Hno+x*y;j++){
				houses[j]=0;
				if(Hno+j>100){
					break;
				}
			}
			for(int j=Hno;j>=x*y-Hno;j--){
				houses[Hno-j]=0;
				if(Hno-j<1){
					break;
				}
			}
		}
		int sum=0;
		for(int i=1;i<101;i++){
			sum+=houses[i];
		}
		cout<<sum<<"\n";
		
	}
}
