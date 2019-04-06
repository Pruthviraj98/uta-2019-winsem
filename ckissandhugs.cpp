/*
All submissions for this problem are available.
Princess Artapoelc greeted her guests by either kissing on the cheek (K) or hugging (H). From the first guest she kisses, she has a compulsion to necessarily kiss every alternate guest from that first kissed guest. That is if the guests are G1, G2, ..., Gi, Gi+1, ..., Gn and if she first kissed Gi then she must necessarily kiss Gi+2, Gi+4, Gi+6 ... till the last possible guest. Your task is to determine in how many ways she can greet N guests.

Input

First line of the input contains T (T = 1000) denoting the number of test cases.

T lines follow each containing a single integer N (1 = N = 10^9) denoting the number of guests.


Output

For each case the output should be a single integer representing the number of ways Artapoelc can greet N guests. As the answer can be large print it MODulo 1000000007.
*/
#include<iostream>
#include<math.h>
#define MOD 1000000007
#define llt long long int
using namespace std;

llt exponent(llt base, int expo){
	if(!expo){
		return 1;
	}
	llt ans=exponent(base, expo/2);
	ans=(ans*ans)%MOD;
	
	if(expo%2){
		ans=(ans*base)%MOD;
	}return ans%MOD;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		llt n, expo1, expo2;
		cin>>n;
		
		expo1=ceil((n+1)/2.0);
		expo2=floor((n+1)/2.0);
		
		llt ans=exponent(2, expo1)+ exponent(2, expo2) -2;
		cout<<ans%MOD<<"\n";
	}
}
