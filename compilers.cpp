/*
Today, Lira is concerned with an abstract instruction which is composed of the characters "<" and ">" , which she will use on the design of her language, L++ :D.

She is using it as an abstraction for generating XML code Tags in an easier fashion and she understood that, for an expression to be valid, a "<" symbol must always have a corresponding ">" character somewhere (not necessary immediately) after it. Moreover, each ">" symbol should correspond to exactly one "<" symbol.

So, for instance, the instructions:

<<>>

<>

<><>

are all valid. While:

>>

><><

are not.

Given some expressions which represent some instructions to be analyzed by Lira's compiler, you should tell the length of the longest prefix of each of these expressions that is valid, or 0 if there's no such a prefix.

Input
Input will consist of an integer T denoting the number of test cases to follow.

Then, T strings follow, each on a single line, representing a possible expression in L++.

Output
For each expression you should output the length of the longest prefix that is valid or 0 if there's no such a prefix.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
//#include <stdlib.h>
using namespace std;

long long int compile(string input){
	long long int n=input.length();
	long long int ret=0;
	
	stack<char> s;
	
	for(long long int i=0;i<n;i++){
		if(s.size()==0 && input[i]=='<'){
			s.push(input[i]);
		}else if(s.top()=='<' && input[i]=='>'){
			ret++;
			s.pop();
		}else if(s.size()==0 && input[i]=='>'){
			return ret;
		}else{
			s.push(input[i]);
		}
		cout<<i<<"\t";
	}
	
	return ret;
}

int main(){
	int t;
	cin>>t;
	string temp;
	while(t--){
		cin>>temp;
		long long int ans=compile(temp);
		cout<<ans*2<<"\n";
	}
}
