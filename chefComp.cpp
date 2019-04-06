#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int t;
	cin>>t;
 	
	while(t!=0){
		int n;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		
		int sumn=1; //match the number n
		int day=0;
		int temp=0; //increment this to sumn
		int temp2 =0; //increment this at each iteration
		for(int i=0;i<n;i+=temp2){
			temp+=A[i];
			sumn+=temp;
			temp2=temp+1;
			if(sumn == n)
				break;
			day++;
		}
		t--;
		
		cout<<day;
	}
}
