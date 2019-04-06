/*
Minimum number of Appends needed to make a string palindrome
Given a string s we need to tell minimum characters to be appended (insertion at end) to make a string palindrome.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool flag=false;
		int buf=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=s[s.length()-i-1]){
//				cout<<s[i]<<"!="<<s[s.length()-i-1]<<"\n";
				flag=true;
				buf++;
			}
		}
		if(flag==false){
			cout<<0<<"\n";
			continue;
		}
		if(s.length()%2==0){
			cout<<buf<<"\n";			
			continue;
		}
		cout<<buf+1<<"\n";						
	}
}
