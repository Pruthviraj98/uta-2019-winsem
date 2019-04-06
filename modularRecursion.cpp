#include<iostream>
using namespace std;

int modu(int a, int b, int c){
	if(b==0){
		return(1);
	}
	if(b%2==0){
		return(modu((a*a)%c, b/2, c));
	}else{
		return(((a%c)*modu(((a*a)%c), b/2, c))%c);
	}
}

int main(){
	int a, b, mod;
	cin>>a>>b>>mod;
	cout<<endl<<modu(a,  b, mod);
}
