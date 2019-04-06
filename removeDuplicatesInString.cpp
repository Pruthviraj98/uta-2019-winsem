#include<iostream>
#include<string.h>
using namespace std;



char* fun(char* s){
	int n=strlen(s);
	for(int i=0;i<n-1;i++){
		for(int k=0;k<n;k++){
			if(i==k){
				continue;
			}
			if(s[i]==s[k]){
				for(int j=k;j<n;j++){
				s[j]=s[j+1];
				}
			}
		}
	}
	if(s[n-1]==s[n-2]){
		s[n-2]=s[n-1];
	}
	return(s);
}


int main(){
	string s="aaaaaaaadddddababacdef";
	char* ss=&s[0];
	char* aa=fun(ss);
	cout<<aa;
}
