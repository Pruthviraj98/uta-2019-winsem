#include<iostream>
#include<string.h>
using namespace std;

bool issem(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }


	for(int i=1;i<n/2;n++){
		for(int j=1;j<i/2;j++){
			if(n%i*j==0){
				if(prime[i] ==true && prime[j]==true){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
    bool prime[200];
    memset(prime, false, sizeof(prime));
    
	for (int i=4;i<=200;i++){
		for(int j=2;j<i/2;j++){
			if(issem(i)==true && issem(i-j)==true && j!=i-j){
				prime[i]==true;
			}
		}
	}
	
	while(t!=0){
		int n;
		cin>>n;
		cout<<prime[n-1];
		t--;
	}
}
