#include<iostream>
#include<string.h>
using namespace std;
int subs(string input, string output[]){
	if(input.empty()){
		cout<<"\n  hi  \n";
		output[0]="";
		return 1;
	}
	string smallString=input.substr(1);
	int smallOutputSize=subs(smallString, output);
	for(int i=0;i<smallOutputSize;i++){
		output[i+smallOutputSize]=input[0]+output[i];	
	}
	return 2*smallOutputSize;
}


int main(){
	string input;
	cin>>input;
	int n=input.length();
	string* output=new string[1000];
	int count=subs(input, output);
	for(int i=0;i<count;i++){
	
		cout<<output[i]<<"\n";

	}
}
