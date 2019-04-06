/*Given a date and an array of integer containing the numbers of the cars traveling on that date(an integer), the task is to calculate the total fine collected based on the following rules:

Odd numbered cars can travel on only odd dates.
Even numbered cars on only even dates.
Otherwise a car would be fined 250 Rs.*/

#include<iostream>
#define llt long long int 

using namespace std;
int main(){
	llt t;
	cin>>t;
	while(t--){
		int date;
		llt n;
		cin>>n;
		llt car_num_even[n/2+1];
		llt car_num_odd[n/2+1];
		llt temp;
		llt l1=0;
		llt l2=0;
		for(llt i=0;i<n;i++){
			cin>>temp;
			if(temp%2==0){
				car_num_even[l1++]=temp;
			}else{
				car_num_odd[l2++]=temp;
			}
		}
		
		llt da;
		cin>>da;
		if(da%2==0){
			cout<<l2*250<<"\n";
		}else{
			cout<<l1*250<<"\n";
		}
	}
}
