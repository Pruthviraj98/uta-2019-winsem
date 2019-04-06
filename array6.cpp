#include<iostream>
#include<string.h>
using namespace std;

bool check(int A[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=A[i];
	}
	if(sum==0){
		return true;
	}else{
		return false;
	}
}

void fillHouse(int x, int n, int house[]){
	
	int fur=n;
	int bck=n;
	int indi=x+1;
	int indb=x;
	while(fur>=0){
		house[indi++]=0;
		if(indi>=100){
			break;
		}
		fur--;
	}
	while(bck>0){
		house[indb--]=0;
		if(indb<0){
			break;
		}
		bck--;
	}
	return;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int M;
		cin>>M;
		int x, y;
		cin>>x>>y;
		int A[M];
		int house[100];
	
		for(int i=0;i<100;i++){
			house[i]=1;
		}
		int temp;
		for(int i=0;i<M;i++){
			cin>>temp;
			A[i]=temp-1;
			house[A[i]]=0;
		}
		bool flag=false;
		int totH=x*y;
		for(int i=0;i<M;i++){
			fillHouse(A[i], x*y, house);
			if(check(house, 100)==true){
				flag=true;
				break;
			}
		}
		if(flag==true){
			cout<<0<<"\n";
		}else{
			int sum=0;
			for(int i=0;i<100;i++){
					cout<<house[i]<<"\t";
				if(house[i]==1){
					sum++;
				}
			}
			cout<<"\n";
			cout<<sum<<"\n";
		}
	}	
}
