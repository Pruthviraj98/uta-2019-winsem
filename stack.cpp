#include<bits/stdc++.h>
using namespace std;

stack <int> showStack(stack <int> &s){
	stack <int>ss;
	
	while(!s.empty()){
		int temp=s.top();
		s.pop();
		
		while(!ss.empty() && ss.top()>temp){
			s.push(ss.top());
			ss.pop();
		}
		
		ss.push(temp);
	}
	return ss;
}
int main(){
	stack <int> s;
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		s.push(temp);
	}
	stack<int> ss=showStack(s);
	
	while(!ss.empty()){
		cout<<ss.top()<<"\t";
		ss.pop();
	}
}/*
*/
