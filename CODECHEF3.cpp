/*#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int t;
	cin>>t;
 	
	while(t!=0){
		int n;
		cin>>n;
		int A[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		
		
		int PersonsKnow=1;
		int index=0;
		int tempSum=0;
		int days=0;
		while(PersonsKnow<=n){
			
			for(int j=index;j<index+A[index];j++){
			tempSum+=A[index];
			cout<<tempSum<<"\n";
			}
			index=index+tempSum;
			tempSum=0;
			cout<<"\n";
			PersonsKnow+=index;
			days++;		
		}
		cout<<days;
t--;
	}
	
}*/
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
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		
		
		int PersonsKnow=1;
		int index=0;
		int tempSum=0;
		int days=0;
		while(PersonsKnow<=n){
			
			for(int j=index;j<index+A[index];j++){
			tempSum+=A[index];
		//	cout<<tempSum<<"\n";
			}
			index=index+tempSum;
			tempSum=0;
		//	cout<<"\n";
			PersonsKnow+=index;
			days++;		
		}
		cout<<days<<"\n";
t--;
	}
	
}
